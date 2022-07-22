#ifndef _408_H_
#define _408_H_
#include "lvgl/lvgl.h"
#include "OscStyle.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OSC_COLOR_BLACK                 0X373737
#define OSC_COLOR_YELLOW                0Xffff00
#define OSC_COLOR_GREEN_LIGHT           0X59A869
#define OSC_COLOR_BLUE_LIGHT            0X40b6e0
#define OSC_COLOR_PINK_LIGHT            0Xf6b4c0
#define OSC_COLOR_RED_DEEP              0X993300

typedef struct {
    lv_obj_t* obj;
    uint16_t                 hdiv;
    uint16_t                 vdiv;
    lv_chart_series_t* spectrumSeries;
    lv_chart_series_t* waveSeries;
    lv_coord_t               pointCnt;
    lv_coord_t               width;
    lv_coord_t               height;
    lv_point_t               axis;
    lv_chart_update_mode_t   updateMode : 1;
}OscChart_t;

typedef struct {
    /** ͼ�� **/
    OscChart_t          Chart;
    lv_style_t          ChartStyle;

    /** ���� **/
    lv_obj_t* btnVer;
    lv_obj_t* btnHor;
    lv_obj_t* btnTri;
    lv_obj_t* btnRS;
    lv_obj_t* btnDAC;

    /** ������ǩ **/
    lv_obj_t* labelVerBtn;
    lv_obj_t* labelHorBtn;
    lv_obj_t* labelTriBtn;
    lv_obj_t* labelRSBtn;
    lv_obj_t* labelDACBtn;

    /** ��ֵ��ǩ **/
    lv_obj_t* labelFre;
    lv_obj_t* labelMAXVol;
    lv_obj_t* labelTrigger;
    lv_style_t          MixLabelStyle;
    /** ������ѹ **/
    lv_obj_t* triggerVol;
}OscScreen_t;

/***************��ǩ����***************/
extern double dataFreLabelDouble;
extern double dataFreLabelDouble;
extern int    dataTriggerInt;

extern OscScreen_t  OscScreen;

/***************��������***************/
void OscChartCallBack(lv_event_t* e);
static void OscChartVarInit();
void OscMainInterface();
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif


