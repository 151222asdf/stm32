#include "MyApplication.h"
int32_t math1=0;
int32_t math2=0;
int32_t math3=0;
int32_t math4=0;

int32_t math01=0;
int32_t math02=0;
int32_t math03=0;
int32_t math04=0;

int32_t math11=0;
int32_t math12=0;
int32_t math13=0;
int32_t math14=0;

int8_t mode=0;
int keycom=0;

uint8_t common[20];
void COM(void)//界面设计
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	LCD_Fill(0,0,lcddev.width,lcddev.height,BLACK);
	POINT_COLOR=GRAY;
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z*0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);			
	/*绘制按键*5*/
	LCD_Fill(u*0.75,(z*0.2)*0,u,(z*0.2)*1,BRED);	
	LCD_Fill(u*0.75,(z*0.2)*1,u,(z*0.2)*2,GRED);
	LCD_Fill(u*0.75,(z*0.2)*2,u,(z*0.2)*3,GBLUE);	
	LCD_Fill(u*0.75,(z*0.2)*3,u,(z*0.2)*4,RED);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	LCD_Fill(u*0.75,(z*0.2)*4,u,(z*0.2)*5,LGRAYBLUE);
	/*绘制数据格*5*/
	POINT_COLOR=WHITE;//画笔
	LCD_DrawRectangle((u*0.15)*0,z*0.75,(u*0.15)*1,z);
	LCD_DrawRectangle((u*0.15)*1,z*0.75,(u*0.15)*2,z);
	LCD_DrawRectangle((u*0.15)*2,z*0.75,(u*0.15)*3,z);
	LCD_DrawRectangle((u*0.15)*3,z*0.75,(u*0.15)*4,z);
	LCD_DrawRectangle((u*0.15)*4,z*0.75,(u*0.15)*5,z);
	LCD_DrawLine((u*0.15)*0,(z*0.85),(u*0.15)*5,(z*0.85));
	/*数据格命名*/
	BACK_COLOR=BLACK;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.15)*0+1,(z*0.75)+2,80,16,16,"math1");
	LCD_ShowString((u*0.15)*1+1,(z*0.75)+2,80,16,16,"math2");
	LCD_ShowString((u*0.15)*2+1,(z*0.75)+2,80,16,16,"math3");
	LCD_ShowString((u*0.15)*3+1,(z*0.75)+2,80,16,16,"math4");
	LCD_ShowString((u*0.15)*4+1,(z*0.75)+2,80,16,16,"math5");
	/*按键命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*0+20,80,24,24,"1");
	BACK_COLOR=GRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*1+20,80,24,24,"2");
	BACK_COLOR=GBLUE;
	POINT_COLOR=BLACK; 
	LCD_ShowString((u*0.85),(z*0.2)*2+20,80,24,24,"3");
	BACK_COLOR=RED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*3+20,80,24,24,"4");
	BACK_COLOR=LGRAYBLUE;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*4+20,80,24,24,"5");		
}


void KEY_1(void)
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	POINT_COLOR=WHITE;//画笔
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z*0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);
}

void KEY_2(void)
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
		POINT_COLOR=YELLOW;//画笔
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z*0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);
}

void KEY_3(void)
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	POINT_COLOR=BLUE;//画笔
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z*0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);
}

void KEY_4(void)
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	POINT_COLOR=RED;//画笔
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z*0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);
}

void KEY_5(void)
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	POINT_COLOR=GRAY;//画笔
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z* 0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);
}






//界面总
void COM0(void)//界面选择
{	
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	/*绘制按键*5*/
	LCD_Fill((u*0.2)*0,(z*0.2)*0,(u*0.2)*1,z,BRED);	
	LCD_Fill((u*0.2)*1,(z*0.2)*0,(u*0.2)*2,z,GRED);
	LCD_Fill((u*0.2)*2,(z*0.2)*0,(u*0.2)*3,z,GBLUE);	
	LCD_Fill((u*0.2)*3,(z*0.2)*0,(u*0.2)*4,z,RED);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	LCD_Fill((u*0.2)*4,(z*0.2)*0,(u*0.2)*5,z,LGRAYBLUE);
	/*按键命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.1),(z*0.5),80,24,24,"1");
	BACK_COLOR=GRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.3),(z*0.5),80,24,24,"2");
	BACK_COLOR=GBLUE;
	POINT_COLOR=BLACK; 
	LCD_ShowString((u*0.5),(z*0.5),80,24,24,"3");
	BACK_COLOR=RED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.7),(z*0.5),80,24,24,"4");
	BACK_COLOR=LGRAYBLUE;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.9),(z*0.5),80,24,24,"5");		
}
void Q1(void)//
{
	COM0_1();
	keycom=1;
}
void Q2(void)//
{
	COM0_2();
	keycom=2;
}
void Q3(void)//
{
	COM0_3();
	keycom=3;
}
void Q4(void)//
{
	COM0_4();
	keycom=4;
}
void Q5(void)//
{
	COM0_5();
	keycom=5;
}
/**************************************************************************/
//波形绘制界面
void COM0_1(void)
{
	int x,y;//形参
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	LCD_Fill(0,0,lcddev.width,lcddev.height,BLACK);
	POINT_COLOR=GRAY;
	/*绘制网格*/
	for(x=0;x<=(u*0.75);x+=5)
		for(y=0;y<=(z*0.75);y+=20)
			LCD_DrawPoint(x,y);
	for(y=0;y<=(z*0.75);y+=5)
		for(x=0;x<=(u*0.75);x+=20)
			LCD_DrawPoint(x,y);			
	/*绘制按键*5*/
	LCD_Fill(u*0.75,(z*0.2)*0,u,(z*0.2)*1,BRED);	
	LCD_Fill(u*0.75,(z*0.2)*1,u,(z*0.2)*2,GRED);
	LCD_Fill(u*0.75,(z*0.2)*2,u,(z*0.2)*3,GBLUE);	
	LCD_Fill(u*0.75,(z*0.2)*3,u,(z*0.2)*4,RED);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	LCD_Fill(u*0.75,(z*0.2)*4,u,(z*0.2)*5,LGRAYBLUE);
	/*绘制数据格*5*/
	POINT_COLOR=WHITE;//画笔
	LCD_DrawRectangle((u*0.15)*0,z*0.75,(u*0.15)*1,z);
	LCD_DrawRectangle((u*0.15)*1,z*0.75,(u*0.15)*2,z);
	LCD_DrawRectangle((u*0.15)*2,z*0.75,(u*0.15)*3,z);
	LCD_DrawRectangle((u*0.15)*3,z*0.75,(u*0.15)*4,z);
	LCD_DrawRectangle((u*0.15)*4,z*0.75,(u*0.15)*5,z);
	LCD_DrawLine((u*0.15)*0,(z*0.85),(u*0.15)*5,(z*0.85));
	/*数据格命名*/
	BACK_COLOR=BLACK;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.15)*0+1,(z*0.75)+2,80,16,16,"math1");
	LCD_ShowString((u*0.15)*1+1,(z*0.75)+2,80,16,16,"math2");
	LCD_ShowString((u*0.15)*2+1,(z*0.75)+2,80,16,16,"math3");
	LCD_ShowString((u*0.15)*3+1,(z*0.75)+2,80,16,16,"math4");
	LCD_ShowString((u*0.15)*4+1,(z*0.75)+2,80,16,16,"math5");
	/*按键命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*0+20,80,24,24,"1");
	BACK_COLOR=GRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*1+20,80,24,24,"2");
	BACK_COLOR=GBLUE;
	POINT_COLOR=BLACK; 
	LCD_ShowString((u*0.85),(z*0.2)*2+20,80,24,24,"3");
	BACK_COLOR=RED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*3+20,80,24,24,"4");
	BACK_COLOR=LGRAYBLUE;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*4+20,80,24,24,"5");		
}
void W1(void)
{
	COM0();//返回
	keycom=0;
}
void W2(void)
{

}
void W3(void)
{

}
void W4(void)
{

}
void W5(void)
{

}
/*************************************************************************************/
//幅频特性界面
void COM0_2(void)
{
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	LCD_Fill(0,0,lcddev.width,lcddev.height,BLACK);//清空
	/*绘制坐标轴*/
	POINT_COLOR=WHITE;
	LCD_DrawLine((u*0.10)*1,(z*0.10)*1,(u*0.10)*1,(z*0.10)*7);//y
	LCD_DrawLine((u*0.10)*1,(z*0.10)*7,(u*0.10)*7,(z*0.10)*7);//x
	/*按键设定*/
	LCD_Fill((u*0.10)*7,(z*0.1)*0,u,(z*0.1)*5,BRED);	
	LCD_Fill((u*0.10)*7,(z*0.1)*5,u,(z*0.1)*10,GRED);	
}
void E1(void)
{
	COM0();//返回
	keycom=0;
}
void E2(void)
{

}
/*************************************************************************************/
//9959调频界面 9959扫频界面 9959调幅移向
void COM0_3(void)//调频
{
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
		LCD_Fill(0,0,lcddev.width,lcddev.height,BLACK);//清空//清空	
	BACK_COLOR=BLACK;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.10)*0,(z*0.15)*0,80,16,16,"9959");
	LCD_ShowString((u*0.10)*0,(z*0.15)*1,80,16,16,"CH0:");
	LCD_ShowString((u*0.10)*0,(z*0.15)*2,80,16,16,"CH1:");
	LCD_ShowString((u*0.10)*0,(z*0.15)*3,80,16,16,"CH2:");
	LCD_ShowString((u*0.10)*0,(z*0.15)*4,80,16,16,"CH3:");
	
	sprintf((char *)common,"%d",math1);
	LCD_ShowString((u*0.20),(z*0.15)*1,80,16,16,common);
	LCD_ShowString((u*0.60),(z*0.15)*1,80,16,16,"HZ");
	sprintf((char *)common,"%d",math2);
	LCD_ShowString((u*0.20),(z*0.15)*2,80,16,16,common);
	LCD_ShowString((u*0.60),(z*0.15)*2,80,16,16,"HZ");
	sprintf((char *)common,"%d",math3);
	LCD_ShowString((u*0.20),(z*0.15)*3,80,16,16,common);	
	LCD_ShowString((u*0.60),(z*0.15)*3,80,16,16,"HZ");
	sprintf((char *)common,"%d",math4);
	LCD_ShowString((u*0.20),(z*0.15)*4,80,16,16,common);	
	LCD_ShowString((u*0.60),(z*0.15)*4,80,16,16,"HZ");
	
	/*绘制按键*5*/
	LCD_Fill(u*0.75,(z*0.2)*0,u,(z*0.2)*1,BRED);	
	LCD_Fill(u*0.75,(z*0.2)*1,u,(z*0.2)*2,GRED);
	LCD_Fill(u*0.75,(z*0.2)*2,u,(z*0.2)*3,GBLUE);	
	LCD_Fill(u*0.75,(z*0.2)*3,u,(z*0.2)*4,RED);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	LCD_Fill(u*0.75,(z*0.2)*4,u,(z*0.2)*5,LGRAYBLUE);
	/*绘制表格*/
	POINT_COLOR=WHITE;//画笔
	LCD_DrawRectangle((u*0.15)*0,z*0.75,(u*0.15)*1,z);
	LCD_DrawRectangle((u*0.15)*1,z*0.75,(u*0.15)*2,z);
	LCD_DrawRectangle((u*0.15)*2,z*0.75,(u*0.15)*3,z);
	LCD_DrawRectangle((u*0.15)*3,z*0.75,(u*0.15)*4,z);
	LCD_DrawRectangle((u*0.15)*4,z*0.75,(u*0.15)*5,z);
	LCD_DrawLine((u*0.15)*0,(z*0.75)+1,(u*0.15)*5,(z*0.75)+1);
	/*数据格命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.15)*0+1,(z*0.75)+2,80,16,16,"OF");
	LCD_ShowString((u*0.15)*1+1,(z*0.75)+2,80,16,16,"1");
	LCD_ShowString((u*0.15)*2+1,(z*0.75)+2,80,16,16,"2");
	LCD_ShowString((u*0.15)*3+1,(z*0.75)+2,80,16,16,"3");
	LCD_ShowString((u*0.15)*4+1,(z*0.75)+2,80,16,16,"4");
	/*按键命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*0+20,80,24,24,"+");
	BACK_COLOR=GRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*1+20,80,24,24,"-");
	BACK_COLOR=GBLUE;
	POINT_COLOR=BLACK; 
	LCD_ShowString((u*0.85),(z*0.2)*2+20,80,24,24,"<-");
	BACK_COLOR=RED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*3+20,80,24,24,"->");
	BACK_COLOR=LGRAYBLUE;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*4+20,80,24,24,"ok");
}
void COM0_4(void)//扫频
{
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	LCD_Fill(0,0,lcddev.width,lcddev.height,BLACK);//清空
	BACK_COLOR=BLACK;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.00),(z*0.2)*0+20,80,24,24,"9959");
	LCD_ShowString((u*0.00),(z*0.2)*0+40,80,24,24,"Min:");
	LCD_ShowString((u*0.00),(z*0.2)*0+60,80,24,24,"Max:");
	LCD_ShowString((u*0.00),(z*0.2)*0+80,80,24,24,"Int:");
	LCD_ShowString((u*0.00),(z*0.2)*0+100,80,24,24,"Mas:");
	
	sprintf((char *)common,"%d",math01);
	LCD_ShowString((u*0.20),(z*0.2)*0+40,80,16,16,common);
	LCD_ShowString((u*0.60),(z*0.2)*0+40,80,16,16,"HZ");
	sprintf((char *)common,"%d",math02);
	LCD_ShowString((u*0.20),(z*0.2)*0+60,80,16,16,common);
	LCD_ShowString((u*0.60),(z*0.2)*0+60,80,16,16,"HZ");
	sprintf((char *)common,"%d",math03);
	LCD_ShowString((u*0.20),(z*0.2)*0+80,80,16,16,common);	
	LCD_ShowString((u*0.60),(z*0.2)*0+80,80,16,16,"HZ");
	sprintf((char *)common,"%d",math04);
	LCD_ShowString((u*0.20),(z*0.2)*0+100,80,16,16,common);	
	LCD_ShowString((u*0.60),(z*0.2)*0+100,80,16,16,"MS");
	
		/*绘制按键*5*/
	LCD_Fill(u*0.75,(z*0.2)*0,u,(z*0.2)*1,BRED);	
	LCD_Fill(u*0.75,(z*0.2)*1,u,(z*0.2)*2,GRED);
	LCD_Fill(u*0.75,(z*0.2)*2,u,(z*0.2)*3,GBLUE);	
	LCD_Fill(u*0.75,(z*0.2)*3,u,(z*0.2)*4,RED);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	LCD_Fill(u*0.75,(z*0.2)*4,u,(z*0.2)*5,LGRAYBLUE);
	/*绘制表格*/
	POINT_COLOR=WHITE;//画笔
	LCD_DrawRectangle((u*0.15)*0,z*0.75,(u*0.15)*1,z);
	LCD_DrawRectangle((u*0.15)*1,z*0.75,(u*0.15)*2,z);
	LCD_DrawRectangle((u*0.15)*2,z*0.75,(u*0.15)*3,z);
	LCD_DrawRectangle((u*0.15)*3,z*0.75,(u*0.15)*4,z);
	LCD_DrawRectangle((u*0.15)*4,z*0.75,(u*0.15)*5,z);
	LCD_DrawLine((u*0.15)*0,(z*0.75)+1,(u*0.15)*5,(z*0.75)+1);
	/*数据格命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.15)*0+1,(z*0.75)+2,80,16,16,"OF");
	LCD_ShowString((u*0.15)*1+1,(z*0.75)+2,80,16,16,"1");
	LCD_ShowString((u*0.15)*2+1,(z*0.75)+2,80,16,16,"2");
	LCD_ShowString((u*0.15)*3+1,(z*0.75)+2,80,16,16,"3");
	LCD_ShowString((u*0.15)*4+1,(z*0.75)+2,80,16,16,"4");
	/*按键命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*0+20,80,24,24,"+");
	BACK_COLOR=GRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*1+20,80,24,24,"-");
	BACK_COLOR=GBLUE;
	POINT_COLOR=BLACK; 
	LCD_ShowString((u*0.85),(z*0.2)*2+20,80,24,24,"<-");
	BACK_COLOR=RED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*3+20,80,24,24,"->");
	BACK_COLOR=LGRAYBLUE;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*4+20,80,24,24,"ok");
}
void COM0_5(void)//调幅移向
{
	int u,z;//用于记录屏幕长短
	u=lcddev.width;//屏幕长
	z=lcddev.height;//屏幕宽
	LCD_Fill(0,0,lcddev.width,lcddev.height,BLACK);//清空
	BACK_COLOR=BLACK;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.10)*0,(z*0.15)*0,80,16,16,"9959");
	LCD_ShowString((u*0.10)*0,(z*0.15)*1,80,16,16,"CH0:");
	LCD_ShowString((u*0.10)*0,(z*0.15)*2,80,16,16,"CH1:");
	LCD_ShowString((u*0.10)*0,(z*0.15)*3,80,16,16,"CH2:");
	LCD_ShowString((u*0.10)*0,(z*0.15)*4,80,16,16,"CH3:");
	
	sprintf((char *)common,"%d",math11);
	LCD_ShowString((u*0.20),(z*0.15)*1,80,16,16,common);
	LCD_ShowString((u*0.60),(z*0.15)*1,80,16,16,"A");
	sprintf((char *)common,"%d",math12);
	LCD_ShowString((u*0.20),(z*0.15)*2,80,16,16,common);
	LCD_ShowString((u*0.60),(z*0.15)*2,80,16,16,"A");
	sprintf((char *)common,"%d",math13);
	LCD_ShowString((u*0.20),(z*0.15)*3,80,16,16,common);	
	LCD_ShowString((u*0.60),(z*0.15)*3,80,16,16,"A");
	sprintf((char *)common,"%d",math14);
	LCD_ShowString((u*0.20),(z*0.15)*4,80,16,16,common);	
	LCD_ShowString((u*0.60),(z*0.15)*4,80,16,16,"A");	
	
	/*绘制按键*5*/
	LCD_Fill(u*0.75,(z*0.2)*0,u,(z*0.2)*1,BRED);	
	LCD_Fill(u*0.75,(z*0.2)*1,u,(z*0.2)*2,GRED);
	LCD_Fill(u*0.75,(z*0.2)*2,u,(z*0.2)*3,GBLUE);	
	LCD_Fill(u*0.75,(z*0.2)*3,u,(z*0.2)*4,RED);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
	LCD_Fill(u*0.75,(z*0.2)*4,u,(z*0.2)*5,LGRAYBLUE);
	/*绘制表格*/
	POINT_COLOR=WHITE;//画笔
	LCD_DrawRectangle((u*0.15)*0,z*0.75,(u*0.15)*1,z);
	LCD_DrawRectangle((u*0.15)*1,z*0.75,(u*0.15)*2,z);
	LCD_DrawRectangle((u*0.15)*2,z*0.75,(u*0.15)*3,z);
	LCD_DrawRectangle((u*0.15)*3,z*0.75,(u*0.15)*4,z);
	LCD_DrawRectangle((u*0.15)*4,z*0.75,(u*0.15)*5,z);
	LCD_DrawLine((u*0.15)*0,(z*0.75)+1,(u*0.15)*5,(z*0.75)+1);
	/*数据格命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=WHITE;
	LCD_ShowString((u*0.15)*0+1,(z*0.75)+2,80,16,16,"OF");
	LCD_ShowString((u*0.15)*1+1,(z*0.75)+2,80,16,16,"1");
	LCD_ShowString((u*0.15)*2+1,(z*0.75)+2,80,16,16,"2");
	LCD_ShowString((u*0.15)*3+1,(z*0.75)+2,80,16,16,"3");
	LCD_ShowString((u*0.15)*4+1,(z*0.75)+2,80,16,16,"4");
	/*按键命名*/
	BACK_COLOR=BRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*0+20,80,24,24,"+");
	BACK_COLOR=GRED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*1+20,80,24,24,"-");
	BACK_COLOR=GBLUE;
	POINT_COLOR=BLACK; 
	LCD_ShowString((u*0.85),(z*0.2)*2+20,80,24,24,"<-");
	BACK_COLOR=RED;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*3+20,80,24,24,"->");
	BACK_COLOR=LGRAYBLUE;
	POINT_COLOR=BLACK;
	LCD_ShowString((u*0.85),(z*0.2)*4+20,80,24,24,"ok");
}
void R1(void)
{
	COM0();//返回
	keycom=0;
}
void R2(void)
{

}
void R3(void)
{

}
void R4(void)
{

}
void R5(void)
{

}
void R6(void)
{

}
void R7(void)
{

}
void R8(void)
{

}
void R9(void)
{

}
void R0(void)
{

}








