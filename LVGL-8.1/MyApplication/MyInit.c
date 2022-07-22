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
	* @brief  Õ‚…Ë…Ë÷√
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
	delay_init(168);
	Timer6.Timer6_Start_IT();
	LCD_Init();
	LCD_Clear(RED);
  tp_dev.init();
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	//test_start();
	OscMainInterface();
	HAL_Delay(1000);
}

/********************************************************
  End Of File
********************************************************/
