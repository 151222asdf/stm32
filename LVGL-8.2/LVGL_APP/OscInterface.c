/**
 ******************************************************************************
  * @file           : OscInterface.c
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/7
  ******************************************************************************
  */
#include "OscInterface.h"
/**********************************主界面变量**********************************/
OscScreen_t OscScreen = {
        .Chart.hDiv       = 9,
        .Chart.vDiv       = 11,
        .Chart.pointCnt   = 500,
        .Chart.updateMode = LV_CHART_UPDATE_MODE_CIRCULAR,
        .Chart.axis.x     = 50,
        .Chart.axis.y     = 255,
        .Chart.width      = 230,
        .Chart.height     = 190,
};

double   dataMaxLabelDouble = 0.000;
double   dataFreLabelDouble = 0.0;
uint16_t dataTriggerInt     = 128;

/**********************************回调函数声明**********************************/
void horBtnCallback(lv_event_t *e);
void verBtnCallback(lv_event_t *e);
void triBtnCallback(lv_event_t *e);
void saveBtnCallback(lv_event_t *e);

/**
  * @brief  主界面构建
  * @note   None
  * @param  None
  * @retval None
  */
void OscMainInterface() {
    /***********************去掉滚动条***********************/
//    lv_obj_clear_flag(lv_scr_act(), LV_OBJ_FLAG_SCROLLABLE);
//    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(OSC_COLOR_BLACK), _LV_STYLE_STATE_CMP_SAME); //设置界面背景色
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0X1c1c1c), _LV_STYLE_STATE_CMP_SAME); //设置界面背景色
/***********************************************************图表***********************************************************/
    OscScreen.Chart.obj = lv_chart_create(lv_scr_act());
    lv_style_init(&OscScreen.ChartStyle); //样式初始化函数
    lv_style_set_bg_color      (&OscScreen.ChartStyle, lv_color_hex(OSC_COLOR_BLACK)); //设置背景色
    lv_style_set_border_side   (&OscScreen.ChartStyle, LV_BORDER_SIDE_FULL);//设置边
    lv_style_set_border_color  (&OscScreen.ChartStyle, lv_palette_lighten(LV_PALETTE_GREY, 1));
    lv_style_set_border_width  (&OscScreen.ChartStyle, 1); //设置边宽
    lv_style_set_radius        (&OscScreen.ChartStyle, 0); //设置圆角
    lv_style_set_pad_all       (&OscScreen.ChartStyle, 0); //设置边距
    lv_style_set_border_opa    (&OscScreen.ChartStyle, LV_OPA_40);
    lv_style_set_transform_zoom(&OscScreen.ChartStyle, 0);
    lv_chart_set_zoom_y        (OscScreen.Chart.obj, LV_IMG_ZOOM_NONE);
    lv_chart_set_zoom_x        (OscScreen.Chart.obj, LV_IMG_ZOOM_NONE);
    lv_obj_add_style           (OscScreen.Chart.obj , &OscScreen.ChartStyle, LV_STATE_DEFAULT ); //给对象添加样式
//    lv_obj_center            (OscScreen.OscChart.obj);
    lv_obj_set_pos(OscScreen.Chart.obj, 5, 45);
    lv_obj_set_size           (OscScreen.Chart.obj , OscScreen.Chart.width, OscScreen.Chart.height); //设置图表大小
    lv_obj_add_event_cb       (OscScreen.Chart.obj , OscChartCallBack, LV_EVENT_DRAW_PART_BEGIN, NULL); //给图表添加回调函数

    /****************************设置波形显示****************************/
    lv_chart_set_type         (OscScreen.Chart.obj ,LV_CHART_TYPE_LINE);
    /****************************设置图标Y轴的范围****************************/
    lv_chart_set_range        (OscScreen.Chart.obj ,LV_CHART_AXIS_PRIMARY_Y, 0, OscScreen.Chart.axis.y);
    /****************************设置图标X轴的范围****************************/
    lv_chart_set_range        (OscScreen.Chart.obj ,LV_CHART_AXIS_PRIMARY_X, 0, OscScreen.Chart.axis.x);
    /****************************设置线条上的点数***************************/
    lv_chart_set_point_count  (OscScreen.Chart.obj ,OscScreen.Chart.pointCnt);
    /****************************设置波形移位方式***************************/
    lv_chart_set_update_mode  (OscScreen.Chart.obj , OscScreen.Chart.updateMode);
    /****************************设置分割的线条数***************************/
    lv_chart_set_div_line_count(OscScreen.Chart.obj ,OscScreen.Chart.hDiv, OscScreen.Chart.vDiv);

    /*****************************线条*****************************/
    OscScreen.Chart.waveSeries     = lv_chart_add_series(OscScreen.Chart.obj, lv_palette_main(LV_PALETTE_YELLOW), LV_CHART_AXIS_PRIMARY_Y);
//    OscScreen.OscChart.spectrumSeries = lv_chart_add_series(eScreen.eChart.obj, lv_palette_main(LV_PALETTE_RED)   , LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_all_value(OscScreen.Chart.obj, OscScreen.Chart.waveSeries, 0);
/***********************************************************Logo***********************************************************/
    LV_IMG_DECLARE(OscLogo);
    lv_obj_t * logoImg = lv_img_create(lv_scr_act());
    lv_img_set_src(logoImg, &OscLogo);
    lv_obj_set_pos(logoImg,  157, 7);
    lv_img_set_zoom(logoImg, 300);
/***********************************************************按键***********************************************************/
    OscScreen.btnVer = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnVer);
    lv_obj_set_pos(OscScreen.btnVer, 240, 45);
    OscScreen.labelVerBtn = lv_label_create(OscScreen.btnVer);
    lv_label_set_text(OscScreen.labelVerBtn, "Ver: 1.00V");
    lv_obj_center(OscScreen.labelVerBtn);

    OscScreen.btnHor =lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnHor);
    lv_obj_set_pos(OscScreen.btnHor, 240, 85);
    OscScreen.labelHorBtn = lv_label_create(OscScreen.btnHor);
    lv_label_set_text(OscScreen.labelHorBtn, "Hor 20ms");
    lv_obj_center(OscScreen.labelHorBtn);

    OscScreen.btnTriAdd = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnTriAdd);
    lv_obj_set_pos(OscScreen.btnTriAdd, 240, 125);
    OscScreen.labelTriAddBtn = lv_label_create(OscScreen.btnTriAdd);
    lv_label_set_text(OscScreen.labelTriAddBtn, "Tri Add");
    lv_obj_center(OscScreen.labelTriAddBtn);

    OscScreen.btnTriSub = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnTriSub);
    lv_obj_set_pos(OscScreen.btnTriSub, 240, 165);
    OscScreen.labelTriSubBtn = lv_label_create(OscScreen.btnTriSub);
    lv_label_set_text(OscScreen.labelTriSubBtn, "Tri Sub");
    lv_obj_center(OscScreen.labelTriSubBtn);

    OscScreen.btnSave = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnSave);
    lv_obj_set_pos(OscScreen.btnSave, 240, 205);
    OscScreen.labelSaveBtn = lv_label_create(OscScreen.btnSave);
    lv_label_set_text(OscScreen.labelSaveBtn, "Save");
    lv_obj_center(OscScreen.labelSaveBtn);
/************************按键回调函数************************/
    lv_obj_add_event_cb(OscScreen.btnHor,    horBtnCallback,   LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(OscScreen.btnVer,    verBtnCallback,   LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(OscScreen.btnTriAdd, triBtnCallback,   LV_EVENT_CLICKED | LV_EVENT_LONG_PRESSED, NULL);
    lv_obj_add_event_cb(OscScreen.btnTriSub, triBtnCallback,   LV_EVENT_CLICKED | LV_EVENT_LONG_PRESSED, NULL);
    lv_obj_add_event_cb(OscScreen.btnSave,   saveBtnCallback,  LV_EVENT_CLICKED, NULL);
/***********************************************************标签***********************************************************/
    OscScreen.labelFre     =  lv_label_create(lv_scr_act());
    OscScreen.labelMAXVol  =  lv_label_create(lv_scr_act());
    OscScreen.labelTrigger =  lv_label_create(lv_scr_act());
    /****************************样式初始化****************************/
    OscNormalLabelStyle(&OscScreen.MixLabelStyle);
    lv_obj_set_pos       (OscScreen.labelMAXVol, 5,   5);
    lv_obj_set_pos       (OscScreen.labelFre,    5,  25);
    lv_obj_set_pos       (OscScreen.labelTrigger,80,  5);

    lv_obj_add_style     (OscScreen.labelMAXVol, &OscScreen.MixLabelStyle, 0);
    lv_obj_add_style     (OscScreen.labelFre,    &OscScreen.MixLabelStyle, 0);
    lv_obj_add_style     (OscScreen.labelTrigger,&OscScreen.MixLabelStyle, 0);
    lv_obj_set_size(OscScreen.labelFre,     130, 15);
    lv_obj_set_size(OscScreen.labelTrigger, 55, 15);

    lv_label_set_text_fmt(OscScreen.labelMAXVol, "Max: %1.3fV",    dataMaxLabelDouble);
    lv_label_set_text_fmt(OscScreen.labelFre,    "Fre: %.1f Hz",   dataFreLabelDouble);
    lv_label_set_text_fmt(OscScreen.labelTrigger,"Tri: %4d",       dataTriggerInt);
}
