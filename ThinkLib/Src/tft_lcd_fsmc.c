#include "tft_lcd_fsmc.h"

//LCD的画笔颜色和背景色	   
uint16_t POINT_COLOR=0x0000;	//画笔颜色
uint16_t BACK_COLOR=0xFFFF;  //背景色 
  
//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;
	 
//写寄存器函数
//regval:寄存器值
void LCD_WR_REG(uint16_t regval)
{   
	LCD->LCD_REG=regval;//写入要写的寄存器序号	 
}
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(uint16_t data)
{	 
	LCD->LCD_RAM=data;		 
}
//读LCD数据
//返回值:读到的值
uint16_t LCD_RD_DATA(void)
{
	volatile uint16_t ram;			//防止被优化
	ram=LCD->LCD_RAM;	
	return ram;	 
}					   
//写寄存器
//LCD_Reg:寄存器地址
//LCD_RegValue:要写入的数据
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue)
{	
	LCD->LCD_REG = LCD_Reg;		//写入要写的寄存器序号	 
	LCD->LCD_RAM = LCD_RegValue;//写入数据	    		 
}	   
//读寄存器
//LCD_Reg:寄存器地址
//返回值:读到的数据
uint16_t LCD_ReadReg(uint16_t LCD_Reg)
{										   
	LCD_WR_REG(LCD_Reg);		//写入要读的寄存器序号
	//有5us延迟		  
	return LCD_RD_DATA();		//返回读到的值
}  

//开始写GRAM
void LCD_WriteRAM_Prepare(void)
{
 	LCD->LCD_REG=lcddev.wramcmd;	  
}	 
//LCD写GRAM
//RGB_Code:颜色值
void LCD_WriteRAM(uint16_t RGB_Code)
{							    
	LCD->LCD_RAM = RGB_Code;//写十六位GRAM
}

//从ILI93xx读出的数据为GBR格式，而我们写入的时候为RGB格式。
//通过该函数转换
//c:GBR格式的颜色值
//返回值：RGB格式的颜色值
uint16_t LCD_BGR2RGB(uint16_t c)
{
	uint16_t  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 
//当mdk -O1时间优化时需要设置
//延时i
void opt_delay(uint8_t i)
{
	while(i--);
}

uint16_t LCD_GetID(void)
{
	lcddev.id=LCD_ReadReg(0x0000);	//读ID（9320/9325/9328/4531/4535等IC）   
  if(lcddev.id<0XFF||lcddev.id==0XFFFF||lcddev.id==0X9300)//读到ID不正确,新增lcddev.id==0X9300判断，因为9341在未被复位的情况下会被读成9300
	{	
		//尝试9341 ID的读取		
		LCD_WR_REG(0XD3);				   
		lcddev.id=LCD_RD_DATA();	//dummy read 	
 		lcddev.id=LCD_RD_DATA();	//读到0X00
  		lcddev.id=LCD_RD_DATA();   	//读取93								   
 		lcddev.id<<=8;
		lcddev.id|=LCD_RD_DATA();  	//读取41 	   			   
 		if(lcddev.id!=0X9341)		//非9341,尝试是不是6804
		{	
 			LCD_WR_REG(0XBF);				   
			lcddev.id=LCD_RD_DATA(); 	//dummy read 	 
	 		lcddev.id=LCD_RD_DATA();   	//读回0X01			   
	 		lcddev.id=LCD_RD_DATA(); 	//读回0XD0 			  	
	  		lcddev.id=LCD_RD_DATA();	//这里读回0X68 
			lcddev.id<<=8;
	  		lcddev.id|=LCD_RD_DATA();	//这里读回0X04	  
			if(lcddev.id!=0X6804)		//也不是6804,尝试看看是不是NT35310
			{ 
				LCD_WR_REG(0XD4);				   
				lcddev.id=LCD_RD_DATA();//dummy read  
				lcddev.id=LCD_RD_DATA();//读回0X01	 
				lcddev.id=LCD_RD_DATA();//读回0X53	
				lcddev.id<<=8;	 
				lcddev.id|=LCD_RD_DATA();	//这里读回0X10	 
				if(lcddev.id!=0X5310)		//也不是NT35310,尝试看看是不是NT35510
				{
					LCD_WR_REG(0XDA00);	
					lcddev.id=LCD_RD_DATA();		//读回0X00	 
					LCD_WR_REG(0XDB00);	
					lcddev.id=LCD_RD_DATA();		//读回0X80
					lcddev.id<<=8;	
					LCD_WR_REG(0XDC00);	
					lcddev.id|=LCD_RD_DATA();		//读回0X00		
					if(lcddev.id==0x8000)lcddev.id=0x5510;//NT35510读回的ID是8000H,为方便区分,我们强制设置为5510
					if(lcddev.id!=0X5510)			//也不是NT5510,尝试看看是不是SSD1963
					{
						LCD_WR_REG(0XA1);
						lcddev.id=LCD_RD_DATA();
						lcddev.id=LCD_RD_DATA();	//读回0X57
						lcddev.id<<=8;	 
						lcddev.id|=LCD_RD_DATA();	//读回0X61	
						if(lcddev.id==0X5761)lcddev.id=0X1963;//SSD1963读回的ID是5761H,为方便区分,我们强制设置为1963
					}
				}
			}
 		}  	
	}
	return lcddev.id;
}  
