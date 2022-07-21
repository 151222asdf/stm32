/**
  ******************************************************************************
  * @file           : FpgaSPI.h
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/10
  ******************************************************************************
  */

#ifndef PORTINGFPGASPI_FPGASPI_H
#define PORTINGFPGASPI_FPGASPI_H
/**************************************************************
 ***                  还未增加硬件SPI支持
 ***                  FIFO时钟引脚可达到19MHz
 *** //TODO:完善Fpga和STM32 SPI通信库  目标:更加通用——添加硬件SPI支持
 **************************************************************/

/**********************头文件引入**********************/
#include "stm32f4xx.h"
#include "stdint.h"
/************************************************宏定义************************************************/
/**********************使用OS**********************/
#define USE_OS_WITH_FPGA_STM32                   0
#if USE_OS_WITH_FPGA_STM32
/***********下面以FreeRTOS为例子，可更换为其他的操作系统临界段***********/
#include "FreeRTOS.h"
#include "task.h"
#define  OS_CRITICAL_SECTION_ENTER()            taskENTER_CRITICAL()
#define  OS_CRITICAL_SECTION_EXIT()             taskEXIT_CRITICAL()
#endif
/*****************使用硬件SPI时修改为 1*****************/
#define USE_FPGA_HARDWARE_SPI                     0
#if USE_FPGA_HARDWARE_SPI
#define USE_HARDWARE_SPI_X                        1
/*****************在文件首部声明此宏定义 会自动定义*****************/
#define USE_HARDWARE_SPI(USE_HARDWARE_SPI_X)      extern SPI_HandleTypeDef hspi##x
/*****************SPI句柄 支持多SPI*****************/
#define FpgaSPI(USE_HARDWARE_SPI_X)                   hspi##x
/*****************SPI头文件*****************/
#include "spi.h"
#endif

/***********定义发送数据的宽度***********/
#define    SPI_DATA_WIDTH 32
#if (SPI_DATA_WIDTH == 32)
    #define SPI_DATA_WIDTH_GET    0X80000000
#elif (SPI_DATA_WIDTH == 16)
    #define SPI_DATA_WIDTH_GET    0X00008000
#elif (SPI_DATA_WIDTH == 8)
    #define SPI_DATA_WIDTH_GET    0X000000080
#endif
/***********地址位宽***********/
#define    SPI_CMD_WIDTH  8
#if (SPI_CMD_WIDTH == 32)
#define SPI_CMS_WIDTH_GET        0X80000000
#elif (SPI_CMD_WIDTH == 16)
#define SPI_CMS_WIDTH_GET        0X00008000
#elif (SPI_CMD_WIDTH == 8)
    #define SPI_CMS_WIDTH_GET    0X00000080
#endif
/*************************************** FpgaSPI IO 操作 ***************************************/
#if (!USE_FPGA_HARDWARE_SPI)
#define FPGA_SPI_CS_CMD_Port       GPIOF
#define FPGA_SPI_CS_CMD_Pin        GPIO_PIN_0

#define FPGA_SPI_CS_DATA_Port      GPIOF
#define FPGA_SPI_CS_DATA_Pin       GPIO_PIN_1

#define FPGA_SPI_MOSI_Port         GPIOF
#define FPGA_SPI_MOSI_Pin          GPIO_PIN_3

#define FPGA_SPI_MISO_Port         GPIOF
#define FPGA_SPI_MISO_Pin          GPIO_PIN_2

#define FPGA_SPI_SCLK_Port         GPIOF
#define FPGA_SPI_SCLK_Pin          GPIO_PIN_4
/** 片选命令,FPGA(spi_cs_Cmd) **/
#define CS_CMD_Set        HAL_GPIO_WritePin(FPGA_SPI_CS_CMD_Port,  FPGA_SPI_CS_CMD_Pin,   GPIO_PIN_SET)
#define CS_CMD_Clr        HAL_GPIO_WritePin(FPGA_SPI_CS_CMD_Port,  FPGA_SPI_CS_CMD_Pin,   GPIO_PIN_RESET)
/** 片选数据cs_data **/
#define CS_DATA_Set       HAL_GPIO_WritePin(FPGA_SPI_CS_DATA_Port, FPGA_SPI_CS_DATA_Pin,  GPIO_PIN_SET)
#define CS_DATA_Clr       HAL_GPIO_WritePin(FPGA_SPI_CS_DATA_Port, FPGA_SPI_CS_DATA_Pin,  GPIO_PIN_RESET)
/** 数据线:单片机输入,FPGA输出(spi_sdo) **/
#define SPI_FPGA_MOSI_Set HAL_GPIO_WritePin(FPGA_SPI_MOSI_Port,    FPGA_SPI_MOSI_Pin,     GPIO_PIN_SET)
#define SPI_FPGA_MOSI_Clr HAL_GPIO_WritePin(FPGA_SPI_MOSI_Port,    FPGA_SPI_MOSI_Pin,     GPIO_PIN_RESET)
/** 数据线:单片机输出,FPGA输入(spi_sdi) **/
#define SPI_FPGA_MISO     HAL_GPIO_ReadPin (FPGA_SPI_MISO_Port,    FPGA_SPI_MISO_Pin)
/** 时钟线,FPGA(spi_scl) **/
#define SPI_FPGA_SCL_Set  HAL_GPIO_WritePin(FPGA_SPI_SCLK_Port,    FPGA_SPI_SCLK_Pin,     GPIO_PIN_SET)
#define SPI_FPGA_SCL_Clr  HAL_GPIO_WritePin(FPGA_SPI_SCLK_Port,    FPGA_SPI_SCLK_Pin,     GPIO_PIN_RESET)
#endif

/************************** 函数声明 **************************/
/*************FpgaSPI IO配置*************/
static void GPIO_SPI_Configuration();
/************* FpgaSPI 配置 *************/
void     SPI_Configuration();
/************* SPI读写函数 **************/
void     SPI_Send_Data(uint32_t Send_Data);
void     SPI_Send_Cmd(uint8_t Send_Data);
uint32_t SPI_Rece_Data(void);
void     SPI_Send_Cmd_Data(uint8_t Cmd,uint32_t Send_Data);
uint32_t SPI_Rece_Cmd_Data(uint8_t Cmd);

#endif //PORTINGFPGASPI_FPGASPI_H
