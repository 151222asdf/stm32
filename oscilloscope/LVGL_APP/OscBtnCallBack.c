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
///**
//  * @brief  示波器图标控件回调函数，用于构建图表界面
//  * @note   None
//  * @param  None
//  * @retval None
//  */
//void OscChartCallBack(lv_event_t * e) {
//    lv_obj_draw_part_dsc_t *oscDsc = lv_event_get_draw_part_dsc(e);
//    if (oscDsc->part == LV_PART_MAIN) {
//        if (oscDsc->line_dsc == NULL || oscDsc->p1 == NULL || oscDsc->p2 == NULL) {
//            return;
//        }
//        if (oscDsc->p1->x == oscDsc->p2->x) {
////            oscDsc->line_dsc->color  = lv_palette_lighten(LV_PALETTE_GREY, 1);
//            oscDsc->line_dsc->color  = lv_color_hex(0xd3d3d3);
//            oscDsc->line_dsc->opa         = LV_OPA_100;
//            if (oscDsc->id == 5) {
//                oscDsc->line_dsc->width       = 3;
//                oscDsc->line_dsc->dash_gap    = 2;
//                oscDsc->line_dsc->dash_width  = 2;
//                oscDsc->line_dsc->color       = lv_palette_main(LV_PALETTE_GREEN);
//            }else {
//                oscDsc->line_dsc->width       = 1;
//                oscDsc->line_dsc->dash_gap    = 2;
//                oscDsc->line_dsc->dash_width  = 1;
//                oscDsc->line_dsc->opa         = LV_OPA_40;
//            }
//        }else {
////            oscDsc->line_dsc->color           = lv_palette_lighten(LV_PALETTE_GREY, 1);
//            oscDsc->line_dsc->color  = lv_color_hex(0xd3d3d3);
//            oscDsc->line_dsc->opa         = LV_OPA_100;
//            if (oscDsc->id == 4) {
//                oscDsc->line_dsc->width       = 3;
//                oscDsc->line_dsc->dash_gap    = 3;
//                oscDsc->line_dsc->dash_width  = 2;
//                oscDsc->line_dsc->color       = lv_palette_main(LV_PALETTE_GREEN);
//            }else {
//                oscDsc->line_dsc->width       = 1;
//                oscDsc->line_dsc->dash_gap    = 3;
//                oscDsc->line_dsc->dash_width  = 1;
//                oscDsc->line_dsc->opa         = LV_OPA_40;
//            }
//        }
//    }
//}


/**
  * @brief  水平灵敏度回调函数
  * @note   None
  * @param  None
  * @retval None
  */
void horBtnCallback(lv_event_t *e) {
    static int clicked = 0;
    if (clicked == 0) {
        clicked++;
        lv_label_set_text(OscScreen.labelHorBtn, "Hor: 1V");
        lv_chart_set_zoom_x(OscScreen.Chart.obj, LV_IMG_ZOOM_NONE);
    } else if (clicked == 1) {
        clicked++;
        OscScreen.Chart.axis.y = 4095;
        lv_label_set_text(OscScreen.labelHorBtn, "Hor 0.1V");
        lv_chart_set_zoom_x(OscScreen.Chart.obj, LV_IMG_ZOOM_NONE + 500);
    } else if (clicked == 2) {
        clicked++;
        lv_label_set_text(OscScreen.labelHorBtn, "Hor 2mV");
        lv_chart_set_zoom_x(OscScreen.Chart.obj, LV_IMG_ZOOM_NONE + 1000);
    } else if (clicked == 3) {
        clicked = 0;
        lv_label_set_text(OscScreen.labelHorBtn, "Hor 2uV");
        lv_chart_set_zoom_x(OscScreen.Chart.obj, LV_IMG_ZOOM_NONE + 3000);
    }
}

/**
  * @brief  垂直灵敏度调节按键回调函数
  * @note   None
  * @param  None
  * @retval None
  */
void verBtnCallback(lv_event_t *e) {
    static int clicked = 0;
    if (clicked == 0) {
        clicked++;
        OscScreen.Chart.axis.x = 0;
        lv_label_set_text(OscScreen.labelVerBtn, "Ver: 0.1V");
        OscScreen.Chart.axis.x = 100;
//        lv_chart_set_zoom_y(OscScreen.OscChart.obj, LV_IMG_ZOOM_NONE + 500);
        lv_chart_set_range(OscScreen.Chart.obj, LV_CHART_AXIS_PRIMARY_Y, 0, 820);
    } else if (clicked == 1) {
        clicked = 0;
        lv_label_set_text(OscScreen.labelVerBtn, "Ver: 1V");
//        lv_chart_set_zoom_y(OscScreen.OscChart.obj, LV_IMG_ZOOM_NONE);
        lv_chart_set_range(OscScreen.Chart.obj, LV_CHART_AXIS_PRIMARY_Y, 0, 4096);
    }
}

/**
  * @brief  触发调节
  * @note   None
  * @param  None
  * @retval None
  */
void triBtnCallback(lv_event_t *e) {

}

/**
  * @brief  示波器暂停和运行
  * @note   None
  * @param  None
  * @retval None
  */

void rsBtnCallback(lv_event_t *e) {

}

/**
  * @brief  DAC输出
  * @note   None
  * @param  None
  * @retval None
  */
void dacBtnCallback (lv_event_t *e) {

}
