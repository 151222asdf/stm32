/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

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
union
{
 
  struct
  {
    uint8_t com[4];
  }ComInfo;
	
	float data;
	
}D_data;
/*
	* @name   Run
	* @brief  ϵͳ����
	* @param  None
	* @retval None      
*/
static void Run()
{
		/*******�򿪴����ж����Խ�������***********/
		HAL_UART_Receive_IT(&huart1,(uint8_t*)RxBuffer,1);
    /*******���Ͳ�����***********/
    SPI_Send_Cmd_Data(FPGA_CHANNEL_SMAP,4);
    /*******���Ͳ�������*********/
    SPI_Send_Cmd_Data(FPGA_CHANNEL_SMAP_POINT,2048);
    /*******���ʹ�����ƽ*********/
    SPI_Send_Cmd_Data(FPGA_CHANNEL_TRI_VOL,127);
    /*******FIFO����*********/
    SPI_Send_Cmd_Data(FPGA_CHANNEL_FIFO,       OSC_DISABLE);
    SPI_Send_Cmd_Data(FPGA_CHANNEL_FIFO,       OSC_ENABLE);
		/*******���뻺��ʱ��*********/
		HAL_Delay(5);
    /*******Ƭѡ�ź� ʹ��*******/
    SPI_Send_Cmd_Data(FPGA_CHANNEL_CS, OSC_ENABLE);
    /*******�ȴ������źŲ���*******/
    while (SAMPLE_END_Read_From_FPGA() != 15) {
			static int i = 0;
			for (i = 0; i < 10; i++) {
				HAL_Delay(10);
			}
			if (i >= 10) {
				i = 0;
				break;
			}
		}
		/*******Ƭѡ�ź�-ʧ��*******/
    SPI_Send_Cmd_Data(FPGA_CHANNEL_CS, OSC_DISABLE);
    /******��ȡ��������********/
		for(int i=0;i<2048;i++)
		{
			FPGA_ADC[i]=(uint16_t)MCU_Read_From_FPGA()*2;
		}
		cfft_f32_mag();
}

/*
	* @name   Error_Handler
	* @brief  ϵͳ������
	* @param  None
	* @retval None      
*/
static void Error_Handler()
{
	/* User can add his own implementation to report the HAL error return state */
}

/*
	* @name   Assert_Failed
	* @brief  ��������������
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
