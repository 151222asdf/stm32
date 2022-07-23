/**
  ******************************************************************************
  * @file           : OscBtnCallBack.c
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/10
  ******************************************************************************
  */
#include "OscInterface.h"
#include "OscDefine.h"

/**
  * @brief  水平灵敏度回调函数
  * @note   None
  * @param  None
  * @retval None
  */
void horBtnCallback(lv_event_t *e) {
    static int clicked = OSC_BTN_FIRST_PRESSED;
    if (clicked == OSC_BTN_FIRST_PRESSED) {

        clicked++;
    }else if (clicked == OSC_BTN_SECOND_PRESSED) {

        clicked++;
    }else if (clicked == OSC_BTN_THIRD_PRESSED) {

        clicked = OSC_BTN_FIRST_PRESSED;
    }
}

/**
  * @brief  垂直灵敏度调节按键回调函数
  * @note   None
  * @param  None
  * @retval None
  */
void verBtnCallback(lv_event_t *e) {
    static int clicked = OSC_BTN_FIRST_PRESSED;
    if (clicked == OSC_BTN_FIRST_PRESSED) {
        clicked++;
    } else if (clicked == OSC_BTN_SECOND_PRESSED) {
        clicked++;
    } else if (clicked == OSC_BTN_THIRD_PRESSED) {
        clicked = OSC_BTN_FIRST_PRESSED;
    }
}

/**
  * @brief  触发调节
  * @note   None
  * @param  None
  * @retval None
  */
void triBtnCallback(lv_event_t *e) {
//    lv_obj_t *btnObj = lv_event_get_target(e);
//    if (btnObj == OscScreen.btnTriAdd) {
//        oscVar.keyStatus = OSC_KEY_PRESS;
//        oscVar.keyValue  = OSC_KEY_VALUE_TRI_ADD;
//    } else if (btnObj == OscScreen.btnTriSub) {
//        oscVar.keyStatus = OSC_KEY_PRESS;
//        oscVar.keyValue  = OSC_KEY_VALUE_TRI_SUB;
//    }
}

/**
  * @brief  保存波形数据
  * @note   None
  * @param  None
  * @retval None
  */
void saveBtnCallback (lv_event_t *e) {
   static int clicked = OSC_BTN_FIRST_PRESSED;
   if (clicked == OSC_BTN_FIRST_PRESSED) {
       clicked++;
   } else if (clicked == OSC_BTN_SECOND_PRESSED) {
       clicked++;
   } else if (clicked == OSC_BTN_THIRD_PRESSED) {
       clicked++;
   } else if (clicked == OSC_BTN_FOURTH_PRESSED) {
       clicked = OSC_BTN_FIRST_PRESSED;
   }
}
