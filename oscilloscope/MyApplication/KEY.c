/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/
static void KEY1_Detect(void);   //��������1���
static void KEY2_Detect(void);   //��������2���


/* Public variables-----------------------------------------------------------*/
//�ṹ�嶨��
KEY_t  KEY1 = {FALSE,FALSE,FALSE,KEY1_Detect};      
KEY_t  KEY2 = {FALSE,FALSE,FALSE,KEY2_Detect}; 


/*
	* @name   KEY1_Detect
	* @brief  ��������1���
	* @param  None
	* @retval None      
*/
static void KEY1_Detect() 
{	
	if(KEY1.KEY_Flag == TRUE)
	{
		KEY1.Click = FALSE;
		KEY1.Press = TRUE;
		//���������������

		//�������״̬
		KEY1.KEY_Flag = FALSE;
		KEY1.Click = FALSE;
		KEY1.Press = FALSE;
	}
}

/*
	* @name   KEY2_Detect
	* @brief  ��������1���
	* @param  None
	* @retval None      
*/
static void KEY2_Detect() 
{
	if(KEY2.KEY_Flag == TRUE)
	{
		KEY2.Click = FALSE;
		KEY2.Press = TRUE;
		//���������������

		//�������״̬
		KEY2.KEY_Flag = FALSE;
		KEY2.Click = FALSE;
		KEY2.Press = FALSE;
	}
}


/********************************************************
  End Of File
********************************************************/
