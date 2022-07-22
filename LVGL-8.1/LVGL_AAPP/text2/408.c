#include "408.h"
#include <stdio.h>

/**********************************主界面变量**********************************/
OscScreen_t OscScreen;

double dataMaxLabelDouble = 0.000;
double dataFreLabelDouble = 100000000.0;
int    dataTriggerInt = 255;
/**********************************回调函数声明**********************************/
void horBtnCallback(lv_event_t* e);
void verBtnCallback(lv_event_t* e);
void triBtnCallback(lv_event_t* e);
void rsBtnCallback(lv_event_t* e);
void dacBtnCallback(lv_event_t* e);
/**
  * @brief  示波器相关变量初始化
  * @note   None
  * @param  None
  * @retval None
  */
static void OscChartVarInit() {
    OscScreen.Chart.hdiv = 9;
    OscScreen.Chart.vdiv = 11;
    OscScreen.Chart.pointCnt = 500;
    OscScreen.Chart.updateMode = LV_CHART_UPDATE_MODE_SHIFT;
    OscScreen.Chart.axis.x = 100;
    OscScreen.Chart.axis.y = 4095;
    OscScreen.Chart.width = 230;
    OscScreen.Chart.height = 190;
}

/**
  * @brief  主界面构建
  * @note   None
  * @param  None
  * @retval None
  */
void OscMainInterface()
{
    OscChartVarInit();
    /*****************************************************设立背景色***********************************************************/
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(OSC_COLOR_BLACK), 0);
    /***********************************************************图表***********************************************************/
    OscScreen.Chart.obj = lv_chart_create(lv_scr_act());
    lv_style_init(&OscScreen.ChartStyle); //样式初始化函数
    lv_style_set_bg_color(&OscScreen.ChartStyle, lv_color_hex(OSC_COLOR_BLACK)); //设置背景色
    lv_style_set_border_side(&OscScreen.ChartStyle, LV_BORDER_SIDE_FULL);//设置边
    lv_style_set_border_color(&OscScreen.ChartStyle, lv_palette_lighten(LV_PALETTE_GREY, 1));
    lv_style_set_border_width(&OscScreen.ChartStyle, 1); //设置边宽
    lv_style_set_radius(&OscScreen.ChartStyle, 5); //设置圆角
    lv_style_set_pad_all(&OscScreen.ChartStyle, 0); //设置边距
    lv_style_set_border_opa(&OscScreen.ChartStyle, LV_OPA_40);
    lv_style_set_transform_zoom(&OscScreen.ChartStyle, 0);
    lv_chart_set_zoom_y(OscScreen.Chart.obj, LV_IMG_ZOOM_NONE);
    lv_chart_set_zoom_x(OscScreen.Chart.obj, LV_IMG_ZOOM_NONE);
    lv_obj_add_style(OscScreen.Chart.obj, &OscScreen.ChartStyle, LV_STATE_DEFAULT); //给对象添加样式
//    lv_obj_center            (OscScreen.OscChart.obj);
    lv_obj_set_pos(OscScreen.Chart.obj, 5, 45);
    lv_obj_set_size(OscScreen.Chart.obj, OscScreen.Chart.width, OscScreen.Chart.height); //设置图表大小
    lv_obj_add_event_cb(OscScreen.Chart.obj, OscChartCallBack, LV_EVENT_DRAW_PART_BEGIN, NULL); //给图表添加回调函数

   /****************************设置波形显示****************************/
    lv_chart_set_type(OscScreen.Chart.obj, LV_CHART_TYPE_LINE);
    /****************************设置图标Y轴的范围****************************/
    lv_chart_set_range(OscScreen.Chart.obj, LV_CHART_AXIS_PRIMARY_Y, 0, OscScreen.Chart.axis.y);
    /****************************设置图标X轴的范围****************************/
    lv_chart_set_range(OscScreen.Chart.obj, LV_CHART_AXIS_PRIMARY_X, 0, OscScreen.Chart.axis.x);
    /****************************设置线条上的点数***************************/
    lv_chart_set_point_count(OscScreen.Chart.obj, OscScreen.Chart.pointCnt);
    /****************************设置波形移位方式***************************/
    lv_chart_set_update_mode(OscScreen.Chart.obj, LV_CHART_UPDATE_MODE_SHIFT);
    /****************************设置分割的线条数***************************/
    lv_chart_set_div_line_count(OscScreen.Chart.obj, OscScreen.Chart.hdiv, OscScreen.Chart.vdiv);

    /*****************************示波器的两个通道以线条形式出现*****************************/
    OscScreen.Chart.waveSeries = lv_chart_add_series(OscScreen.Chart.obj, lv_palette_main(LV_PALETTE_YELLOW), LV_CHART_AXIS_PRIMARY_Y);
    OscScreen.Chart.spectrumSeries = lv_chart_add_series(OscScreen.Chart.obj, lv_palette_main(LV_PALETTE_RED)   , LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_all_value(OscScreen.Chart.obj, OscScreen.Chart.waveSeries, 2048);
    lv_chart_set_all_value(OscScreen.Chart.obj, OscScreen.Chart.spectrumSeries, 0);
    /***********************************************************Logo***********************************************************/
    LV_IMG_DECLARE(OscLogo);                                //包含图片资源文件
    lv_obj_t* logoImg = lv_img_create(lv_scr_act());        //创建静图对象
    lv_img_set_src(logoImg, &OscLogo);                      //设定图像来源
    lv_obj_set_pos(logoImg, 157, 7);                        //设定坐标
    lv_img_set_zoom(logoImg, 300);                          // 对图片进行缩放
/***********************************************************按键***********************************************************/
    OscScreen.btnVer = lv_btn_create(lv_scr_act());                                 //创建按键
    OscNormalBtnStyle(OscScreen.btnVer);                                            //创建一般按键格式
    lv_obj_set_pos(OscScreen.btnVer, 240, 45);                                      //设定按键位置
    OscScreen.labelVerBtn = lv_label_create(OscScreen.btnVer);                      //以按键为父类创建标签
    lv_label_set_text(OscScreen.labelVerBtn, "Ver: 1V");                            //创建一般的按键格式
    lv_obj_center(OscScreen.labelVerBtn);                                           //将标签与其父类对象进行中心对齐

    OscScreen.btnHor = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnHor);
    lv_obj_set_pos(OscScreen.btnHor, 240, 85);
    OscScreen.labelHorBtn = lv_label_create(OscScreen.btnHor);
    lv_label_set_text(OscScreen.labelHorBtn, "Hor 20ns");
    lv_obj_center(OscScreen.labelHorBtn);

    OscScreen.btnTri = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnTri);
    lv_obj_set_pos(OscScreen.btnTri, 240, 125);
    OscScreen.labelTriBtn = lv_label_create(OscScreen.btnTri);
    lv_label_set_text(OscScreen.labelTriBtn, "Trigger");
    lv_obj_center(OscScreen.labelTriBtn);

    OscScreen.btnRS = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnRS);
    lv_obj_set_pos(OscScreen.btnRS, 240, 165);
    OscScreen.labelRSBtn = lv_label_create(OscScreen.btnRS);
    lv_label_set_text(OscScreen.labelRSBtn, "Run");
    lv_obj_center(OscScreen.labelRSBtn);

    OscScreen.btnDAC = lv_btn_create(lv_scr_act());
    OscNormalBtnStyle(OscScreen.btnDAC);
    lv_obj_set_pos(OscScreen.btnDAC, 240, 205);
    OscScreen.labelDACBtn = lv_label_create(OscScreen.btnDAC);
    lv_label_set_text(OscScreen.labelDACBtn, "DAC");
    lv_obj_center(OscScreen.labelDACBtn);
    /************************按键回调函数************************/
    lv_obj_add_event_cb(OscScreen.btnHor, horBtnCallback, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(OscScreen.btnVer, verBtnCallback, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(OscScreen.btnTri, triBtnCallback, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(OscScreen.btnRS, rsBtnCallback, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(OscScreen.btnDAC, dacBtnCallback, LV_EVENT_CLICKED, NULL);
    /****************************样式初始化****************************/
}

/**
  * @brief  数据显示 波形、频谱、参数
  * @note   None
  * @param  None
  * @retval None
  */
void TEXT1258(void) {
            for (int i = 0; i < 9032; i++) {
                lv_chart_set_next_value(OscScreen.Chart.obj, OscScreen.Chart.waveSeries, i % 100);
                lv_chart_refresh(OscScreen.Chart.obj);
            }
        lv_chart_set_all_value(OscScreen.Chart.obj, OscScreen.Chart.waveSeries, 50);
}


