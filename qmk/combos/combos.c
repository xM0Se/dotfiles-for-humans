#include QMK_KEYBOARD_H
#include "combos.h"
#include "layers/layers.h"
#include "tap-dances/tap-dances.h"

const uint16_t PROGMEM n_r__esc[]                = {RALT_T(KC_N), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM c_k__homerow[]            = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM g_m__homerow_scroll[]     = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM space_shift__tab[]        = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM space_backspace__delete[] = {TD(TD_SPC_ENT_TT1), TD(TD_ALT_BSPC_TT3), COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    COMBO(n_r__esc, KC_ESC),
    COMBO(c_k__homerow, MEH(KC_C)),
    COMBO(g_m__homerow_scroll, MEH(KC_G)),
    COMBO(space_shift__tab, KC_TAB),
    COMBO(space_backspace__delete, KC_DEL),
};
