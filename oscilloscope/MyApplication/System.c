/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/
uint16_t x=0;
/* Private variables----------------------------------------------------------*/
static void Run(void); 
static void Error_Handler(void);
static void Assert_Failed(void);

/* Public variables-----------------------------------------------------------*/
System_t System = 
{
	Run,
	Error_Handler,
	Assert_Failed
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Run
	* @brief  系统运行
	* @param  None
	* @retval None      
*/
static void Run() 
{
	if(	TransferComplete==1)
	{
			TransferComplete=0;
      for (int i=0;i<2048;i++) 
			{
					x=(uint16_t)InBufArray[i];
          lv_chart_set_next_value(OscScreen.Chart.obj, OscScreen.Chart.waveSeries, x);
					printf("line=%d\r\n",(uint16_t)InBufArray[i]);
          lv_chart_refresh(OscScreen.Chart.obj);
      }			
			HAL_TIM_Base_Start(&htim8);
	} 
}

/*
	* @name   Error_Handler
	* @brief  系统错误处理
	* @param  None
	* @retval None      
*/
static void Error_Handler()
{
	/* User can add his own implementation to report the HAL error return state */
}

/*
	* @name   Assert_Failed
	* @brief  函数参数错误处理
	* @param  None
	* @retval None      
*/
static void Assert_Failed()
{
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
/********************************************************
  End Of File
********************************************************/
