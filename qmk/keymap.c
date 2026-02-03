/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "tap-dances.h"
#include "layers/layers.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    #include "layers/base-layer.h"
    #include "layers/number-layer.h"
    #include "layers/symbol-layer.h"
    #include "layers/arrow-layer.h"
    #include "layers/onshape-layer.h"
    #include "layers/onshape-numbers-layer.h"
};

#include "led.c"
#include "oled.c"
#include "tap-dances.c"
#include "combos.c"
