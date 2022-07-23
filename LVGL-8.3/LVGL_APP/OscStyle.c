/**
  ******************************************************************************
  * @file           : OscStyle.c
  * @author         : WangLaoEr
  * @brief          : None
  * @attention      : None
  * @date           : 2022/7/10
  ******************************************************************************
  */

#include "OscStyle.h"

/**
  * @brief  一般按键样式设计
  * @note   None
  * @param  None
  * @retval None
  */
void OscNormalBtnStyle(lv_obj_t *obj) {
    static lv_style_t btnReleaseStyle;
    static lv_style_t btnPressStyle;

    lv_style_init(&btnReleaseStyle);
    lv_style_init(&btnPressStyle);
    /******************设置按键释放状态样式******************/
    lv_style_set_radius(&btnReleaseStyle, 3);
    lv_style_set_bg_opa(&btnReleaseStyle, LV_OPA_100);
    lv_style_set_bg_color(&btnReleaseStyle, lv_color_hex(OSC_COLOR_GREEN_LIGHT));
    lv_style_set_text_color(&btnReleaseStyle, lv_color_white());
    /******************设置按键按下状态样式******************/
    lv_style_set_outline_width(&btnPressStyle, 30);
    lv_style_set_outline_opa(&btnPressStyle, LV_OPA_TRANSP);
    lv_style_set_translate_y(&btnPressStyle, 5);
    lv_style_set_shadow_ofs_y(&btnPressStyle, 3);
    lv_style_set_bg_color(&btnPressStyle, lv_palette_darken(LV_PALETTE_RED, 2));

    lv_obj_remove_style_all(obj);                          /*Remove the style coming from the theme*/
    lv_obj_add_style(obj, &btnReleaseStyle, 0);
    lv_obj_add_style(obj, &btnPressStyle, LV_STATE_PRESSED);
    lv_obj_set_size(obj, 75, 30);
}

/**
  * @brief  标签样式设计
  * @note   None
  * @param  None
  * @retval None
  */
void OscNormalLabelStyle(lv_style_t *obj) {
    lv_style_init(obj);
    lv_style_set_text_align (obj, LV_ALIGN_OUT_LEFT_TOP);
    lv_style_set_bg_color   (obj, lv_color_hex(OSC_COLOR_YELLOW));
    lv_style_set_bg_opa     (obj, LV_OPA_100);
    lv_style_set_text_color (obj, lv_color_hex(OSC_COLOR_BLACK));
    lv_style_set_text_font  (obj, &lv_font_montserrat_12);
    lv_style_set_height     (obj, 15);
    lv_style_set_width      (obj, 75);
    lv_style_set_text_align (obj, LV_TEXT_ALIGN_AUTO);
}

