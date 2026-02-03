#include QMK_KEYBOARD_H
#include "layers.h"

const uint16_t PROGMEM esc_n_r[] = {RALT_T(KC_N), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM homerow_c_k[] = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM homerow_scroll_g_m[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM tab_shift_space[] = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM delete_shift_bspc[] = {TD(TD_SFT_TT2), TD(TD_ALT_BSPC_TT3), COMBO_END};
combo_t key_combos[] = {
    COMBO(homerow_c_k, MEH(KC_C)),
    COMBO(homerow_scroll_g_m, MEH(KC_G)),
    COMBO(tab_shift_space, KC_TAB),
    COMBO(delete_shift_bspc, KC_DEL),
};
