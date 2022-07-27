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
	* @brief  ��������
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
		printf("��ʼ����\r\n");
    /** SPIͨ�ų�ʼ�� **/
    SPI_Configuration();
    /** FIFOͨ�ų�ʼ�� **/
    Read_From_FPGA_GPIO_Init();
}

/********************************************************
  End Of File
********************************************************/
