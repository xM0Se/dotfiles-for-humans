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
