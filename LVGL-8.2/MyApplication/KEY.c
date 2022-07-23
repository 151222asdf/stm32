/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/
static void KEY1_Detect(void);   //´¥Ãþ°´¼ü1¼ì²â
static void KEY2_Detect(void);   //´¥Ãþ°´¼ü2¼ì²â


/* Public variables-----------------------------------------------------------*/
//½á¹¹Ìå¶¨Òå
KEY_t  KEY1 = {FALSE,FALSE,FALSE,KEY1_Detect};      
KEY_t  KEY2 = {FALSE,FALSE,FALSE,KEY2_Detect}; 


/*
	* @name   KEY1_Detect
	* @brief  ´¥Ãþ°´¼ü1¼ì²â
	* @param  None
	* @retval None      
*/
static void KEY1_Detect() 
{	
	if(KEY1.KEY_Flag == TRUE)
	{
		KEY1.Click = FALSE;
		KEY1.Press = TRUE;
		//´¥Ãþ°´¼ü³¤°´¼ì²â

		//Çå³ý°´¼ü×´Ì¬
		KEY1.KEY_Flag = FALSE;
		KEY1.Click = FALSE;
		KEY1.Press = FALSE;
	}
}

/*
	* @name   KEY2_Detect
	* @brief  ´¥Ãþ°´¼ü1¼ì²â
	* @param  None
	* @retval None      
*/
static void KEY2_Detect() 
{
	if(KEY2.KEY_Flag == TRUE)
	{
		KEY2.Click = FALSE;
		KEY2.Press = TRUE;
		//´¥Ãþ°´¼ü³¤°´¼ì²â

		//Çå³ý°´¼ü×´Ì¬
		KEY2.KEY_Flag = FALSE;
		KEY2.Click = FALSE;
		KEY2.Press = FALSE;
	}
}


/********************************************************
  End Of File
********************************************************/
