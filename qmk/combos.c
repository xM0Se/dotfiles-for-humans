#include QMK_KEYBOARD_H
#include "combos.h"
#include "layers.h"
#include "tap-dances.h"

const uint16_t PROGMEM n_r__esc_combo[]                = {RALT_T(KC_N), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM c_k__homerow_combo[]            = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM g_m__homerow_scroll_combo[]     = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM space_shift__tab_combo[]        = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM space_backspace__delete_combo[] = {TD(TD_SPC_ENT_TT1), TD(TD_ALT_BSPC_TT3), COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    COMBO(n_r__esc, KC_ESC),
    COMBO(c_k__homerow, MEH(KC_C)),
    COMBO(g_m__homerow_scroll, MEH(KC_G)),
    COMBO(space_shift__tab, KC_TAB),
    COMBO(space_backspace__delete, KC_DEL),
};
