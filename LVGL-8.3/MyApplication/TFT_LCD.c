#include "MyApplication.h"

//�����Ļ�������Ͻ���ʾ"RST"
void Load_Drow_Dialog(void)
{
	LCD_Clear(WHITE);//����   
 	POINT_COLOR=BLUE;//��������Ϊ��ɫ 
	LCD_ShowString(lcddev.width-24,0,200,16,16,"RST");//��ʾ��������
  	POINT_COLOR=RED;//���û�����ɫ 
}
////////////////////////////////////////////////////////////////////////////////
//���ݴ�����ר�в���
//��ˮƽ��
//x0,y0:����
//len:�߳���
//color:��ɫ
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color)
{
	if(len==0)return;
	LCD_Fill(x0,y0,x0+len-1,y0,color);	
}
//��ʵ��Բ
//x0,y0:����
//r:�뾶
//color:��ɫ
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
//������֮��ľ���ֵ 
//x1,x2����ȡ��ֵ��������
//����ֵ��|x1-x2|
u16 my_abs(u16 x1,u16 x2)
{			 
	if(x1>x2)return x1-x2;
	else return x2-x1;
}  
//��һ������
//(x1,y1),(x2,y2):��������ʼ����
//size�������Ĵ�ϸ�̶�
//color����������ɫ
void lcd_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	if(x1<size|| x2<size||y1<size|| y2<size)return; 
	delta_x=x2-x1; //������������ 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //���õ������� 
	else if(delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//ˮƽ�� 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//������� 
	{  
		gui_fill_circle(uRow,uCol,size,color);//���� 
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
//5�����ص����ɫ(���ݴ�������)												 
const u16 POINT_COLOR_TBL[5]={RED,GREEN,BLUE,BROWN,GRED};  
//���败�������Ժ���
void rtp_test(void)//��ʼ����ѡ��
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]<(lcddev.width*0.2)*1&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q1();//���
				else if(tp_dev.x[0]<(lcddev.width*0.2)*2&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q2();//���
				else if(tp_dev.x[0]<(lcddev.width*0.2)*3&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q3();//���
				else if(tp_dev.x[0]<(lcddev.width*0.2)*4&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q4();//���
				else if(tp_dev.x[0]<(lcddev.width*0.2)*5&&tp_dev.y[0]<(lcddev.height*0.2)*5)Q5();//���	  			   
			}
		}else delay_ms(10);	//û�а������µ�ʱ�� 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//���ݴ��������Ժ���
void ctp_test(void)//��ʼ����ѡ��
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//���һ�ε����� 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X����:%d,Y����:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//����
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]<(lcddev.width*0.2)*1&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q1();//����1
					else if(tp_dev.x[t]<(lcddev.width*0.2)*2&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q2();//����2
					else if(tp_dev.x[t]<(lcddev.width*0.2)*3&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q3();//����3
					else if(tp_dev.x[t]<(lcddev.width*0.2)*4&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q4();//����4
					else if(tp_dev.x[t]<(lcddev.width*0.2)*5&&tp_dev.y[t]<(lcddev.height*0.2)*5)Q5();//����5
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);
	
}


/*����������һ���*/
//���败�������Ժ���
void rtp_test0(void)//��ʼ����ѡ��
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*1)W1();//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*2)W2();//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*3)W3();//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*4)W4();//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*5)W5();//���	  			   
			}
		}else delay_ms(10);	//û�а������µ�ʱ�� 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//���ݴ��������Ժ���
void ctp_test0(void)//��ʼ����ѡ��
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//���һ�ε����� 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X����:%d,Y����:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//����
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*1)W1();//����1
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*2)W2();//����2
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*3)W3();//����3
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*4)W4();//����4
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*5)W5();//����5
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);

}



/*��������������*/
//���败�������Ժ���
void rtp_test1(void)//��ʼ����ѡ��
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.5)*1)E1();//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.5)*2)E2();//���			   
			}
		}else delay_ms(10);	//û�а������µ�ʱ�� 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//���ݴ��������Ժ���
void ctp_test1(void)//��ʼ����ѡ��
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//���һ�ε����� 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X����:%d,Y����:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//����
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.5)*1)E1();//����1
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.5)*2)E2();//����2
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);
	
}


/*���������������ģ�����*/
//���败�������Ժ���
void rtp_test2(void)//��ʼ����ѡ��
{
	u8 i=0;	  

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*1){R1();}//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*2){R2();}//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*3){R3();}//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*4){R4();}//���
				else if(tp_dev.x[0]>(lcddev.width*0.75)&&tp_dev.y[0]<(lcddev.height*0.2)*5){R5();}//���	
				else if(tp_dev.x[0]<(lcddev.width*0.15*1)&&tp_dev.y[0]>(lcddev.height*0.75)){R6();}//���
				else if(tp_dev.x[0]<(lcddev.width*0.15*2)&&tp_dev.y[0]>(lcddev.height*0.75)){R7();}//���
				else if(tp_dev.x[0]<(lcddev.width*0.15*3)&&tp_dev.y[0]>(lcddev.height*0.75)){R8();}//���
				else if(tp_dev.x[0]<(lcddev.width*0.15*4)&&tp_dev.y[0]>(lcddev.height*0.75)){R9();}//���
				else if(tp_dev.x[0]<(lcddev.width*0.15*5)&&tp_dev.y[0]>(lcddev.height*0.75)){R0();}//���					   
			}
		}else delay_ms(10);	//û�а������µ�ʱ�� 	    
		i++;
		if(i%20==0)LED.LED_Flip(LED1);

}
//���ݴ��������Ժ���
void ctp_test2(void)//��ʼ����ѡ��
{
	u8 t=0;
	u8 i=0;	  	    
 	u16 lastpos[5][2];		//���һ�ε����� 

		tp_dev.scan(0);
		for(t=0;t<5;t++)
		{
			if((tp_dev.sta)&(1<<t))
			{
                //printf("X����:%d,Y����:%d\r\n",tp_dev.x[0],tp_dev.y[0]);
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
                    
//					lcd_draw_bline(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//����
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*1){R1();}//����1
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*2){R2();}//����2
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*3){R3();}//����3
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*4){R4();}//����4
					else if(tp_dev.x[t]>(lcddev.width*0.75)&&tp_dev.y[t]<(lcddev.height*0.2)*5){R5();}//����5
					else if(tp_dev.x[0]<(lcddev.width*0.15*1)&&tp_dev.y[0]>(lcddev.height*0.75)){R6();}
					else if(tp_dev.x[0]<(lcddev.width*0.15*2)&&tp_dev.y[0]>(lcddev.height*0.75)){R7();}//���
					else if(tp_dev.x[0]<(lcddev.width*0.15*3)&&tp_dev.y[0]>(lcddev.height*0.75)){R8();}//���
					else if(tp_dev.x[0]<(lcddev.width*0.15*4)&&tp_dev.y[0]>(lcddev.height*0.75)){R9();}//���
					else if(tp_dev.x[0]<(lcddev.width*0.15*5)&&tp_dev.y[0]>(lcddev.height*0.75)){R0();}//���
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		delay_ms(5);i++;
		if(i%20==0)LED.LED_Flip(LED1);
	
}







