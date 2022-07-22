/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Public variables-----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/      
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
/********************************************************
  End Of File
********************************************************/
