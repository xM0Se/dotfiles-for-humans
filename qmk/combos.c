#include QMK_KEYBOARD_H
#include "combos.h"
#include "layers.h"
#include "tap-dances.h"

const uint16_t PROGMEM _esc[] = {RALT_T(KC_N), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM _homerow[] = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM _homerow_scroll[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM _tab[] = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM _delete[] = {TD(TD_SFT_TT2), TD(TD_ALT_BSPC_TT3), COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    COMBO(_esc, KC_ESC),
    COMBO(_homerow, MEH(KC_C)),
    COMBO(_homerow_scroll, MEH(KC_G)),
    COMBO(_tab, KC_TAB),
    COMBO(_delete, KC_DEL),
};
