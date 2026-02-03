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
