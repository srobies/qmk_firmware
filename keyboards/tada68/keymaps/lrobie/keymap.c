#include QMK_KEYBOARD_H

#define _Dvorak 0
#define _QWERTY 1
#define _FL 2

enum {
  TD_RCTRL_CAPS = 0,
  TD_ESC_GRV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Keymap _Dvorak: (Base Layer with Dvorak Layout) Default Layer
[_Dvorak] = LAYOUT_ansi(
  TD(TD_ESC_GRV),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC, KC_RBRC, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_QUOTE,   KC_COMMA,   KC_DOT,   KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_SLASH, KC_EQL,KC_BSLS,KC_DEL, \
  MO(_FL), KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,KC_MINS,         KC_ENT,KC_PGUP,  \
  KC_LSPO,         KC_SCLN,   KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,KC_V, KC_Z,   KC_RSPC,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPACE,                        KC_RALT,TG(_FL),TD(TD_RCTRL_CAPS), KC_LEFT,KC_DOWN,KC_RGHT),

  // Keymap _QWERTY: (Layer with Qwerty Layout)
[_QWERTY] = LAYOUT_ansi(
  TD(TD_ESC_GRV),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS, KC_EQUAL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRACKET, KC_RBRACKET,KC_BSLS,KC_DEL, \
  MO(_FL), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCOLON,KC_QUOTE,         KC_ENT,KC_PGUP,  \
  KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMMA,KC_DOT, KC_SLASH,   KC_RSPC,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPACE,                        KC_RALT,TG(_FL),TD(TD_RCTRL_CAPS), KC_LEFT,KC_DOWN,KC_RGHT),

  // Keymap _FL: Function Layer
[_FL] = LAYOUT_ansi(
  KC_GRV, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,KC_MPLY,KC_MPRV, KC_MNXT,_______,_______,_______,_______,_______,_______,_______, _______,KC_HOME, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,KC_MUTE,KC_VOLD,KC_VOLU,_______,_______,_______,_______,_______,_______,KC_END, \
  _______,_______,_______,BL_TOGG, BL_DEC,BL_INC, _______,_______,_______,_______,_______,_______, _______, TO(_QWERTY), \
  _______,_______,_______,_______,_______,_______,_______,_______,_______, TO(_Dvorak)),
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RCTRL_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RCTRL, KC_CAPS),
  [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
};  