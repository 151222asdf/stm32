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
	printf("----�˳���ʵ�ִ��ڴ�ӡ����----\r\n");
	printf("Initialization completed, system startup!\r\n");
	printf("Software version is V%.1f\r\n\r\n",SoftWare_Version);
	
	printf("��ʼ��������״̬��:\r\n\r\n");
}

/********************************************************
  End Of File
********************************************************/
