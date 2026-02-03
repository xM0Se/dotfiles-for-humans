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
