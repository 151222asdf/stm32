#ifndef _TFT_LCD_H_
#define _TFT_LCD_H_
#include "MyApplication.h"


void Load_Drow_Dialog(void);
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color);	
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color);
u16 my_abs(u16 x1,u16 x2);
void lcd_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color);
void rtp_test(void);
void ctp_test(void);//����ѡ��������

void rtp_test0(void);
void ctp_test0(void);//���λ��ƽ���

void rtp_test1(void);
void ctp_test1(void);//��Ƶ���Խ���

void rtp_test2(void);
void ctp_test2(void);//��Ƶ���Խ���
#endif
