#include QMK_KEYBOARD_H
#include "layers/layers.h"
#include "tap-dances/tap-dances.h"

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (data[0] == 0x01) {
        layer_move(data[_ONSHAPE]); 
    }
}
