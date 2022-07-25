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
	* @brief  外设设置
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
  HAL_Init();                  	  															//初始化HAL库    
	delay_init(168);               																//初始化延时函数
	Timer6.Timer6_Start_IT();																			//开启定时器
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)&InBufArray,2048);				//ADC_DMA采样
	LCD_Init();																										//TFT初始化
	tp_dev.init();				    																		//触摸屏初始化 	
	lv_init();																										//LVGL屏初始化
	lv_port_disp_init();																					//移动初始化
	lv_port_indev_init();																					//触摸屏开启
	OscMainInterface();																						//示波器界面
}

/********************************************************
  End Of File
********************************************************/
