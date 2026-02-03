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
