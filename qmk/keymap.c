/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _default_layer,
    _number_layer,
    _symbol_layer,
    _keyboard_layer,
    _arrow_layer,
    _onshape,
    _onshape_numbers,
};

enum layers {
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4,
    _LAYER5,
    _LAYER6,
};

/* ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* TAP DANCES */

enum {
    TD_SPC_ENT_TT1,
    TD_ALT_BSPC_TT3,
    TD_SFT_TT2,
    TD_CBR_ALT,
    TD_BRC_GUI,
    TD_SLSH_CTL,
    TD_PRN_CTL,
    TD_ABK,
    TD_MINS_GUI,
};

static bool td_mins_gui_held = false;
void dance_mins_gui_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_mins_gui_held = true;
        register_code(KC_RGUI);
    } else {
        td_mins_gui_held = false;
        if (state->count == 1) {
            tap_code(KC_MINS);
        } else if (state->count == 2) {
            tap_code16(KC_UNDS);
        }
    }
}

void dance_mins_gui_reset(tap_dance_state_t *state, void *user_data) {
    if (td_mins_gui_held) {
        unregister_code(KC_RGUI);
        td_mins_gui_held = false;
    }
}

static bool td_slsh_ctl_held = false;
void dance_slsh_ctl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_slsh_ctl_held = true;
        register_code(KC_RCTL);
    } else {
        td_slsh_ctl_held = false;
        if (state->count == 1) {
            tap_code(KC_SLSH);
        } else if (state->count == 2) {
            tap_code(KC_BSLS);
        }
    }
}

void dance_slsh_ctl_reset(tap_dance_state_t *state, void *user_data) {
    if (td_slsh_ctl_held) {
        unregister_code(KC_RCTL);
        td_slsh_ctl_held = false;
    }
}

static bool td_prn_ctl_held = false;
void dance_prn_ctl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_prn_ctl_held = true;
        register_code(KC_LCTL);
    } else {
        td_prn_ctl_held = false;
        if (state->count == 1) {
            tap_code16(KC_RPRN);
        } else if (state->count == 2) { 
            tap_code16(KC_LPRN);
        }
    }
}

void dance_prn_ctl_reset(tap_dance_state_t *state, void *user_data) {
    if (td_prn_ctl_held) {
        unregister_code(KC_LCTL);
        td_prn_ctl_held = false;
    }
}

static bool td_brc_gui_held = false;
void dance_brc_gui_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_brc_gui_held = true;
        register_code(KC_LGUI);
    } else {
        td_brc_gui_held = false;
        if (state->count == 1) {
            tap_code(KC_LBRC);
        } else if (state->count == 2) {
            tap_code(KC_RBRC);
        }
    }
}

void dance_brc_gui_reset(tap_dance_state_t *state, void *user_data) {
    if (td_brc_gui_held) {
        unregister_code(KC_LGUI);
        td_brc_gui_held = false;
    }
}

static bool td_cbr_alt_held = false;
void dance_cbr_alt_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_cbr_alt_held = true;
        register_code(KC_LALT);
    } else {
        td_cbr_alt_held = false;
        if (state->count == 1) {
            tap_code16(KC_LCBR);
        } else if (state->count == 2) {
            tap_code16(KC_RCBR);
        }
    }
}

void dance_cbr_alt_reset(tap_dance_state_t *state, void *user_data) {
    if (td_cbr_alt_held) {
        unregister_code(KC_LALT);
        td_cbr_alt_held = false;
    }
}

static bool td_spc_ent_tt1_held = false;
void dance_spc_ent_tt1_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_spc_ent_tt1_held = true;
        layer_on(_LAYER1);
    } else {
        td_spc_ent_tt1_held = false;
        if (state->count == 1) {
            tap_code(KC_SPC);
        } else if (state->count == 2) {
            tap_code(KC_ENT);
        } else if (state->count >= 3) {
            layer_on(_LAYER1);
        }
    }
}

void dance_spc_ent_tt1_reset(tap_dance_state_t *state, void *user_data) {
    if (td_spc_ent_tt1_held) {
        layer_off(_LAYER1);
        td_spc_ent_tt1_held = false;
    }
}

static bool td_alt_bspc_tt3_held = false;
void dance_alt_bspc_tt3_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_alt_bspc_tt3_held = true;
        layer_on(_LAYER4);
    } else {
        td_alt_bspc_tt3_held = false;
        if (state->count == 1) {
            tap_code(KC_BSPC);
        } else if (state->count == 2) {
            register_code(KC_LALT);
            tap_code(KC_BSPC);
            unregister_code(KC_LALT);
        } else if (state->count >= 3) {
            layer_on(_LAYER4);
        }
    }
}

void dance_alt_bspc_tt3_reset(tap_dance_state_t *state, void *user_data) {
    if (td_alt_bspc_tt3_held) {
        layer_off(_LAYER4);
        td_alt_bspc_tt3_held = false;
    }
}

static bool td_sft_tt2 = false;
void dance_sft_tt2_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_sft_tt2 = true;
        layer_on(_LAYER2);
    } else {
        td_sft_tt2 = false;
        if (state->count == 1) {
            set_oneshot_mods(MOD_BIT(KC_RSFT));
        } else if (state->count == 2) {
            caps_word_toggle();
        } else if (state->count >= 3) {
            layer_on(_LAYER2);
        }
    }
}

void dance_sft_tt2_reset(tap_dance_state_t *state, void *user_data) {
    if (td_sft_tt2) {
        layer_off(_LAYER2);
        td_sft_tt2 = false;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT_TT1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_spc_ent_tt1_finished, dance_spc_ent_tt1_reset),
    [TD_ALT_BSPC_TT3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_alt_bspc_tt3_finished, dance_alt_bspc_tt3_reset),
    [TD_SFT_TT2]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_tt2_finished, dance_sft_tt2_reset),
    [TD_CBR_ALT]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cbr_alt_finished, dance_cbr_alt_reset),
    [TD_BRC_GUI]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_gui_finished, dance_brc_gui_reset),
    [TD_SLSH_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_slsh_ctl_finished, dance_slsh_ctl_reset),
    [TD_PRN_CTL]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_prn_ctl_finished, dance_prn_ctl_reset),
    [TD_ABK]          = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_MINS_GUI]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mins_gui_finished, dance_mins_gui_reset),
};

/* ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* COMBOS */

const uint16_t PROGMEM esc_n_r[] = {RALT_T(KC_N), LCTL_T(KC_R), COMBO_END};
const uint16_t PROGMEM homerow_c_k[] = {KC_C, KC_K, COMBO_END};
const uint16_t PROGMEM homerow_scroll_g_m[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM tab_shift_space[] = {TD(TD_SFT_TT2), TD(TD_SPC_ENT_TT1), COMBO_END};
const uint16_t PROGMEM delete_shift_bspc[] = {TD(TD_SFT_TT2), TD(TD_ALT_BSPC_TT3), COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_n_r, KC_ESC),
    COMBO(homerow_c_k, MEH(KC_C)),
    COMBO(homerow_scroll_g_m, MEH(KC_G)),
    COMBO(tab_shift_space, KC_TAB),
    COMBO(delete_shift_bspc, KC_DEL),
};

/* ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* KEYMAP */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------------------------------------.                                                           ,-----------------------------------------------------------------------------------------------------------------------.
      TO(5),              KC_Q,               KC_W,               KC_F,               KC_P,              KC_B,                                                                           KC_J,               KC_L,                    KC_U,               KC_Y,               MEH(KC_L),          MEH(KC_U),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                                           |-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
      MEH(KC_A),          KC_A,               LCTL_T(KC_R),      LGUI_T(KC_S),       LALT_T(KC_T),       KC_G,                                                                           KC_M,               RALT_T(KC_N),            RGUI_T(KC_E),       RCTL_T(KC_I),       KC_O,       MEH(KC_P),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                                           |-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
      MEH(KC_Z),          KC_Z,               KC_X,               KC_C,              KC_D,               KC_V,                                                                           KC_K,               KC_H,                    KC_DOT,             KC_COMM,            MEH(KC_X),          MEH(KC_H),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                                           |-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                     KC_NO,              TD(TD_SPC_ENT_TT1),  KC_NO,                           TD(TD_ALT_BSPC_TT3),   TD(TD_SFT_TT2),   KC_NO
                                                                                  //`-------------------+-------------------+-------------------'                   |`------------------+-------------------+-------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------------------------------------------------------.
      KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,              KC_F6,                                    KC_F7,              KC_F8,                   KC_F9,              KC_F10,             KC_F11,             KC_F12,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      HYPR(KC_Q),         KC_1,               LCTL_T(KC_2),       LGUI_T(KC_3),       LALT_T(KC_4),       KC_5,                                     KC_6,               RALT_T(KC_7),            RGUI_T(KC_8),       RCTL_T(KC_9),       KC_0,               HYPR(KC_0),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      HYPR(KC_W),         HYPR(KC_F),         HYPR(KC_P),         HYPR(KC_B),         HYPR(KC_J),         HYPR(KC_L),                               HYPR(KC_U),         HYPR(KC_A),              KC_DOT,            KC_COMM,         HYPR(KC_T),         HYPR(KC_E),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                            TO(0),   _______,   TT(2),     _______,   _______,   TT(3)
                                                                                                        //`--------------------------'  `--------------------------'

  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------------------------------------------------------.
      MEH(KC_B),          KC_NO,              KC_PERC,            KC_PIPE,            KC_PPLS,            KC_AT,                                    TD(TD_ABK),            KC_AMPR,             KC_TILD,              KC_DQUO,            KC_NO,            MEH(KC_J),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      MEH(KC_G),          KC_GRV,             TD(TD_PRN_CTL),    TD(TD_BRC_GUI),     TD(TD_CBR_ALT),    KC_DLR,                                      KC_EXLM,            RALT_T(KC_COLN),         TD(TD_MINS_GUI),    TD(TD_SLSH_CTL),     KC_SCLN,           MEH(KC_M),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      MEH(KC_V),          KC_NO,             KC_PEQL,          KC_PAST,               KC_QUES,            KC_CIRC,                                  KC_EQL,            KC_UNDS,                 KC_DOT,            KC_COMM,            KC_HASH,            MEH(KC_K),
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                            TO(0),   _______,   TT(3),     _______,   _______,   KC_NO
                                                                                                        //`--------------------------'  `--------------------------'

  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------------------------------------------------------.
      QK_BOOT,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                  XXXXXXX,            XXXXXXX,                 XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      RM_TOGG,            RM_HUEU,            RM_SATU,            RM_VALU,            XXXXXXX,            XXXXXXX,                                  XXXXXXX,            XXXXXXX,                 XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      RM_NEXT,            RM_HUED,            RM_SATD,            RM_VALD,            XXXXXXX,            XXXXXXX,                                  XXXXXXX,            XXXXXXX,                 XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                            KC_LGUI,  _______,  KC_SPC,     KC_ENT,   _______,  KC_RALT
                                                                                                        //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(

  //,-----------------------------------------------------------------------------------------------------------------------.                    ,---------------------------------------------------------------------------------------------------------------------------.
      KC_NO,            KC_NO,               KC_NO,               KC_NO,             KC_NO,               KC_NO,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      KC_NO,            KC_NO,               KC_NO,               KC_NO,             KC_NO,               KC_NO,                                   KC_NO,             KC_LEFT,                 KC_DOWN,            KC_UP,              KC_RGHT,            KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      KC_NO,            KC_NO,               KC_NO,               KC_NO,             KC_NO,               KC_NO,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                            TO(0),  _______,  KC_SPC,     KC_ENT,   _______,  KC_RALT
                                                                                                        //`--------------------------'  `--------------------------'
  ),
    [5] = LAYOUT_split_3x6_3(

  //,-----------------------------------------------------------------------------------------------------------------------.                    ,---------------------------------------------------------------------------------------------------------------------------.
      KC_NO,            KC_C,                KC_G,                KC_L,              KC_D,                KC_NO,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      KC_NO,            LSFT(KC_F),          LSFT(KC_E),          LSFT(KC_S),        KC_DELETE,           KC_NO,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      KC_NO,            KC_NO,               KC_NO,               LSG(KC_Z),         LGUI(KC_Z),          KC_NO,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                            TO(0),   TO(6),  KC_ESC,     KC_ENT,   _______,  KC_RALT
                                                                                                        //`--------------------------'  `--------------------------'
  ),
    [6] = LAYOUT_split_3x6_3(

  //,-----------------------------------------------------------------------------------------------------------------------.                    ,---------------------------------------------------------------------------------------------------------------------------.
      KC_NO,            KC_7,                KC_8,                KC_9,              KC_ENT,              KC_M,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      KC_NO,            KC_4,                KC_5,                KC_6,              KC_DOT,              KC_C,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
      KC_NO,            KC_1,                KC_2,                KC_3,              KC_0,                KC_NO,                                   KC_NO,             KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,
  //|-------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                    |-------------------+------------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                            TO(0),   TO(5),  KC_BSPC,     KC_ENT,   _______,  KC_RALT
                                                                                                        //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};

#endif
#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    // Set default color to blue (HSV: Hue=170, Sat=255, Val=150)
    rgb_matrix_sethsv(170, 255, 150);
}
#endif


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
