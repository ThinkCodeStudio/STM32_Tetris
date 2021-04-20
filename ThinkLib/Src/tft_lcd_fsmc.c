#include "tft_lcd_fsmc.h"

//LCD�Ļ�����ɫ�ͱ���ɫ	   
uint16_t POINT_COLOR=0x0000;	//������ɫ
uint16_t BACK_COLOR=0xFFFF;  //����ɫ 
  
//����LCD��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;
	 
//д�Ĵ�������
//regval:�Ĵ���ֵ
void LCD_WR_REG(uint16_t regval)
{   
	LCD->LCD_REG=regval;//д��Ҫд�ļĴ������	 
}
//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(uint16_t data)
{	 
	LCD->LCD_RAM=data;		 
}
//��LCD����
//����ֵ:������ֵ
uint16_t LCD_RD_DATA(void)
{
	volatile uint16_t ram;			//��ֹ���Ż�
	ram=LCD->LCD_RAM;	
	return ram;	 
}					   
//д�Ĵ���
//LCD_Reg:�Ĵ�����ַ
//LCD_RegValue:Ҫд�������
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue)
{	
	LCD->LCD_REG = LCD_Reg;		//д��Ҫд�ļĴ������	 
	LCD->LCD_RAM = LCD_RegValue;//д������	    		 
}	   
//���Ĵ���
//LCD_Reg:�Ĵ�����ַ
//����ֵ:����������
uint16_t LCD_ReadReg(uint16_t LCD_Reg)
{										   
	LCD_WR_REG(LCD_Reg);		//д��Ҫ���ļĴ������
	//��5us�ӳ�		  
	return LCD_RD_DATA();		//���ض�����ֵ
}  

//��ʼдGRAM
void LCD_WriteRAM_Prepare(void)
{
 	LCD->LCD_REG=lcddev.wramcmd;	  
}	 
//LCDдGRAM
//RGB_Code:��ɫֵ
void LCD_WriteRAM(uint16_t RGB_Code)
{							    
	LCD->LCD_RAM = RGB_Code;//дʮ��λGRAM
}

//��ILI93xx����������ΪGBR��ʽ��������д���ʱ��ΪRGB��ʽ��
//ͨ���ú���ת��
//c:GBR��ʽ����ɫֵ
//����ֵ��RGB��ʽ����ɫֵ
uint16_t LCD_BGR2RGB(uint16_t c)
{
	uint16_t  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 
//��mdk -O1ʱ���Ż�ʱ��Ҫ����
//��ʱi
void opt_delay(uint8_t i)
{
	while(i--);
}

uint16_t LCD_GetID(void)
{
	lcddev.id=LCD_ReadReg(0x0000);	//��ID��9320/9325/9328/4531/4535��IC��   
  if(lcddev.id<0XFF||lcddev.id==0XFFFF||lcddev.id==0X9300)//����ID����ȷ,����lcddev.id==0X9300�жϣ���Ϊ9341��δ����λ������»ᱻ����9300
	{	
		//����9341 ID�Ķ�ȡ		
		LCD_WR_REG(0XD3);				   
		lcddev.id=LCD_RD_DATA();	//dummy read 	
 		lcddev.id=LCD_RD_DATA();	//����0X00
  		lcddev.id=LCD_RD_DATA();   	//��ȡ93								   
 		lcddev.id<<=8;
		lcddev.id|=LCD_RD_DATA();  	//��ȡ41 	   			   
 		if(lcddev.id!=0X9341)		//��9341,�����ǲ���6804
		{	
 			LCD_WR_REG(0XBF);				   
			lcddev.id=LCD_RD_DATA(); 	//dummy read 	 
	 		lcddev.id=LCD_RD_DATA();   	//����0X01			   
	 		lcddev.id=LCD_RD_DATA(); 	//����0XD0 			  	
	  		lcddev.id=LCD_RD_DATA();	//�������0X68 
			lcddev.id<<=8;
	  		lcddev.id|=LCD_RD_DATA();	//�������0X04	  
			if(lcddev.id!=0X6804)		//Ҳ����6804,���Կ����ǲ���NT35310
			{ 
				LCD_WR_REG(0XD4);				   
				lcddev.id=LCD_RD_DATA();//dummy read  
				lcddev.id=LCD_RD_DATA();//����0X01	 
				lcddev.id=LCD_RD_DATA();//����0X53	
				lcddev.id<<=8;	 
				lcddev.id|=LCD_RD_DATA();	//�������0X10	 
				if(lcddev.id!=0X5310)		//Ҳ����NT35310,���Կ����ǲ���NT35510
				{
					LCD_WR_REG(0XDA00);	
					lcddev.id=LCD_RD_DATA();		//����0X00	 
					LCD_WR_REG(0XDB00);	
					lcddev.id=LCD_RD_DATA();		//����0X80
					lcddev.id<<=8;	
					LCD_WR_REG(0XDC00);	
					lcddev.id|=LCD_RD_DATA();		//����0X00		
					if(lcddev.id==0x8000)lcddev.id=0x5510;//NT35510���ص�ID��8000H,Ϊ��������,����ǿ������Ϊ5510
					if(lcddev.id!=0X5510)			//Ҳ����NT5510,���Կ����ǲ���SSD1963
					{
						LCD_WR_REG(0XA1);
						lcddev.id=LCD_RD_DATA();
						lcddev.id=LCD_RD_DATA();	//����0X57
						lcddev.id<<=8;	 
						lcddev.id|=LCD_RD_DATA();	//����0X61	
						if(lcddev.id==0X5761)lcddev.id=0X1963;//SSD1963���ص�ID��5761H,Ϊ��������,����ǿ������Ϊ1963
					}
				}
			}
 		}  	
	}
	return lcddev.id;
}  
