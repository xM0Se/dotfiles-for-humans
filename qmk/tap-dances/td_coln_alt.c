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
