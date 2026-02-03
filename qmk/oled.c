#include QMK_KEYBOARD_H
#include "layers/layers.h"

#ifdef OLED_ENABLE

bool oled_task_user(void) {

    if (is_keyboard_master()) {


        switch (get_highest_layer(layer_state)) {
            case _default_layer:
                oled_write("main layer", false);
                break;
            case _number_layer:
                oled_write("number layer", false);
                break;
            case _symbol_layer:
                oled_write("symbol layer", false);
                break;
            case _keyboard_layer:
                oled_write("idk layer", false);
                break;
            case _arrow_layer:
                oled_write("arrow layer", false);
                break;
        }
        return false;


    } else { /* left side ^ */ /* rigth side */

        oled_write("hello world",false);

    }
    return false;
}

#endif
