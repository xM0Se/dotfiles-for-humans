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
