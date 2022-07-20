/**
  ******************************************************************************
  * @file           : FpgaFiFoData.c
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/11
  ******************************************************************************
  */

#include <stdio.h>
#include "FpgaFiFoData.h"
#include "OscDefine.h"

void Read_From_FPGA_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /** GPIO Ports Clock Enable **/
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    GPIO_InitStruct.Pin     = READ_FIFO_SCLK_Pin ;
    GPIO_InitStruct.Speed   = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Mode    = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(READ_FIFO_SCLK_Port, &GPIO_InitStruct);
#if USE_SPI_FIFO_SAMPLE_END
    GPIO_InitStruct.Pin     = SAMPLE_END_Pin;
    GPIO_InitStruct.Mode    = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull    = GPIO_PULLUP;
    HAL_GPIO_Init(SAMPLE_END_Port, &GPIO_InitStruct);
#endif
}

uint32_t MCU_Read_From_FPGA(void) {
    uint32_t fifo_data;
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_ENTER();
#endif
    /** 控制读取时钟 **/
    READ_FIFO_SCLK_Clear;
    READ_FIFO_SCLK_Set;
    fifo_data = SPI_Rece_Cmd_Data(FPGA_CHANNEL_WAVE_RECEIVE);
//    printf("%d\n", fifo_data);
    READ_FIFO_SCLK_Clear;
    READ_FIFO_SCLK_Set;
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_EXIT();
#endif
    return fifo_data;
}

uint32_t SAMPLE_END_Read_From_FPGA(void) {
    uint32_t fifo_data;
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_ENTER();
#endif
/** 控制读取时钟 **/
    READ_FIFO_SCLK_Clear;
    READ_FIFO_SCLK_Set;
    fifo_data = SPI_Rece_Cmd_Data(FPGA_CHANNEL_RECEIVE);
    READ_FIFO_SCLK_Clear;
    READ_FIFO_SCLK_Set;
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_EXIT();
#endif
//    printf("sample end signal value :%ld\n", fifo_data);
    return fifo_data;
}
