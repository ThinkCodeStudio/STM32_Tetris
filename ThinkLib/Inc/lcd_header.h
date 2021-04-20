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

void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);//设置光标位置
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y);//读取个某点的颜色值	
void LCD_Scan_Dir(uint8_t dir);//设置LCD的自动扫描方向
void LCD_DrawPoint(uint16_t x,uint16_t y);//画点
void LCD_Fast_DrawPoint(uint16_t x,uint16_t y,uint16_t color);//快速画点
void LCD_SSD_BackLightSet(uint8_t pwm);//SSD1963 背光设置
void LCD_Display_Dir(uint8_t dir);//设置LCD显示方向
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);//设置窗口,并自动设置画点坐标到窗口左上角(sx,sy).
void LCD_Clear(uint16_t color);//清屏函数
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);//在指定区域内填充单个颜色
void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color);//在指定区域内填充指定颜色块
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);//画线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);//画矩形	
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r);//在指定位置画一个指定大小的圆
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);//在指定位置显示一个字符
uint32_t LCD_Pow(uint8_t m,uint8_t n);//m^n函数
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);//显示数字,高位为0,则不显示
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode);//显示数字,高位为0,还是显示
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p);//显示字符串

//LCD屏初始化，写入一些默认的设置参数，有15个版本，所以2000多行都是这个。
void LCD_Init(void(*)(uint32_t));
//Lcd* NewLCD(void(*)(uint32_t));

//LCD分辨率设置
#define SSD_HOR_RESOLUTION		800		//LCD水平分辨率
#define SSD_VER_RESOLUTION		480		//LCD垂直分辨率
//LCD驱动参数设置
#define SSD_HOR_PULSE_WIDTH		1		//水平脉宽
#define SSD_HOR_BACK_PORCH		46		//水平前廊
#define SSD_HOR_FRONT_PORCH		210		//水平后廊

#define SSD_VER_PULSE_WIDTH		1		//垂直脉宽
#define SSD_VER_BACK_PORCH		23		//垂直前廊
#define SSD_VER_FRONT_PORCH		22		//垂直前廊
//如下几个参数，自动计算
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)


#endif
