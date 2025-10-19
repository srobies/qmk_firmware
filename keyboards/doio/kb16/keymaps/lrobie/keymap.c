/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// OLED animation
#include "lib/layer_status/layer_status.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _FN,
    _FN1,
    _FN2
};

// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                KC_ESC,  KC_NO,     KC_NO,    KC_NO,     KC_MPLY,
                A(KC_Z), A(KC_F12), A(KC_F9), LSG(KC_S), TO(_FN),
                C(KC_A), C(KC_S),   KC_AGIN,  KC_NO,     KC_MUTE,
                KC_UNDO, KC_CUT,    KC_COPY,  KC_PASTE
            ),
    [_FN] = LAYOUT(
                KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_NO,
                KC_F1,   KC_F2,   KC_F3,   KC_F4,  TO(_FN1),
                KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_NO,
                KC_F9,   KC_F10,  KC_F11,  KC_F12
            ),
    [_FN1] = LAYOUT(
                KC_P7, KC_P8,  KC_P9,  KC_EQL,  KC_NO,
                KC_P4, KC_P5,  KC_P6,  KC_PLUS, TO(_FN2),
                KC_P1, KC_P7,  KC_P7,  KC_P7,   KC_NO,
                KC_P0, KC_DOT, KC_ENT, KC_TAB
            ),
    /*  Row:    0        1        2        3        4        */
    [_FN2] = LAYOUT(
                LM_PREV, LM_NEXT, KC_NO,   QK_BOOT, KC_NO,
                RM_SPDD, RM_SPDU, KC_NO,   KC_NO,   TO(_BASE),
                RGB_M_P, RGB_M_B, RGB_M_R, KC_NO,   BL_TOGG,
                KC_NO,    KC_NO,   KC_NO,   KC_NO
            ),
};

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(S(KC_VOLD), S(KC_VOLU)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]   = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_UNDO, KC_AGIN) },
    [_FN1]  = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UNDO, KC_AGIN) },
    [_FN2]  = { ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
};
#endif
