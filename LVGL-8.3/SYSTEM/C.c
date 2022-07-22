#include "MyApplication.h"
int on=0;
/**********************************************************
简介：画点函数，反转Y坐标
***********************************************************/
void lcd_huadian(u16 a,u16 b,u16 color)
{							    
	LCD_Fast_DrawPoint(a,240-b,color);
}

/**********************************************************
简介：画线函数，反转Y坐标
***********************************************************/
void lcd_huaxian(u16 x1,u16 y1,u16 x2,u16 y2)
{
	LCD_DrawLine(x1,240-y1,x2,240-y2);
}

/******************************************************************
函数名称:clear_point()
函数功能:循环更新波形
参数说明:mode 波形模式选择 1——连线模式，0——打点模式
备    注:波形的显示可采用打点方式和绘制线方式
*******************************************************************/
void clear_point(uint16_t mode,uint32_t* ADC_Data )
{
	uint16_t x,past_vol,pre_vol,y;
	for(x=0;x<200;x++)
	{		
		POINT_COLOR=BLACK;
		LCD_DrawLine(x,0,x,380);
		if(x%20==0)
			for(y=0;y<=380;y+=4)
				LCD_Fast_DrawPoint(x,y,GRAY);
		if(x%4==0)
			for(y=0;y<=380;y+=20)
				LCD_Fast_DrawPoint(x,y,GRAY);	
		//测量值
		pre_vol=120+ADC_Data[x]/50;
		//波形更新
		if(mode==1)
		{
					POINT_COLOR=WHITE;
			if(x!=0&&x<200)	//去除第一个，最后一个以及y轴上点的绘制
				lcd_huaxian(x,past_vol,x+1,pre_vol);
			else
				lcd_huadian(x,pre_vol,BLACK);
		}
//		if (getKey() != 0) break;
		past_vol = pre_vol;
	}
}	


/******************************************************************
函数名称:clear_point()
函数功能:循环更新波形
参数说明:mode 波形模式选择 1——连线模式，0——打点模式
备    注:波形的显示可采用打点方式和绘制线方式
*******************************************************************/
void clear_point_1(uint16_t mode,uint32_t* ADC_Data )//2.8寸划波
{
	uint16_t x,past_vol,pre_vol,y;
	for(x=0;x<240;x++)
	{		
		POINT_COLOR=BLACK;
		LCD_DrawLine(x,0,x,200);
		if(x%20==0)
			for(y=0;y<=200;y+=4)
				LCD_Fast_DrawPoint(x,y,GRAY);
		if(x%4==0)
			for(y=0;y<=200;y+=20)
				LCD_Fast_DrawPoint(x,y,GRAY);	
		//测量值
		pre_vol=50+ADC_Data[x]/50;
		//波形更新
		if(mode==1)
		{
					POINT_COLOR=WHITE;
			if(x!=0&&x<240)	//去除第一个，最后一个以及y轴上点的绘制
				lcd_huaxian(x,past_vol,x+1,pre_vol);
			else
				lcd_huadian(x,pre_vol,BLACK);
		}
//		if (getKey() != 0) break;
		past_vol = pre_vol;
	}
}

/******************************************************************
函数名称:clear_point()
函数功能:循环更新波形
参数说明:mode 波形模式选择 1——连线模式，0——打点模式
备    注:波形的显示可采用打点方式和绘制线方式
*******************************************************************/
void clear_point_11(uint16_t mode)//2.8寸划波
{
	uint16_t x,past_vol,pre_vol,y;
	for(x=0;x<320;x++)
	{	
		POINT_COLOR=BLACK;
		LCD_DrawLine(x,0,x,240);
		if(x%20==0)
			for(y=0;y<=240;y+=4)
				LCD_Fast_DrawPoint(x,y,GRAY);
		if(x%4==0)
			for(y=0;y<=240;y+=20)
				LCD_Fast_DrawPoint(x,y,GRAY);	
		//测量值
		pre_vol=120;
		//波形更新
		if(mode==1)
		{
			POINT_COLOR=WHITE;
			if(x!=0&&x<320)	//去除第一个，最后一个以及y轴上点的绘制
				lcd_huaxian(x,past_vol,x+1,pre_vol);
			else
				lcd_huadian(x,pre_vol,BLACK);
		}
//		if (getKey() != 0) break;
		past_vol = pre_vol;
	}
}






