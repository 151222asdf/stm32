/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Peripheral_Set(void); 

/* Public variables-----------------------------------------------------------*/
MyInit_t MyInit = 
{
	Peripheral_Set
};

/* Private function prototypes------------------------------------------------*/      


/*
	* @name   Peripheral_Set
	* @brief  ��������
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
  HAL_Init();                  	  															//��ʼ��HAL��    
	delay_init(168);               																//��ʼ����ʱ����
	Timer6.Timer6_Start_IT();																			//������ʱ��
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)&InBufArray,2048);				//ADC_DMA����
	LCD_Init();																										//TFT��ʼ��
	tp_dev.init();				    																		//��������ʼ�� 	
	lv_init();																										//LVGL����ʼ��
	lv_port_disp_init();																					//�ƶ���ʼ��
	lv_port_indev_init();																					//����������
	OscMainInterface();																						//ʾ��������
}

/********************************************************
  End Of File
********************************************************/
