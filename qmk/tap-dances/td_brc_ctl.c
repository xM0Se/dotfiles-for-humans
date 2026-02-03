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
