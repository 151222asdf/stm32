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
		default:printf("���� - �ⲿ�жϻص������У�����������ֵ����\r\n\r\n");
	}
}
/*
	* @name   HAL_TIM_PeriodElapsedCallback
	* @brief  ��ʱ���жϻص�����
	* @param  *htim -> ����ʱ���Ľṹ��ָ��
	* @retval None      
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == htim6.Instance)
	{
		//����֧�����У�ָʾ�Ƽ��1s��˸
		if(++Timer6.usMCU_Run_Timer >= TIMER0_10mS)
		{
			Timer6.usMCU_Run_Timer = 0;//��¼ѭ������
			lv_tick_inc(10);			// ���������������������1����1ms��ͨ����������1�����ж�һ�εĶ�ʱ���жϴ�����
			tp_dev.scan(10);
			lv_task_handler();		// ���������������LVGL�Ĺ�����ÿ����һ�Σ��������ִ��һ�Ρ�
			LED.LED_Flip(LED1);
		}
	}
}
/*
	* @name   HAL_ADC_ConvCpltCallback
	* @brief  ADC_DMA�����жϻص�����
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
	* @brief  ���ڽ����жϻص�����
	* @param  None
	* @retval None      
*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)  
{
	UNUSED(huart);
	
    if(huart->Instance == USART1)//�жϴ��ں�
    {
        HAL_UART_Transmit(&huart1,(uint8_t *)&rx_buffer,1,100); // �����յ���������ͨ�����ڷ��ͳ�ȥ
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_buffer, 1);   //����ʹ�ܽ����ж�
    }
}


/********************************************************
  End Of File
********************************************************/
