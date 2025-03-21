// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* ┌─────┬─────┬─────┬─────┬─────┬─────┐
    * │ ESC │  F1 │ F2  │ F3  │ F4  │ F5  │
    * ├─────┼─────┼─────┼─────┼─────┼─────┤
    * │ TAB │  Q  │  W  │  E  │  R  │  T  │
    * ├─────┼─────┼─────┼─────┼─────┼─────┤
    * │CAPSL│  A  │  S  │  D  │  F  │  B  │
    * ├─────┼─────┼─────┼─────┼─────┼─────┤
    * │SHIFT│  Z  │  X  │  C  │  V  │  M  │
    * └─────┴─────┴─────┴─────┴─────┴─────┘
    *                     ┌────┐
    *                     │CRTL├────┐
    *                     └────┤SPC ├────┐
    *                          └────┤LALT|
     *                              └────┘
    */
    /* Base */
    [0] = LAYOUT(
        KC_ESC,  KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,
        KC_TAB,  KC_Q,  KC_W,  KC_E,    KC_R,    KC_T,
        KC_CAPS, KC_A,  KC_S,  KC_D,    KC_F,    KC_B,
        KC_LSFT, KC_Z,  KC_X,  KC_C,    KC_V,    KC_M,
        /*NO-KEY*//*NO-KEY*/   KC_LCTL, KC_SPC, KC_LALT
    ),
};
