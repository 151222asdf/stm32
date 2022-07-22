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
    HAL_Init();                   	//��ʼ��HAL��    
	delay_init(168);               	//��ʼ����ʱ����
	LCD_Init();						//TFT��ʼ��
	tp_dev.init();				    //��������ʼ�� 	

}

/********************************************************
  End Of File
********************************************************/
