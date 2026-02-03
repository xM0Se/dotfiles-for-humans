#include QMK_KEYBOARD_H
#include "combos.h"
#include "layers.h"
#include "tap-dances.h"

const uint16_t PROGMEM n-r--esc[]                = {RALT_T(KC_N), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM c-k--homerow[]            = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM g-m--homerow_scroll[]     = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM space-shift--tab[]        = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM space-backspace--delete[] = {TD(TD_SPC_ENT_TT1), TD(TD_ALT_BSPC_TT3), COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    COMBO(n-r--esc, KC_ESC),
    COMBO(c-k--homerow, MEH(KC_C)),
    COMBO(g-m--homerow_scroll, MEH(KC_G)),
    COMBO(space-shift--tab, KC_TAB),
    COMBO(space-backspace--delete, KC_DEL),
};
