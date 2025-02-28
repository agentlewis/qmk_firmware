/* Copyright 2020 Toyoshima Hidenori <t@toyo.dev>
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
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

#define EISU LALT(KC_GRV)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  TAB |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   -  |                    |   =  |   N  |   M  |   ,  |   .  |   /  |PageUp|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  Alt |   `  | RAISE||||||||  GUI | Raise| Space|||||||| Enter| Space|  Gui |||||||| Lower|   @  |   #  |PageDN|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
    [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,                        KC_EQL,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,                        KC_EQL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PGUP,
    KC_LCTL, KC_LALT, KC_GRV, KC_DEL,            KC_LGUI, KC_BSPC, RAISE,         KC_ENT, KC_SPC,   KC_RGUI,          LOWER,   KC_AT,   KC_HASH, KC_PGDN
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |   _  |                    |   +  | 6    | 7    |  8   | 9    |   0  |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   ^  |   &  |   *  |   (  |   )  |   <  |                    |   >  | End  | Left | Down |  Up  | Right|  End |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   !  |   @  |   #  |   $  |   %  |   (  |                    |   )  |   _  |   =  |   <  |   >  |   ?  |PageUp|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  Alt |   ~  | RAISE||||||||  GUI | Raise| Space|||||||| Enter| Space|  Gui |||||||| Lower|   @  |   #  |PageDN|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    S(KC_W),                       S(KC_E),  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
    KC_TAB,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, S(KC_MINS),                    S(KC_EQL),  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,
    KC_LSFT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_9,                           KC_0,     S(KC_QUOT), KC_RBRC,  S(KC_W), S(KC_E), S(KC_Z), KC_PGUP,
    KC_LCTL, KC_LALT, KC_GRV, KC_DEL,            KC_LGUI, KC_BSPC, RAISE,         KC_ENT, KC_SPC,   KC_RGUI,          LOWER,   KC_AT,   KC_HASH, KC_PGDN
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |   _  |                    |   +  | 6    | 7    |  8   | 9    |   0  |   /  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   ^  |   &  |   *  |   (  |   )  |   -  |                    |   +  | End  | Left | Down |  Up  | Right|  End |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   -  |   +  |   /  |  *   |   ?  |PageUp|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  Alt |  ~   | RAISE||||||||  GUI | Raise| Space|||||||| Enter| Space|  Gui |||||||| Lower|   @  |   #  |PageDN|
   * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    S(KC_W),                        S(KC_E),  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC,
    KC_TAB,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LPRN,                        KC_RPRN,  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,
    KC_LSFT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_9,                           KC_0,     KC_QUOT, S(KC_RBRC), KC_LBRC, S(KC_8), S(KC_LBRC), KC_PGUP,
    KC_LCTL, KC_LALT, KC_GRV, KC_DEL,            KC_LGUI, KC_BSPC, RAISE,         KC_ENT, KC_SPC,   KC_RGUI,          LOWER,   KC_AT,   KC_HASH, KC_PGDN
  ),

    /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |                                  |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |                    |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6 ,_______,                       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

