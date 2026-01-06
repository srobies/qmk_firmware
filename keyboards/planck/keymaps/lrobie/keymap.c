/* Copyright 2015-2021 Jack Humbert
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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define TO_HD TO(_HANDSDOWN)
#define TO_NUM TO(_NUMPAD)
#define TO_GA TO(_GAMING)
#define MO_AD MO(_ADJUST)
#define QTILE LM(_QTILE, MOD_LGUI)
#define TERM LM(_QTILE, MOD_LALT)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)

enum planck_layers {
  _HANDSDOWN,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _QTILE
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum td_keycodes {
    NAV // Qtile on single hold, Term on double hold
};

td_state_t cur_dance(tap_dance_state_t *state);
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_HANDSDOWN] = LAYOUT_planck_grid(
    QK_GESC, KC_W,    KC_F,    KC_M,  KC_P,  KC_V,   KC_SLSH, KC_DOT, KC_Q,    KC_SCLN, KC_QUOT, KC_Z,
    KC_TAB,  KC_R,    KC_S,    KC_N,  KC_T,  KC_B,   KC_COMM, KC_A,   KC_E,    KC_I,    KC_H,    KC_J,
    KC_LSFT, KC_X,    KC_C,    KC_L,  KC_D,  KC_G,   KC_MINS, KC_U,   KC_O,    KC_Y,    KC_K,    SC_SENT,
    KC_LCTL, KC_LGUI, KC_LALT, TD(NAV), LOWER, KC_SPC, KC_SPC,  RAISE,  KC_BSPC, KC_LALT, _______, _______
),
[_GAMING] = LAYOUT_planck_grid(
    QK_GESC, KC_1,    KC_2,    KC_3,   KC_4, KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,   KC_F,   KC_G,   KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LSFT, KC_A,    KC_O,    KC_E,   KC_U, KC_I,   KC_D,   KC_H,   KC_T,    KC_N,    KC_S,    KC_RSFT,
    KC_LCTL, KC_SCLN, KC_Q,    KC_J,   KC_K, KC_SPC, KC_SPC, KC_ENT, _______, _______, _______, TO_HD
),
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, UNDO,    CUT,     COPY,    PASTE,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU
    ),
[_ADJUST] = LAYOUT_planck_grid(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   TO_GA,   TO_HD,   TO_NUM,  _______, _______, QK_BOOT,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, KC_7, KC_8, KC_9,   _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, KC_4, KC_5, KC_6,   _______,  KC_UP,   _______, _______,
    _______, _______, _______, _______, _______, KC_1, KC_2, KC_3,   KC_LEFT,  KC_DOWN, KC_RGHT, _______,
    _______, _______, _______, _______, KC_TAB,  KC_0, KC_0, KC_ENT, _______,  _______, _______, TO_HD
),
[_QTILE] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_H,    KC_J,    KC_K,    KC_L,    _______, _______, KC_A,    KC_E,    KC_I,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_U,    KC_O,    KC_Y,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) return TD_SINGLE_HOLD;
    }
    if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
    }
    return TD_UNKNOWN;
}

static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            layer_on(_QTILE);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LALT);
            layer_on(_QTILE);
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        unregister_code(KC_LGUI);
        layer_off(_QTILE);
    }
    if (ql_tap_state.state == TD_DOUBLE_HOLD) {
        unregister_code(KC_LALT);
        layer_off(_QTILE);
    }
    ql_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};
