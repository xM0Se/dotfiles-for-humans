#include QMK_KEYBOARD_H
#include "tap-dances/tap-dances.h"
#include "layers/layers.h"

#include "tap-dances/td_spc_ent_tt1.c"
#include "tap-dances/td_alt_bspc_tt3.c"
#include "tap-dances/td_sft_tt2.c"
#include "tap-dances/td_cbr_alt.c"
#include "tap-dances/td_brc_ctl.c"
#include "tap-dances/td_slsh_gui.c"
#include "tap-dances/td_prn_gui.c"
#include "tap-dances/td_mins_ctl.c"
#include "tap-dances/td_coln_alt.c"

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT_TT1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_spc_ent_tt1_finished, dance_spc_ent_tt1_reset),
    [TD_ALT_BSPC_TT3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_alt_bspc_tt3_finished, dance_alt_bspc_tt3_reset),
    [TD_SFT_TT2]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_tt2_finished, dance_sft_tt2_reset),
    [TD_CBR_ALT]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cbr_alt_finished, dance_cbr_alt_reset),
    [TD_BRC_CTL]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_ctl_finished, dance_brc_ctl_reset),
    [TD_SLSH_GUI]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_slsh_gui_finished, dance_slsh_gui_reset),
    [TD_PRN_GUI]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_prn_gui_finished, dance_prn_gui_reset),
    [TD_MINS_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mins_ctl_finished, dance_mins_ctl_reset),
    [TD_COLN_ALT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_coln_alt_finished, dance_coln_alt_reset),

    [TD_ABK]          = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
};
