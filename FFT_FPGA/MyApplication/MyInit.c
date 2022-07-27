/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/
uint16_t FPGA_ADC[2048]={0};
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
		printf("开始测试\r\n");
    /** SPI通信初始化 **/
    SPI_Configuration();
    /** FIFO通信初始化 **/
    Read_From_FPGA_GPIO_Init();
}

/********************************************************
  End Of File
********************************************************/
