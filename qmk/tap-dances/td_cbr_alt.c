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
