// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NAV,
    _MOUSE,
    _NUM,
    _SYM,
    _FUN
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* ┌───┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │ Q │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │
    * ├───┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │ A │S/ALT│D/CMD│F/SFT│  G  │       │  H  │J/SFT│K/CMD│L/ALT│  ;  │
    * ├───┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │ Z │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │
    * └───┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *               ┌───┬───┐                   ┌───┬───┐
    *               │   │ESC├───┐           ┌───┤DEL│   │
    *               └───┴───┤BSP├───┐   ┌───┤SPC├───┴───┘
    *                       └───┤TAB│   │ENT├───┘
    *                           └───┘   └───┘
    */
    /* Base */
    [_QWERTY] = LAYOUT(
        KC_Q,      KC_W,        KC_E,        KC_R,        KC_T,  /**/  KC_Y,    KC_U,        KC_I,        KC_O,        KC_P,
        KC_A,      ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,  /**/  KC_H,    SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), KC_P,
        KC_Z,      KC_X,        KC_C,        KC_V,        KC_B,  /**/  KC_N,    KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,
        /*NO-KEY*/ KC_LSFT, KC_ESC, LT(_NAV,KC_BSPC), LT(_MOUSE,KC_TAB), /**/ LT(_SYM,KC_ENT),  LT(_NUM,KC_SPACE),     LT(_FUN,KC_DEL),     KC_RSFT      /*NO-KEY*/
    ),
    /* Navigation */
    [_NAV] = LAYOUT(
        XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   KC_LALT,   KC_LCTL,  KC_LSFT,    XXXXXXX,         XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,
        XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        /*NO-KEY*/ XXXXXXX,   XXXXXXX,  _______,    XXXXXXX,         KC_ENT,     KC_BSPC,    KC_DEL,     XXXXXXX   /*NO-KEY*/
    ),
    /* Mouse */
    [_MOUSE] = LAYOUT(
        XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   KC_LALT,   KC_LCTL,  KC_LSFT,    XXXXXXX,         XXXXXXX,    MS_LEFT,    MS_DOWN,    MS_UP,      MS_RGHT,
        XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,         XXXXXXX,    MS_WHLL,    MS_WHLD,    MS_WHLU,    MS_WHLR,
        /*NO-KEY*/ XXXXXXX,   XXXXXXX,  XXXXXXX,    _______,         MS_BTN1,    MS_BTN2,    MS_BTN3,     XXXXXXX   /*NO-KEY*/
    ),
    /* Number */
    [_NUM] = LAYOUT(
        KC_LBRC,   KC_7,      KC_8,     KC_9,       KC_RBRC,        XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        KC_SCLN,   KC_4,      KC_5,     KC_6,       KC_EQUAL,       XXXXXXX,      KC_RSFT,  KC_RCTL,   KC_RALT,  XXXXXXX,
        KC_GRAVE,  KC_1,      KC_2,     KC_3,       KC_BSLS,        XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        /*NO-KEY*/ XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,        XXXXXXX,   _______,  XXXXXXX,   XXXXXXX  /*NO-KEY*/
    ),
    /* Symbol */
   /* ┌───┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │ Q │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │
    * ├───┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │ A │S/ALT│D/CMD│F/SFT│  G  │       │  H  │J/SFT│K/CMD│L/ALT│  ;  │
    * ├───┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │ Z │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │
    * └───┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *               ┌───┬───┐                   ┌───┬───┐
    *               │   │ESC├───┐           ┌───┤DEL│   │
    *               └───┴───┤BSP├───┐   ┌───┤SPC├───┴───┘
    *                       └───┤TAB│   │ENT├───┘
    *                           └───┘   └───┘
    */
    [_SYM] = LAYOUT(
        KC_LCBR,   KC_AMPR,   KC_ASTR,  KC_LPRN,    KC_RCBR,         XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        KC_COLN,   KC_DLR,    KC_PERC,  KC_CIRC,    KC_PLUS,         XXXXXXX,      KC_RSFT,  KC_RCTL,   KC_RALT,  XXXXXXX,
        KC_TILD,   KC_EXLM,   KC_AT,    KC_HASH,    KC_PIPE,         XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        /*NO-KEY*/  XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,        _______,  XXXXXXX,  XXXXXXX,   XXXXXXX  /*NO-KEY*/
    ),
    [_FUN] = LAYOUT(
        KC_F12,      KC_F7,     KC_F8,    KC_F9,        XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        KC_F11,      KC_F4,     KC_F5,    KC_F6,        XXXXXXX,     XXXXXXX,  KC_RSFT,  KC_RCTL,   KC_RALT,  XXXXXXX,
        KC_F10,      KC_F1,     KC_F2,    KC_F3,        XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        /*NO-KEY*/   XXXXXXX,   XXXXXXX,  XXXXXXX,      XXXXXXX,     XXXXXXX,  XXXXXXX,  _______,   XXXXXXX  /*NO-KEY*/
    )
};
