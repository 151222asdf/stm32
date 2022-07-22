#include "MyApplication.h"
#include "test.h"
#include <stdio.h>

lv_obj_t* text;//��ʼ����
static lv_style_t style1;//����ʼ������ʽ
lv_chart_series_t* ser1;
lv_chart_series_t* ser2;
/**
  * @brief  ʾ����ͼ��ؼ��ص����������ڹ���ͼ�����
  * @note   None
  * @param  None
  * @retval None
  */
static void eChartCallBack(lv_event_t* e) {
    lv_obj_draw_part_dsc_t* eDsc = lv_event_get_draw_part_dsc(e);
    if (eDsc->part == LV_PART_MAIN) {
        if (eDsc->line_dsc == NULL || eDsc->p1 == NULL || eDsc->p2 == NULL) {
            return;
        }
        if (eDsc->p1->x == eDsc->p2->x) {
            //            eDsc->line_dsc->color  = lv_palette_lighten(LV_PALETTE_GREY, 1);
            eDsc->line_dsc->color = lv_color_hex(0xd3d3d3);
            if (eDsc->id == 5) {
                eDsc->line_dsc->width = 3;
                eDsc->line_dsc->dash_gap = 7;
                eDsc->line_dsc->dash_width = 3;
                eDsc->line_dsc->color = lv_palette_main(LV_PALETTE_GREEN);
            }
            else {
                eDsc->line_dsc->width = 1;
                eDsc->line_dsc->dash_gap = 5;
                eDsc->line_dsc->dash_width = 2;
            }
        }
        else {
            //            eDsc->line_dsc->color           = lv_palette_lighten(LV_PALETTE_GREY, 1);
            eDsc->line_dsc->color = lv_color_hex(0xd3d3d3);
            if (eDsc->id == 4) {
                eDsc->line_dsc->width = 3;
                eDsc->line_dsc->dash_gap = 7;
                eDsc->line_dsc->dash_width = 3;
                eDsc->line_dsc->color = lv_palette_main(LV_PALETTE_GREEN);
            }
            else {
                eDsc->line_dsc->width = 1;
                eDsc->line_dsc->dash_gap = 7;
                eDsc->line_dsc->dash_width = 2;
            }
        }
    }
}
void test_start(void)
{
 
    /*��������ɫ*/
    lv_obj_set_style_bg_color(lv_scr_act(), END_COLOR_BLACK, 0);       //0x000000 = ��ɫ
    /*�Ա������л���*/
    text = lv_chart_create(lv_scr_act());
    lv_style_init(&style1); //��ʽ��ʼ������
    lv_style_set_bg_color(&style1, END_COLOR_BLACK); //���ñ���ɫ
    lv_style_set_border_side(&style1, LV_BORDER_SIDE_FULL);//���ñ�
    lv_style_set_border_color(&style1, lv_palette_lighten(LV_PALETTE_GREY, 1));
    lv_style_set_border_width(&style1, 1); //���ñ߿�
    lv_style_set_radius(&style1, 5); //����Բ��
    lv_style_set_pad_all(&style1, 0); //���ñ߾�
    lv_obj_add_style(text, &style1, LV_STATE_DEFAULT); //�����������ʽ
    lv_obj_set_pos(text, 5, 65);
    lv_obj_set_size(text, 250, 170); //����ͼ���С
    lv_obj_add_event_cb(text, eChartCallBack, LV_EVENT_DRAW_PART_BEGIN, NULL); //��ͼ����ӻص�����

    /****************************���ò�����ʾ****************************/
    lv_chart_set_type(text, LV_CHART_TYPE_LINE);//ָ����ʾ����֮��Ļ���
    /****************************����ͼ��Y��ķ�Χ****************************/
    lv_chart_set_range(text, LV_CHART_AXIS_PRIMARY_Y, 0, 100);//��ֱ���ű���
    /****************************����ͼ��X��ķ�Χ****************************/
    lv_chart_set_range(text, LV_CHART_AXIS_PRIMARY_X, 0, 100);//��ֱ���ű���
    /*******************************************************/
    lv_chart_set_point_count(text, 500);//���ø������
    /****************************���ò�����λ��ʽ***************************/
    lv_chart_set_update_mode(text, LV_CHART_UPDATE_MODE_SHIFT);
    /****************************���÷ָ��������***************************/
    lv_chart_set_div_line_count(text, 9, 11);

    /*****************************����*****************************/
    //˫��ʾ��������·�ɼ��ź�
    ser1 = lv_chart_add_series(text, lv_palette_main(LV_PALETTE_YELLOW), LV_CHART_AXIS_PRIMARY_Y);
    ser2 = lv_chart_add_series(text, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_all_value(text, ser1, 50);
    lv_chart_set_all_value(text, ser2, 0);
}

/**
  * @brief  ������ʾ ���Ρ�Ƶ�ס�����
  * @note   None
  * @param  None
  * @retval None
  */
void ETaskDataShowEntry(void) {
            for (int i = 0; i < 9032; i++) {
                lv_chart_set_next_value(text, ser1, i % 100);
                lv_chart_refresh(text);
            }
        lv_chart_set_all_value(text, ser1, 50);
}





