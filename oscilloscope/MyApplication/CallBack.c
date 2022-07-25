/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Public variables-----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/      
/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case KEY1_Pin: KEY1.KEY_Flag = TRUE;	break;
		case KEY2_Pin: KEY2.KEY_Flag = TRUE;	break;
		default:printf("错误 - 外部中断回调函数中，触摸按键键值错误！\r\n\r\n");
	}
}
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
/*
	* @name   HAL_ADC_ConvCpltCallback
	* @brief  ADC_DMA传输中断回调函数
	* @param  None
	* @retval None      
*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)  
{ 
	HAL_TIM_Base_Stop(&htim8);
	LED.LED_Flip(LED2);
	TransferComplete=1;
}
/*
	* @name   HAL_UART_RxCpltCallback
	* @brief  串口接收中断回调函数
	* @param  None
	* @retval None      
*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)  
{
	UNUSED(huart);
	
    if(huart->Instance == USART1)//判断串口号
    {
        HAL_UART_Transmit(&huart1,(uint8_t *)&rx_buffer,1,100); // 将接收到的数据再通过串口发送出去
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_buffer, 1);   //重新使能接收中断
    }
}


/********************************************************
  End Of File
********************************************************/
