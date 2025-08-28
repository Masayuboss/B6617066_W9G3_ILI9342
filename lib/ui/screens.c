#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // adc_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.adc_chart = obj;
            lv_obj_set_pos(obj, 13, 86);
            lv_obj_set_size(obj, 180, 139);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 103, 13);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "B6617066 Ekahop Ngernna");
        }
        {
            // nextapge_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.nextapge_bt = obj;
            lv_obj_set_pos(obj, 218, 199);
            lv_obj_set_size(obj, 81, 26);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next page");
                }
            }
        }
        {
            // adc33bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc33bar = obj;
            lv_obj_set_pos(obj, 68, 43);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_range(obj, 0, 4095);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // adc34bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc34bar = obj;
            lv_obj_set_pos(obj, 68, 63);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_range(obj, 0, 4095);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 13, 40);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC33");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 13, 60);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC34");
        }
        {
            // adc33val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc33val = obj;
            lv_obj_set_pos(obj, 235, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // adc34val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc34val = obj;
            lv_obj_set_pos(obj, 235, 61);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 245, 96);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC33");
        }
        {
            // adc33led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.adc33led = obj;
            lv_obj_set_pos(obj, 253, 124);
            lv_obj_set_size(obj, 25, 23);
            lv_led_set_color(obj, lv_color_hex(0xff00ff75));
            lv_led_set_brightness(obj, 0);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_control_page() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.control_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // home_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_bt = obj;
            lv_obj_set_pos(obj, 11, 204);
            lv_obj_set_size(obj, 81, 26);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Home");
                }
            }
        }
        {
            // pwmval
            lv_obj_t *obj = lv_spinbox_create(parent_obj);
            objects.pwmval = obj;
            lv_obj_set_pos(obj, 45, 36);
            lv_obj_set_size(obj, 59, 28);
            lv_spinbox_set_digit_format(obj, 3, 0);
            lv_spinbox_set_range(obj, 0, 255);
            lv_spinbox_set_rollover(obj, false);
            lv_spinbox_set_step(obj, 1);
            lv_spinbox_set_value(obj, 0);
        }
        {
            // decrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.decrementpwm = obj;
            lv_obj_set_pos(obj, 8, 36);
            lv_obj_set_size(obj, 26, 26);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
            }
        }
        {
            // incrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.incrementpwm = obj;
            lv_obj_set_pos(obj, 113, 37);
            lv_obj_set_size(obj, 26, 26);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00903a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "PWM Control");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 16, 82);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Pump Control");
        }
        {
            // onmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.onmotor_bt = obj;
            lv_obj_set_pos(obj, 16, 104);
            lv_obj_set_size(obj, 102, 32);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff076732), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Open motor");
                }
            }
        }
        {
            // offmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.offmotor_bt = obj;
            lv_obj_set_pos(obj, 16, 146);
            lv_obj_set_size(obj, 102, 32);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffba3b05), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Closed motor");
                }
            }
        }
        {
            // fan_led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.fan_led = obj;
            lv_obj_set_pos(obj, 241, 120);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff0000ff));
            lv_led_set_brightness(obj, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 244, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Fan");
        }
        {
            // onpwm_sw
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.onpwm_sw = obj;
            lv_obj_set_pos(obj, 216, 33);
            lv_obj_set_size(obj, 50, 25);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 178, 39);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "OFF");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 273, 39);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ON");
        }
    }
    
    tick_screen_control_page();
}

void tick_screen_control_page() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_control_page,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_control_page();
}
