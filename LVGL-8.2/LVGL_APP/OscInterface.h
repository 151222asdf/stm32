/**
  ******************************************************************************
  * @file           : OscInterface.h
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/7
  ******************************************************************************
  */

#ifndef FINALLYOSCILLOSCOPE_OSCINTERFACE_H
#define FINALLYOSCILLOSCOPE_OSCINTERFACE_H
#include "lvgl.h"
#include "OscStyle.h"

/*******************颜色宏定义*******************/
#define OSC_COLOR_BLACK                 0X373737
#define OSC_COLOR_YELLOW                0Xffff00
#define OSC_COLOR_GREEN_LIGHT           0X59A869
#define OSC_COLOR_BLUE_LIGHT            0X40b6e0
#define OSC_COLOR_PINK_LIGHT            0Xf6b4c0
#define OSC_COLOR_RED_DEEP              0X993300
/*******************示波器枚举变量*******************/
enum {
    /*****第一次也代表按键最初值*****/
    OSC_BTN_FIRST_PRESSED    = 0u,
    OSC_BTN_SECOND_PRESSED   = 1u,
    OSC_BTN_THIRD_PRESSED    = 2u,
    OSC_BTN_FOURTH_PRESSED   = 3u,
};

typedef struct {
    lv_obj_t                *obj;
    uint16_t                 hDiv;
    uint16_t                 vDiv;
    lv_chart_series_t       *spectrumSeries;
    lv_chart_series_t       *waveSeries;
    lv_coord_t               pointCnt;
    lv_coord_t               width;
    lv_coord_t               height;
    lv_point_t               axis;
    lv_chart_update_mode_t   updateMode : 1;
}OscChart_t;

typedef struct {
    /** 图表 **/
    OscChart_t          Chart;
    lv_style_t          ChartStyle;

    /** 按键 **/
    lv_obj_t           *btnVer;
    lv_obj_t           *btnHor;
    lv_obj_t           *btnTriAdd;
    lv_obj_t           *btnTriSub;
    lv_obj_t           *btnSave;

    /** 按键标签 **/
    lv_obj_t           *labelVerBtn;
    lv_obj_t           *labelHorBtn;
    lv_obj_t           *labelTriAddBtn;     /** 触发等级加 **/
    lv_obj_t           *labelTriSubBtn;     /** 触发等级减 **/
    lv_obj_t           *labelSaveBtn;

    /** 数值标签 **/
    lv_obj_t           *labelFre;
    lv_obj_t           *labelMAXVol;
    lv_obj_t           *labelTrigger;
    lv_style_t          MixLabelStyle;
    /** 触发电压 **/
    lv_obj_t           *triggerVol;
}OscScreen_t;

/***************标签数据***************/
extern double     dataFreLabelDouble;
extern double     dataFreLabelDouble;
extern uint16_t   dataTriggerInt;

extern OscScreen_t  OscScreen;

/***************函数声明***************/
void OscChartCallBack(lv_event_t * e);
void OscMainInterface();
#endif //FINALLYOSCILLOSCOPE_OSCINTERFACE_H
