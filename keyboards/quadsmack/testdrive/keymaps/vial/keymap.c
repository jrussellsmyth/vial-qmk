// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "quantum.h"


#define MATRIX_ROWS 8
#define MATRIX_COLS 5

enum layers {
    _BASE,
    _NUMPAD,
    _FUNCTIONS,
    _SHIFTED_SYMBOLS,
    _UNUSED_4,
    _UNUSED_5,
    _UNUSED_6,
    _UNUSED_7
};

// Keymap layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base Layer (QWERTY with HRM)
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,      KC_H,    LCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_SLASH,
                          KC_NO,   MO(1),   MO(2),     LT(1, KC_SPACE), MO(3),   KC_NO
    ),

    // Layer 1: Numpad Layer
    [_NUMPAD] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_KP_SLASH, KC_7, KC_8, KC_9, KC_MINUS,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_QUOTE,  KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS,
        KC_GRAVE, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_COMMA, KC_1, KC_2, KC_3, KC_DOT,
                           KC_NO,   KC_TRNS, KC_NO,     KC_KP_DOT, KC_0, KC_KP_ENTER
    ),

    // Layer 2: Function Keys and Editing
    [_FUNCTIONS] = LAYOUT_split_3x5_3(
        KC_ESCAPE,  LGUI(KC_MINUS), KC_NO, SGUI(KC_MINUS), KC_F12,  KC_PGUP, KC_HOME, KC_UP, KC_END, KC_DELETE,
        KC_TAB,     KC_LALT,    KC_LSFT, KC_LCTL, KC_LGUI,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC,
        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,     KC_NO,   KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,
                                KC_NO,   KC_NO,   KC_TRNS,       KC_SPACE, KC_ENTER, OSM(MOD_LALT | MOD_LGUI)
    ),

    // Layer 3: Shifted Symbols
    [_SHIFTED_SYMBOLS] = LAYOUT_split_3x5_3(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_SLASH), KC_QUOTE,
        KC_NO,   KC_NO,   LSFT(KC_9), LSFT(KC_0), LSFT(KC_QUOTE), LSFT(KC_SCLN), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_LBRC, KC_RBRC,
        LSFT(KC_COMMA), LSFT(KC_BSLS), KC_MINUS, LSFT(KC_DOT), KC_SLASH, KC_GRAVE, LSFT(KC_MINUS), KC_SLASH, LSFT(KC_GRAVE), KC_SCLN,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_UNUSED_4] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_UNUSED_5] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 6: Empty
    [_UNUSED_6] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 7: Custom Shifted Layer
    [_UNUSED_7] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};


#ifdef RGBLIGHT_ENABLE
void keyboard_pre_init_kb(void) {
    // Enable the power pin for the Xiao Seeed rp2040 onboard NeoPixel
    gpio_set_pin_output(GP11);
    gpio_write_pin_high(GP11);
    keyboard_pre_init_user();
}
#endif
