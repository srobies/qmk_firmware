#include QMK_KEYBOARD_H

#define _Dvorak 0
#define _QWERTY 1
#define _FL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Keymap _Dvorak: (Base Layer with Dvorak Layout) Default Layer
    [_Dvorak] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,  KC_BSPC, KC_GRV,
        KC_TAB,  KC_QUOTE,    KC_COMMA,    KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLASH, KC_EQL, KC_BSLS, KC_DEL,
        MO(_FL), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINUS,          KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_SCOLON,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W, KC_V,  KC_Z, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QWERTY] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        MO(_FL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
        [_FL] = LAYOUT_65_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
        _______, _______, KC_UP,   KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______,          _______, KC_END,
        _______,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, _______, _______, TO(_Dvorak),
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, TO(_QWERTY)
    ),
};
