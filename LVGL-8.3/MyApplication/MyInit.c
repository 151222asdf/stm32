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
    HAL_Init();                   	//初始化HAL库    
	delay_init(168);               	//初始化延时函数
	LCD_Init();						//TFT初始化
	tp_dev.init();				    //触摸屏初始化 	

}

/********************************************************
  End Of File
********************************************************/
