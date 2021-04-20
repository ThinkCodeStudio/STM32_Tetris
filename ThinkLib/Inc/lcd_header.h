#ifndef __LCD_HEADER_H__
#define __LCD_HEADER_H__

#include "tft_lcd_fsmc.h"
#include "thint.h"
//#include "stm32f1xx_hal.h"
//#define delay_ms(X) HAL_Delay(X)
/*
typedef struct{
	void(*set_cursor)(u16,u16);
	u16(*read_point)(u16,u16);
	void(*scan_dir)(u8);
	void(*draw_point)(u16,u16);
	void(*draw_point_fast)(u16,u16,u16);
	void(*display_dir)(u8);
	void(*set_window)(u16,u16,u16,u16);
	void(*clear)(u16);
	void(*fill)(u16,u16,u16,u16,u16);
	void(*fill_color)(u16,u16,u16,u16,u16*);
	void(*draw_line)(u16,u16,u16,u16);
	void(*draw_rectangle)(u16,u16,u16,u16);
	void(*draw_circle)(u16,u16,u8);
	void(*show_char)(u16,u16,u8,u8,u8);
	u32(*pow)(u8,u8);
	void(*show_num)(u16,u16,u32,u8,u8);
	void(*show_num_x)(u16,u16,u32,u8,u8,u8);
	void(*show_string)(u16,u16,u16,u16,u8,u8*);
}Lcd;*/

void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);//���ù��λ��
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y);//��ȡ��ĳ�����ɫֵ	
void LCD_Scan_Dir(uint8_t dir);//����LCD���Զ�ɨ�跽��
void LCD_DrawPoint(uint16_t x,uint16_t y);//����
void LCD_Fast_DrawPoint(uint16_t x,uint16_t y,uint16_t color);//���ٻ���
void LCD_SSD_BackLightSet(uint8_t pwm);//SSD1963 ��������
void LCD_Display_Dir(uint8_t dir);//����LCD��ʾ����
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);//���ô���,���Զ����û������굽�������Ͻ�(sx,sy).
void LCD_Clear(uint16_t color);//��������
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);//��ָ����������䵥����ɫ
void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color);//��ָ�����������ָ����ɫ��
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);//����
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);//������	
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r);//��ָ��λ�û�һ��ָ����С��Բ
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);//��ָ��λ����ʾһ���ַ�
uint32_t LCD_Pow(uint8_t m,uint8_t n);//m^n����
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);//��ʾ����,��λΪ0,����ʾ
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode);//��ʾ����,��λΪ0,������ʾ
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p);//��ʾ�ַ���

//LCD����ʼ����д��һЩĬ�ϵ����ò�������15���汾������2000���ж��������
void LCD_Init(void(*)(uint32_t));
//Lcd* NewLCD(void(*)(uint32_t));

//LCD�ֱ�������
#define SSD_HOR_RESOLUTION		800		//LCDˮƽ�ֱ���
#define SSD_VER_RESOLUTION		480		//LCD��ֱ�ֱ���
//LCD������������
#define SSD_HOR_PULSE_WIDTH		1		//ˮƽ����
#define SSD_HOR_BACK_PORCH		46		//ˮƽǰ��
#define SSD_HOR_FRONT_PORCH		210		//ˮƽ����

#define SSD_VER_PULSE_WIDTH		1		//��ֱ����
#define SSD_VER_BACK_PORCH		23		//��ֱǰ��
#define SSD_VER_FRONT_PORCH		22		//��ֱǰ��
//���¼����������Զ�����
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)


#endif
