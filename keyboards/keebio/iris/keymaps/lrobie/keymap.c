#include QMK_KEYBOARD_H
#define _DVORAK 0
#define _QWERTY 1
#define _STENO 2
#define _FN 3
#include "config.h"
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};

enum {
  KC_9_LBRC,
  KC_0_RBRC
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [KC_9_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRC),
  [KC_0_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRC)
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,  TD(KC_9_LBRC),TD(KC_0_RBRC),KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LALT, TO(_QWERTY),KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_SPC,  LT(_FN,KC_ENT),LT(_FN,KC_BSPC),KC_EQL,KC_BSLS
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,TD(KC_9_LBRC),TD(KC_0_RBRC),KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, TO(_DVORAK),KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_SPC,  LT(_FN,KC_ENT),LT(_FN,KC_BSPC),KC_EQL,KC_BSLS
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),
  [_STENO] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  _______, _______,_______, _______, _______,                    _______, _______, _______, _______, _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  _______, _______,_______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_S,     KC_T,     KC_P,    KC_H,   KC_ASTR,                   KC_ASTR,   KC_F,    KC_P,   KC_L,     KC_T,    KC_D,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_S,     KC_K,     KC_W,    KC_R,   KC_ASTR,_______,TO(_DVORAK),KC_ASTR,  KC_R,    KC_B,   KC_G,     KC_S,   KC_Z,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_A,     KC_O,     _______,           _______, KC_E,   KC_U
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),
  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,    KC_F7,   KC_F8,  KC_F9,   KC_F10, KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_UP,   _______, RGB_TOG, RGB_MOD,                    KC_7,    KC_8,    KC_9,    KC_LBRC, KC_RBRC, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, TO(_STENO),                    KC_4,    KC_5,    KC_6,    _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_PGUP, KC_PGDN, KC_VOLD,  KC_ENT,  KC_1,    KC_2,    KC_3,    _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘└───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_MUTE, KC_VOLU, _______,           _______,   KC_0,   KC_DOT
                                // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  )
};
