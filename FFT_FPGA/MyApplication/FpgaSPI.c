/**
  ******************************************************************************
  * @file           : FpgaSPI.c
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/10
  ******************************************************************************
  */
#include "FpgaSPI.h"

#if USE_FPGA_HARDWARE_SPI
USE_HARDWARE_SPI(1);
#endif

/**
  * @brief  SPI配置
  * @note   None
  * @param  SPIx    指定SPI
  * @retval None
  */
void SPI_Configuration() {
    GPIO_SPI_Configuration();
}

/**
  * @brief  SPI2 IO配置
  * @note
  *         模拟SPI
  *         引脚连接
  *         FpgaSPI SEL
  *         FpgaSPI CS
  *         FpgaSPI SCK
  *         FpgaSPI MISO
  *         FpgaSPI MOSI
  * @param  None
  * @retval None
  */
static void GPIO_SPI_Configuration(void) {
#if (!USE_FPGA_HARDWARE_SPI)
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    /** GPIO Ports Clock Enable **/
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    GPIO_InitStruct.Pin =   FPGA_SPI_MOSI_Pin;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    /** 使用GPIO模拟的引脚配置 **/
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /** 推挽输出 **/
    HAL_GPIO_Init(FPGA_SPI_MOSI_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin =   FPGA_SPI_CS_DATA_Pin;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    /** 使用GPIO模拟的引脚配置 **/
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /** 推挽输出 **/
    HAL_GPIO_Init(FPGA_SPI_CS_DATA_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = FPGA_SPI_CS_CMD_Pin;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    /** 使用GPIO模拟的引脚配置 **/
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /** 推挽输出 **/
    HAL_GPIO_Init(FPGA_SPI_CS_CMD_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = FPGA_SPI_SCLK_Pin;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    /** 使用GPIO模拟的引脚配置 **/
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /** 推挽输出 **/
    HAL_GPIO_Init(FPGA_SPI_SCLK_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin =  FPGA_SPI_MISO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
    HAL_GPIO_Init(FPGA_SPI_MISO_Port, &GPIO_InitStruct);

    SPI_FPGA_MOSI_Set;
    SPI_FPGA_SCL_Set;
    CS_CMD_Set;
    CS_DATA_Set;
#endif
}

/**
  * @brief  FpgaSPI 发送命令
  * @note   None
  * @param  Send_Data      发送命令(8位)
  * @retval None
  */
void SPI_Send_Cmd(uint8_t Send_Data) {
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_ENTER();
#endif
#if USE_FPGA_HARDWARE_SPI
    HAL_SPI_Transmit(&FpgaSPI(USE_HARDWARE_SPI_X), &Send_Data, 1, 100);
#else
    uint8_t i;
    CS_CMD_Clr; // 片选选中
    for (i = 0; i < SPI_CMD_WIDTH; i++) {
        if ((Send_Data & 0x80) == 0x80) {
            SPI_FPGA_MOSI_Set;
        }else {
            SPI_FPGA_MOSI_Clr;
        }
        Send_Data <<= 1; // 高位在前
        SPI_FPGA_SCL_Clr;
        SPI_FPGA_SCL_Set; // 上升沿发送数据
    }
    CS_CMD_Set; // 片选拉高
#endif
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_EXIT();
#endif
}

/**
  * @brief  FpgaSPI 发送数据
  * @note   None
  * @param  Send_Data       发送数据
  * @retval None
  */
void SPI_Send_Data(uint32_t Send_Data) {
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_ENTER();
#endif
    /** 片选选中 **/
    CS_DATA_Clr;
#if USE_FPGA_HARDWARE_SPI
    uint8_t sendData[5] = {0};
    uint8_t sendData[0] = (uint8_t)(Send_Data>>24);
    uint8_t sendData[1] = (uint8_t)(Send_Data>>16);
    uint8_t sendData[2] = (uint8_t)(Send_Data>>8);
    uint8_t sendData[3] = (uint8_t)Send_Data;
    HAL_SPI_Transmit(&FpgaSPI(USE_HARDWARE_SPI_X), &Send_Data, 1, 100);
#else
    uint8_t i;
    for (i = 0; i < SPI_DATA_WIDTH; i++) {
        if ((Send_Data & SPI_DATA_WIDTH_GET) == SPI_DATA_WIDTH_GET) {
            SPI_FPGA_MOSI_Set;
        } else {
            SPI_FPGA_MOSI_Clr;
        }
        /** 高位在前 **/
        Send_Data <<= 1;
        SPI_FPGA_SCL_Clr;
        /** 上升沿发送数据 **/
        SPI_FPGA_SCL_Set;
    }
#endif
    CS_DATA_Set; // 片选拉高
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_EXIT();
#endif
}

/**
  * @brief  FpgaSPI 接收数据
  * @note   时钟是下降接收数据,片选下降沿有效
  * @param  None
  * @retval Data_Buf        4字节数据
  */
uint32_t SPI_Rece_Data(void) {
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_ENTER();
#endif
    /** 接收到得数据 **/
    uint32_t Data_Buf = 0;
    /** 片选选中 **/
    CS_DATA_Clr;
#if (USE_FPGA_HARDWARE_SPI == 1)

#else
    uint16_t i;
    for (i = 0; i < SPI_DATA_WIDTH; i++) {
        SPI_FPGA_SCL_Set;
        /** 下降沿接收数据 **/
        SPI_FPGA_SCL_Clr;
        /** 左移 **/
        Data_Buf <<= 1;
        /** 接收数据 **/
        Data_Buf = Data_Buf | SPI_FPGA_MISO;
    }
#endif
    /** 片选拉高 **/
    CS_DATA_Set;
#if USE_OS_WITH_FPGA_STM32
    OS_CRITICAL_SECTION_EXIT();
#endif
    return Data_Buf;
}

/**
  * @brief  SPI发送命令 发送数据
  * @note   None
  * @param  None
  * @retval None
  */
void SPI_Send_Cmd_Data(uint8_t Cmd, uint32_t Send_Data) {
    SPI_Send_Cmd(Cmd);
    SPI_Send_Data(Send_Data);
}

/**
  * @brief  FpgaSPI 发送接收函数
  * @note   None
  * @param  cmd                 要写的命令
  * @retval SPI2_Rece_Data()    返回函数调用
  */
uint32_t SPI_Rece_Cmd_Data(uint8_t cmd) {
    SPI_Send_Cmd(cmd);
    return (SPI_Rece_Data());
}
