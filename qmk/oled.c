#include QMK_KEYBOARD_H
#include "layers/layers.h"

#ifdef OLED_ENABLE

bool oled_task_user(void) {

    if (is_keyboard_master()) {


        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write("main layer", false);
                break;
            case _NUMBER:
                oled_write("number layer", false);
                break;
            case _SYMBOL:
                oled_write("symbol layer", false);
                break;
            case _ARROW:
                oled_write("arrow layer", false);
                break;
            case _ONSHAPE:
                oled_write("onshape layer", false);
                break;
            case _ONSHAPE_NUMBERS:
                oled_write("onshape numbers layer", false);
                break;
        }
        return false;


    } else { /* left side ^ */ /* rigth side */

        oled_write("hello world",false);

    }
    return false;
}

#endif
