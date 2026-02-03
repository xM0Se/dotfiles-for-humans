#include QMK_KEYBOARD_H
#include "combos.h"
#include "layers.h"
#include "tap-dances.h"

const uint16_t PROGMEM n-r_esc[]                = {RALT_T(KC_N), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM c-k_homerow[]            = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM g-m_homerow_scroll[]     = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM space-shift_tab[]        = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM space-backspace_delete[] = {TD(TD_SPC_ENT_TT1), TD(TD_ALT_BSPC_TT3), COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    COMBO(n-r_esc, KC_ESC),
    COMBO(c-k_homerow, MEH(KC_C)),
    COMBO(g-m_homerow_scroll, MEH(KC_G)),
    COMBO(space-shift_tab, KC_TAB),
    COMBO(space-backspace_delete, KC_DEL),
};
