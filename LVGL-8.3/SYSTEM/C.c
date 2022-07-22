#include "MyApplication.h"
int on=0;
/**********************************************************
��飺���㺯������תY����
***********************************************************/
void lcd_huadian(u16 a,u16 b,u16 color)
{							    
	LCD_Fast_DrawPoint(a,240-b,color);
}

/**********************************************************
��飺���ߺ�������תY����
***********************************************************/
void lcd_huaxian(u16 x1,u16 y1,u16 x2,u16 y2)
{
	LCD_DrawLine(x1,240-y1,x2,240-y2);
}

/******************************************************************
��������:clear_point()
��������:ѭ�����²���
����˵��:mode ����ģʽѡ�� 1��������ģʽ��0�������ģʽ
��    ע:���ε���ʾ�ɲ��ô�㷽ʽ�ͻ����߷�ʽ
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
		//����ֵ
		pre_vol=120+ADC_Data[x]/50;
		//���θ���
		if(mode==1)
		{
					POINT_COLOR=WHITE;
			if(x!=0&&x<200)	//ȥ����һ�������һ���Լ�y���ϵ�Ļ���
				lcd_huaxian(x,past_vol,x+1,pre_vol);
			else
				lcd_huadian(x,pre_vol,BLACK);
		}
//		if (getKey() != 0) break;
		past_vol = pre_vol;
	}
}	


/******************************************************************
��������:clear_point()
��������:ѭ�����²���
����˵��:mode ����ģʽѡ�� 1��������ģʽ��0�������ģʽ
��    ע:���ε���ʾ�ɲ��ô�㷽ʽ�ͻ����߷�ʽ
*******************************************************************/
void clear_point_1(uint16_t mode,uint32_t* ADC_Data )//2.8�绮��
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
		//����ֵ
		pre_vol=50+ADC_Data[x]/50;
		//���θ���
		if(mode==1)
		{
					POINT_COLOR=WHITE;
			if(x!=0&&x<240)	//ȥ����һ�������һ���Լ�y���ϵ�Ļ���
				lcd_huaxian(x,past_vol,x+1,pre_vol);
			else
				lcd_huadian(x,pre_vol,BLACK);
		}
//		if (getKey() != 0) break;
		past_vol = pre_vol;
	}
}

/******************************************************************
��������:clear_point()
��������:ѭ�����²���
����˵��:mode ����ģʽѡ�� 1��������ģʽ��0�������ģʽ
��    ע:���ε���ʾ�ɲ��ô�㷽ʽ�ͻ����߷�ʽ
*******************************************************************/
void clear_point_11(uint16_t mode)//2.8�绮��
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
		//����ֵ
		pre_vol=120;
		//���θ���
		if(mode==1)
		{
			POINT_COLOR=WHITE;
			if(x!=0&&x<320)	//ȥ����һ�������һ���Լ�y���ϵ�Ļ���
				lcd_huaxian(x,past_vol,x+1,pre_vol);
			else
				lcd_huadian(x,pre_vol,BLACK);
		}
//		if (getKey() != 0) break;
		past_vol = pre_vol;
	}
}






