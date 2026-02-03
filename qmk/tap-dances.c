#include QMK_KEYBOARD_H
#include "tap-dances.h"
#include "layers/layers.h"

static bool td_coln_alt_held = false;
void dance_coln_alt_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_coln_alt_held = true;
        register_code(KC_RALT);
    } else {
        td_coln_alt_held = false;
        tap_code16(KC_COLN);
    }
}

void dance_coln_alt_reset(tap_dance_state_t *state, void *user_data) {
    if (td_coln_alt_held) {
        unregister_code(KC_RALT);
        td_coln_alt_held = false;
    }
}

static bool td_mins_ctl_held = false;
void dance_mins_ctl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_mins_ctl_held = true;
        register_code(KC_RCTL);
    } else {
        td_mins_ctl_held = false;
        if (state->count == 1) {
            tap_code(KC_MINS);
        } else if (state->count == 2) {
            tap_code16(KC_UNDS);
        }
    }
}

void dance_mins_ctl_reset(tap_dance_state_t *state, void *user_data) {
    if (td_mins_ctl_held) {
        unregister_code(KC_RCTL);
        td_mins_ctl_held = false;
    }
}

static bool td_slsh_gui_held = false;
void dance_slsh_gui_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_slsh_gui_held = true;
        register_code(KC_RGUI);
    } else {
        td_slsh_gui_held = false;
        if (state->count == 1) {
            tap_code(KC_SLSH);
        } else if (state->count == 2) {
            tap_code(KC_BSLS);
        }
    }
}

void dance_slsh_gui_reset(tap_dance_state_t *state, void *user_data) {
    if (td_slsh_gui_held) {
        unregister_code(KC_RGUI);
        td_slsh_gui_held = false;
    }
}

static bool td_prn_gui_held = false;
void dance_prn_gui_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_prn_gui_held = true;
        register_code(KC_LGUI);
    } else {
        td_prn_gui_held = false;
        if (state->count == 1) {
            tap_code16(KC_LPRN);
        } else if (state->count == 2) {
            tap_code16(KC_RPRN);
        }
    }
}

void dance_prn_gui_reset(tap_dance_state_t *state, void *user_data) {
    if (td_prn_gui_held) {
        unregister_code(KC_LGUI);
        td_prn_gui_held = false;
    }
}

static bool td_brc_ctl_held = false;
void dance_brc_ctl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_brc_ctl_held = true;
        register_code(KC_LCTL);
    } else {
        td_brc_ctl_held = false;
        if (state->count == 1) {
            tap_code(KC_LBRC);
        } else if (state->count == 2) {
            tap_code(KC_RBRC);
        }
    }
}

void dance_brc_ctl_reset(tap_dance_state_t *state, void *user_data) {
    if (td_brc_ctl_held) {
        unregister_code(KC_LCTL);
        td_brc_ctl_held = false;
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
        layer_on(_NUMBER);
    } else {
        td_spc_ent_tt1_held = false;
        if (state->count == 1) {
            tap_code(KC_SPC);
        } else if (state->count == 2) {
            tap_code(KC_ENT);
        } else if (state->count >= 5) {
            layer_on(_NUMBER);
        }
    }
}

void dance_spc_ent_tt1_reset(tap_dance_state_t *state, void *user_data) {
    if (td_spc_ent_tt1_held) {
        layer_off(_NUMBER);
        td_spc_ent_tt1_held = false;
    }
}

static bool td_alt_bspc_tt3_held = false;
void dance_alt_bspc_tt3_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_alt_bspc_tt3_held = true;
        layer_on(_ARROW);
    } else {
        td_alt_bspc_tt3_held = false;
        if (state->count == 1) {
            tap_code(KC_BSPC);
        } else if (state->count == 2) {
            register_code(KC_LALT);
            tap_code(KC_BSPC);
            unregister_code(KC_LALT);
        } else if (state->count >= 5) {
            layer_on(_ARROW);
        }
    }
}

void dance_alt_bspc_tt3_reset(tap_dance_state_t *state, void *user_data) {
    if (td_alt_bspc_tt3_held) {
        layer_off(_ARROW);
        td_alt_bspc_tt3_held = false;
    }
}

static bool td_sft_tt2 = false;
void dance_sft_tt2_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_sft_tt2 = true;
        layer_on(_SYMBOL);
    } else {
        td_sft_tt2 = false;
        if (state->count == 1) {
            set_oneshot_mods(MOD_BIT(KC_RSFT));
        } else if (state->count == 2) {
            caps_word_toggle();
        } else if (state->count >= 5) {
            layer_on(_SYMBOL);
        }
    }
}

void dance_sft_tt2_reset(tap_dance_state_t *state, void *user_data) {
    if (td_sft_tt2) {
        layer_off(_SYMBOL);
        td_sft_tt2 = false;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT_TT1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_spc_ent_tt1_finished, dance_spc_ent_tt1_reset),
    [TD_ALT_BSPC_TT3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_alt_bspc_tt3_finished, dance_alt_bspc_tt3_reset),
    [TD_SFT_TT2]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_tt2_finished, dance_sft_tt2_reset),
    [TD_CBR_ALT]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cbr_alt_finished, dance_cbr_alt_reset),
    [TD_BRC_CTL]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_ctl_finished, dance_brc_ctl_reset),
    [TD_SLSH_GUI]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_slsh_gui_finished, dance_slsh_gui_reset),
    [TD_PRN_GUI]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_prn_gui_finished, dance_prn_gui_reset),
    [TD_ABK]          = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_MINS_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mins_ctl_finished, dance_mins_ctl_reset),
    [TD_COLN_ALT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_coln_alt_finished, dance_coln_alt_reset),
};
