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
