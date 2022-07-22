#include "MyApplication.h"

//清空屏幕并在右上角显示"RST"
void Load_Drow_Dialog(void)
{
	LCD_Clear(WHITE);//清屏   
 	POINT_COLOR=BLUE;//设置字体为蓝色 
	LCD_ShowString(lcddev.width-24,0,200,16,16,"RST");//显示清屏区域
  	POINT_COLOR=RED;//设置画笔蓝色 
}
////////////////////////////////////////////////////////////////////////////////
//电容触摸屏专有部分
//画水平线
//x0,y0:坐标
//len:线长度
//color:颜色
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color)
{
	if(len==0)return;
	LCD_Fill(x0,y0,x0+len-1,y0,color);	
}
//画实心圆
//x0,y0:坐标
//r:半径
//color:颜色
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color)
{											  
	u32 i;
	u32 imax = ((u32)r*707)/1000+1;
	u32 sqmax = (u32)r*(u32)r+(u32)r/2;
	u32 x=r;
	gui_draw_hline(x0-r,y0,2*r,color);
	for (i=1;i<=imax;i++) 
	{
		if ((i*i+x*x)>sqmax)// draw lines from outside  
		{
 			if (x>imax) 
			{
				gui_draw_hline (x0-i+1,y0+x,2*(i-1),color);
				gui_draw_hline (x0-i+1,y0-x,2*(i-1),color);
			}
			x--;
		}
		// draw lines from inside (center)  
		gui_draw_hline(x0-x,y0+i,2*x,color);
		gui_draw_hline(x0-x,y0-i,2*x,color);
	}
}  
//两个数之差的绝对值 
//x1,x2：需取差值的两个数
//返回值：|x1-x2|
u16 my_abs(u16 x1,u16 x2)
{			 
	if(x1>x2)return x1-x2;
	else return x2-x1;
}  
//画一条粗线
//(x1,y1),(x2,y2):线条的起始坐标
//size：线条的粗细程度
//color：线条的颜色
void lcd_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	if(x1<size|| x2<size||y1<size|| y2<size)return; 
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向 
	else if(delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		gui_fill_circle(uRow,uCol,size,color);//画点 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}   
////////////////////////////////////////////////////////////////////////////////
//5个触控点的颜色(电容触摸屏用)												 
const u16 POINT_COLOR_TBL[5]={RED,GREEN,BLUE,BROWN,GRED};  
//电阻触摸屏测试函数
void rtp_test(void)//初始界面选择
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]<(lcddev.width*0.2)*1&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q1();//清除
				else if(tp_dev.x[0]<(lcddev.width*0.2)*2&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q2();//清除
				else if(tp_dev.x[0]<(lcddev.width*0.2)*3&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q3();//清除
				else if(tp_dev.x[0]<(lcddev.width*0.2)*4&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q4();//清除
				else if(tp_dev.x[0]<(lcddev.width*0.2)*5&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q5();//清除	  			   
			}
		}else delay_ms(10);	//没有按键按下的时候 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//电容触摸屏测试函数
void ctp_test(void)//初始界面选择
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//最后一次的数据 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X坐标:%d,Y坐标:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//画线
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]<(lcddev.width*0.2)*1&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q1();//功能1
					else if(tp_dev.x[t]<(lcddev.width*0.2)*2&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q2();//功能2
					else if(tp_dev.x[t]<(lcddev.width*0.2)*3&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q3();//功能3
					else if(tp_dev.x[t]<(lcddev.width*0.2)*4&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q4();//功能4
					else if(tp_dev.x[t]<(lcddev.width*0.2)*5&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q5();//功能5
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);
	
}


/*触摸屏界面一检测*/
//电阻触摸屏测试函数
void rtp_test0(void)//初始界面选择
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*1)W1();//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*2)W2();//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*3)W3();//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*4)W4();//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*5)W5();//清除	  			   
			}
		}else delay_ms(10);	//没有按键按下的时候 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//电容触摸屏测试函数
void ctp_test0(void)//初始界面选择
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//最后一次的数据 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X坐标:%d,Y坐标:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//画线
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*1)W1();//功能1
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*2)W2();//功能2
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*3)W3();//功能3
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*4)W4();//功能4
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*5)W5();//功能5
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);

}



/*触摸屏界面二检测*/
//电阻触摸屏测试函数
void rtp_test1(void)//初始界面选择
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.5)*1)E1();//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.5)*2)E2();//清除			   
			}
		}else delay_ms(10);	//没有按键按下的时候 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//电容触摸屏测试函数
void ctp_test1(void)//初始界面选择
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//最后一次的数据 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X坐标:%d,Y坐标:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//画线
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.5)*1)E1();//功能1
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.5)*2)E2();//功能2
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);
	
}


/*触摸屏界面三，四，五检测*/
//电阻触摸屏测试函数
void rtp_test2(void)//初始界面选择
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*1){R1();}//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*2){R2();}//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*3){R3();}//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*4){R4();}//清除
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*5){R5();}//清除	
				else if(tp_dev.x[0]<(lcddev.width*0.15*1)&&tp_dev.y[0]>(lcddev.height*0.75)){R6();}//清除
				else if(tp_dev.x[0]<(lcddev.width*0.15*2)&&tp_dev.y[0]>(lcddev.height*0.75)){R7();}//清除
				else if(tp_dev.x[0]<(lcddev.width*0.15*3)&&tp_dev.y[0]>(lcddev.height*0.75)){R8();}//清除
				else if(tp_dev.x[0]<(lcddev.width*0.15*4)&&tp_dev.y[0]>(lcddev.height*0.75)){R9();}//清除
				else if(tp_dev.x[0]<(lcddev.width*0.15*5)&&tp_dev.y[0]>(lcddev.height*0.75)){R0();}//清除					   
			}
		}else delay_ms(10);	//没有按键按下的时候 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//电容触摸屏测试函数
void ctp_test2(void)//初始界面选择
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//最后一次的数据 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X坐标:%d,Y坐标:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//画线
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*1){R1();}//功能1
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*2){R2();}//功能2
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*3){R3();}//功能3
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*4){R4();}//功能4
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*5){R5();}//功能5
					else if(tp_dev.x[0]<(lcddev.width*0.15*1)&&tp_dev.y[0]>(lcddev.height*0.75)){R6();}
					else if(tp_dev.x[0]<(lcddev.width*0.15*2)&&tp_dev.y[0]>(lcddev.height*0.75)){R7();}//清除
					else if(tp_dev.x[0]<(lcddev.width*0.15*3)&&tp_dev.y[0]>(lcddev.height*0.75)){R8();}//清除
					else if(tp_dev.x[0]<(lcddev.width*0.15*4)&&tp_dev.y[0]>(lcddev.height*0.75)){R9();}//清除
					else if(tp_dev.x[0]<(lcddev.width*0.15*5)&&tp_dev.y[0]>(lcddev.height*0.75)){R0();}//清除
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);
	
}







