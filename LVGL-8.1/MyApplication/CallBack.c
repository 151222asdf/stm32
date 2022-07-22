/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Public variables-----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/      
/*
	* @name   HAL_TIM_PeriodElapsedCallback
	* @brief  定时器中断回调函数
	* @param  *htim -> 处理定时器的结构体指针
	* @retval None      
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == htim6.Instance)
	{
		//程序支持运行，指示灯间隔1s闪烁
		if(++Timer6.usMCU_Run_Timer >= TIMER0_10mS)
		{
			Timer6.usMCU_Run_Timer = 0;//记录循环次数
			lv_tick_inc(10);			// 这个函数设置心跳，参数1代表1ms。通常将他放在1毫秒中断一次的定时器中断处理中
			tp_dev.scan(10);
			lv_task_handler();		// 这个函数用来处理LVGL的工作，每心跳一次，这里面就执行一次。
			LED.LED_Flip(LED1);
		}
	}
}
/********************************************************
  End Of File
********************************************************/
