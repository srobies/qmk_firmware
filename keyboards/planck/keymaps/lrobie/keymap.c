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

enum planck_layers {
  _DVORAK,
  _GAMING,
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _NUMPAD
};

enum planck_keycodes {
  PLOVER = SAFE_RANGE,
  EXT_PLV,
  COPY,
  CUT,
  PASTE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define TO_DV TO(_DVORAK)
#define TO_QW TO(_QWERTY)
#define TO_NUM TO(_NUMPAD)
#define TO_GA TO(_GAMING)
#define MO_AD MO(_ADJUST)
#define QTILE LM(_RAISE, MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVORAK] = LAYOUT_planck_grid(
    QK_GESC, KC_QUOT, KC_COMM, KC_DOT, KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,  KC_SLSH,
    KC_TAB,  KC_A,    KC_O,    KC_E,   KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,  KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,  SC_SENT,
    KC_LCTL, KC_LGUI, KC_LALT, QTILE,  LOWER, KC_SPC, KC_SPC, RAISE, KC_BSPC, KC_MPLY, KC_MPRV, KC_MNXT
),
[_GAMING] = LAYOUT_planck_grid(
    QK_GESC, KC_1,    KC_2,    KC_3,   KC_4, KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,   KC_F,   KC_G,   KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LSFT, KC_A,    KC_O,    KC_E,   KC_U, KC_I,   KC_D,   KC_H,   KC_T,    KC_N,    KC_S,    KC_RSFT,
    KC_LCTL, KC_SCLN, KC_Q,    KC_J,   KC_K, KC_SPC, KC_SPC, KC_ENT, _______, _______, _______, TO_DV
),
[_QWERTY] = LAYOUT_planck_grid(
    QK_GESC, KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, QTILE, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
    _______, _______, CUT,     COPY,    PASTE,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU
    ),

[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),
[_ADJUST] = LAYOUT_planck_grid(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   TO_GA,   TO_DV,   TO_QW,   PLOVER,  TO_NUM,  QK_BOOT,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, KC_7, KC_8, KC_9,   _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, KC_4, KC_5, KC_6,   _______,  KC_UP,   _______, _______,
    _______, _______, _______, _______, _______, KC_1, KC_2, KC_3,   KC_LEFT,  KC_DOWN, KC_RGHT, _______,
    _______, _______, _______, _______, KC_TAB,  KC_0, KC_0, KC_ENT, _______,  _______, _______, TO_DV
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case CUT:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("x"));
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("c"));
      }
      return false;
      break;
    case PASTE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("v"));
      }
      return false;
      break;
  }
  return true;
}
