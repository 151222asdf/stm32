/**
  ******************************************************************************
  * @file           : TaskInclude.h
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/6/29
  ******************************************************************************
  */

#ifndef ENDOSCILLOSCOPE_TASKINCLUDE_H
#define ENDOSCILLOSCOPE_TASKINCLUDE_H

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "event_groups.h"

#include "lvgl.h"
#include "driver/lv_port_disp.h"
#include "driver/lv_port_indev.h"
#include "driver/lv_port_fs.h"



#include "stdio.h"
#include "stdint.h"

#include "LCD.h"
#include "FpgaSPI.h"
#include "FpgaFiFoData.h"

#include "OscInterface.h"
#include "cmsis_os.h"

#include "arm_math.h"

/**继电器控制**/
#define RELAY_PRESS                        HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_SET)
#define RELAY_RELEASE                      HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET)

extern osThreadId fTaskLvglHandle;
extern osThreadId fTaskInterfaceHandle;
extern osThreadId fTaskDataProcessHandle;
extern osThreadId fTaskKeyScanHandle;
extern SemaphoreHandle_t xMutexDataProcess;

#endif //ENDOSCILLOSCOPE_TASKINCLUDE_H
