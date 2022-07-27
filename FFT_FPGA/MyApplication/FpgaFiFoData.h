/**
  ******************************************************************************
  * @file           : FpgaFiFoData.h
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/11
  ******************************************************************************
  */
#ifndef PORTINGFPGASPI_FPGAFIFODATA_H
#define PORTINGFPGASPI_FPGAFIFODATA_H

#include "FpgaSPI.h"

#define READ_FIFO_SCLK_Port     GPIOE
#define READ_FIFO_SCLK_Pin      GPIO_PIN_2

#define READ_FIFO_SCLK_Clear    HAL_GPIO_WritePin(READ_FIFO_SCLK_Port, READ_FIFO_SCLK_Pin, GPIO_PIN_RESET)
#define READ_FIFO_SCLK_Set      HAL_GPIO_WritePin(READ_FIFO_SCLK_Port, READ_FIFO_SCLK_Pin, GPIO_PIN_SET)

#define USE_SPI_FIFO_SAMPLE_END     0

#define SAMPLE_END_Port         GPIOF
#define SAMPLE_END_Pin          GPIO_PIN_5
#define SAMPLE_END_READ         HAL_GPIO_ReadPin(SAMPLE_END_Port, SAMPLE_END_Pin)

void Read_From_FPGA_GPIO_Init(void);
uint32_t MCU_Read_From_FPGA(void);
uint32_t SAMPLE_END_Read_From_FPGA(void);

#endif //PORTINGFPGASPI_FPGAFIFODATA_H
