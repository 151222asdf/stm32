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
	printf("----此程序实现串口打印功能----\r\n");
	printf("Initialization completed, system startup!\r\n");
	printf("Software version is V%.1f\r\n\r\n",SoftWare_Version);
	
	printf("开始运行有限状态机:\r\n\r\n");
}

/********************************************************
  End Of File
********************************************************/
