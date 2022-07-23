/**
  ******************************************************************************
  * @file           : OscChartCallBack.c
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/11
  ******************************************************************************
  */

#include "OscInterface.h"
/**
  * @brief  示波器图标控件回调函数，用于构建图表界面
  * @note   None
  * @param  None
  * @retval None
  */
void OscChartCallBack(lv_event_t * e) {
    lv_obj_draw_part_dsc_t *oscDsc = lv_event_get_draw_part_dsc(e);
    if (oscDsc->part == LV_PART_MAIN) {
        if (oscDsc->line_dsc == NULL || oscDsc->p1 == NULL || oscDsc->p2 == NULL) {
            return;
        }
        if (oscDsc->p1->x == oscDsc->p2->x) {
//            oscDsc->line_dsc->color  = lv_palette_lighten(LV_PALETTE_GREY, 1);
            oscDsc->line_dsc->color  = lv_color_hex(0xd3d3d3);
            oscDsc->line_dsc->opa         = LV_OPA_100;
            if (oscDsc->id == 5) {
                oscDsc->line_dsc->width       = 3;
                oscDsc->line_dsc->dash_gap    = 2;
                oscDsc->line_dsc->dash_width  = 2;
                oscDsc->line_dsc->color       = lv_palette_main(LV_PALETTE_GREEN);
            }else {
                oscDsc->line_dsc->width       = 1;
                oscDsc->line_dsc->dash_gap    = 2;
                oscDsc->line_dsc->dash_width  = 1;
                oscDsc->line_dsc->opa         = LV_OPA_40;
            }
        }else {
//            oscDsc->line_dsc->color           = lv_palette_lighten(LV_PALETTE_GREY, 1);
            oscDsc->line_dsc->color  = lv_color_hex(0xd3d3d3);
            oscDsc->line_dsc->opa         = LV_OPA_100;
            if (oscDsc->id == 4) {
                oscDsc->line_dsc->width       = 3;
                oscDsc->line_dsc->dash_gap    = 3;
                oscDsc->line_dsc->dash_width  = 2;
                oscDsc->line_dsc->color       = lv_palette_main(LV_PALETTE_GREEN);
            }else {
                oscDsc->line_dsc->width       = 1;
                oscDsc->line_dsc->dash_gap    = 3;
                oscDsc->line_dsc->dash_width  = 1;
                oscDsc->line_dsc->opa         = LV_OPA_40;
            }
        }
    }
}
