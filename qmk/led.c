#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_sethsv(170, 255, 150);
}
#endif
