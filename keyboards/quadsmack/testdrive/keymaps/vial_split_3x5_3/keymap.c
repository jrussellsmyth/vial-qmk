// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define KC_ZSHFT SFT_T(KC_Z)
#define KC_SLSHSFT SFT_T(KC_SLSH)
#define LCTL_ENT LCTL_T(KC_ENT)
#define LALT_SPC LALT_T(KC_SPC)


#include "quantum.h"

#include QMK_KEYBOARD_H

// Define custom keycodes for macros
enum custom_keycodes {
    KC_MACRO_SCREENSHOT = SAFE_RANGE // Custom keycode for LCTL(LSFT(KC_4)) (Vial Macro M2)
};

// Combo definitions
// Combo for KC_Z + KC_X to trigger KC_MACRO_SCREENSHOT (Vial M2)
const uint16_t PROGMEM combo_z_x[] = {KC_Z, KC_X, COMBO_END};
// Combo for LALT_T(KC_L) + LGUI_T(KC_SCOLON) to trigger KC_MINUS
const uint16_t PROGMEM combo_lalt_l_lgui_scol[] = {LALT_T(KC_L), LGUI_T(KC_SCLN), COMBO_END};
// Combo for LSFT(KC_1) + LSFT(KC_2) to trigger LSFT(KC_GRAVE)
const uint16_t PROGMEM combo_lsft_1_lsft_2[] = {LSFT(KC_1), LSFT(KC_2), COMBO_END};
// Combo for KC_6 + KC_KP_PLUS to trigger KC_EQUAL
const uint16_t PROGMEM combo_6_kp_plus[] = {KC_6, KC_KP_PLUS, COMBO_END};
// Combo for KC_9 + KC_MINUS to trigger LSFT(KC_GRAVE)
const uint16_t PROGMEM combo_9_minus[] = {KC_9, KC_MINUS, COMBO_END};
// Combo for KC_KP_SLASH + KC_7 to trigger LSFT(KC_6)
const uint16_t PROGMEM combo_kp_slash_7[] = {KC_KP_SLASH, KC_7, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_z_x, KC_MACRO_SCREENSHOT),
    COMBO(combo_lalt_l_lgui_scol, KC_MINUS),
    COMBO(combo_lsft_1_lsft_2, LSFT(KC_GRAVE)),
    COMBO(combo_6_kp_plus, KC_EQUAL),
    COMBO(combo_9_minus, LSFT(KC_GRAVE)),
    COMBO(combo_kp_slash_7, LSFT(KC_6)),
};

// Process record user function for custom keycodes and macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MACRO_SCREENSHOT: // Mac Screenshot
            if (record->event.pressed) {
                // Press LCTL + LSHIFT + 4
                register_mods(MOD_LCTL | MOD_LSFT);
                tap_code(KC_4);
            } else {
                // Release LCTL + LSHIFT
                unregister_mods(MOD_LCTL | MOD_LSFT);
            }
            return false; // Do not process this keycode further
    }
    return true; // Continue processing other keycodes
}

// Define the matrix dimensions based on your VIAL layout
// Note: These define the logical matrix size for the keymaps array.
// The LAYOUT_split_3x5_3 macro handles mapping these to the physical pins.
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// Keymap layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base Layer (QWERTY-like with custom modifiers)
    /*
     * ,----------------------------.   ,----------------------------.
     * |  Q   |  W   |  E   |  R   |  T   |   |  Y   |  U   |  I   |  O   |  P   |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | LG(A)| LA(S)| LS(D)| LC(F)|  G   |   |  H   | LC(J)| RS(K)| LA(L)|LG(SC)|
     * |------+------+------+------+------|   |------+------+------+------+------|
     * |  Z   |  X   |  C   |  V   |  B   |   |  N   |  M   |  ,   |  .   |  /   |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  | MO(1)| MO(2)|                      |LT(1,S)| MO(3)|  NO  |
     * `------------'                      `------------'
     */
    [0] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,      KC_H,    LCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_SLASH,
        KC_NO,   MO(1),   MO(2),   // Left thumb keys (from VIAL row 3, skipping -1, -1, KC_NO)
        LT(1, KC_SPACE), MO(3),   KC_NO    // Right thumb keys (from VIAL row 7, skipping -1, -1)
    ),

    // Layer 1: Numbers and Symbols
    /*
     * ,----------------------------.   ,----------------------------.
     * |  NO  |  NO  |  NO  |  NO  |  NO  |   |  /   |  7   |  8   |  9   |  -   |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | LGUI | LALT | LSHFT| LCTRL|  '   |   |  * |  4   |  5   |  6   |  +   |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * |  `   |  NO  |  NO  |  NO  |  NO  |   |  ,   |  1   |  2   |  3   |  .   |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  | TRNS |  NO  |                      |  .   |  0   |ENTER |
     * `------------'                      `------------'
     */
    [1] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_KP_SLASH, KC_7, KC_8, KC_9, KC_MINUS,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_QUOTE,  KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS,
        KC_GRAVE, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_COMMA, KC_1, KC_2, KC_3, KC_DOT,
        KC_NO,   KC_TRNS, KC_NO,   // Left thumb keys (from VIAL row 3, skipping -1, -1)
        KC_KP_DOT, KC_0, KC_KP_ENTER // Right thumb keys (from VIAL row 7, skipping -1, -1)
    ),

    // Layer 2: Function Keys and Editing
    /*
     * ,----------------------------.   ,----------------------------.
     * | ESC  | LG(-) |  NO  | SG(-)| F12  |   | PGUP | HOME |  UP  | END  | DEL  |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | TAB  | LALT | LSHFT| LCTRL| LGUI |   | PGDN | LEFT | DOWN |RIGHT | BSPC |
     * |------+------+------+------+------+------|   |------+------+------+------+------|
     * | LC(Z)| LC(X)| LC(C)| LC(V)|  NO  |   |  NO  | VOLD | VOLU | MPRV | MNXT |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  |  NO  | TRNS |                      | SPC  |ENTER | OSM  |
     * `------------'                      `------------'
     */
    [2] = LAYOUT_split_3x5_3(
        KC_ESCAPE, LGUI(KC_MINUS), KC_NO, SGUI(KC_MINUS), KC_F12,  KC_PGUP, KC_HOME, KC_UP, KC_END, KC_DELETE,
        KC_TAB,  KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC,
        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,     KC_NO,   KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,
        KC_NO,   KC_NO,   KC_TRNS, // Left thumb keys (from VIAL row 3, skipping -1, -1)
        KC_SPACE, KC_ENTER, OSM(MOD_LALT | MOD_LGUI) // Right thumb keys (from VIAL row 7, skipping -1, -1)
    ),

    // Layer 3: Shifted Symbols
    /*
     * ,----------------------------.   ,----------------------------.
     * | S(1) | S(2) | S(3) | S(4) | S(5) |   | S(6) | S(7) | S(8) | S(/) |  '   |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * |  NO  |  NO  | S(9) | S(0) | S(') |   | S(;) | S([) | S(]) |  [   |  ]   |
     * |------+------+------+------+------+------|   |------+------+------+------+------|
     * | S(,) | S(\) |  -   | S(.) |  \   |   |  `   | S(-) |  /   | S(`) |  ;   |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  | TRNS | TRNS |                      | TRNS | TRNS | TRNS |
     * `------------'                      `------------'
     */
    [3] = LAYOUT_split_3x5_3(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_SLASH), KC_QUOTE,
        KC_NO,   KC_NO,   LSFT(KC_9), LSFT(KC_0), LSFT(KC_QUOTE), LSFT(KC_SCLN), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_LBRC, KC_RBRC,
        LSFT(KC_COMMA), LSFT(KC_BSLS), KC_MINUS, LSFT(KC_DOT), KC_SLASH, KC_GRAVE, LSFT(KC_MINUS), KC_SLASH, LSFT(KC_GRAVE), KC_SCLN,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 4: Empty
    /*
     * ,----------------------------.   ,----------------------------.
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------|   |------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  | TRNS | TRNS |                      | TRNS | TRNS | TRNS |
     * `------------'                      `------------'
     */
    [4] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, // Left thumb keys (from VIAL row 3, skipping -1, -1)
        KC_TRNS, KC_TRNS, KC_TRNS  // Right thumb keys (from VIAL row 7, skipping -1, -1)
    ),

    // Layer 5: Empty
    /*
     * ,----------------------------.   ,----------------------------.
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------|   |------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  | TRNS | TRNS |                      | TRNS | TRNS | TRNS |
     * `------------'                      `------------'
     */
    [5] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, // Left thumb keys (from VIAL row 3, skipping -1, -1)
        KC_TRNS, KC_TRNS, KC_TRNS  // Right thumb keys (from VIAL row 7, skipping -1, -1)
    ),

    // Layer 6: Empty
    /*
     * ,----------------------------.   ,----------------------------.
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------|   |------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  | TRNS | TRNS |                      | TRNS | TRNS | TRNS |
     * `------------'                      `------------'
     */
    [6] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, // Left thumb keys (from VIAL row 3, skipping -1, -1)
        KC_TRNS, KC_TRNS, KC_TRNS  // Right thumb keys (from VIAL row 7, skipping -1, -1)
    ),

    // Layer 7: Custom Shifted Layer
    /*
     * ,----------------------------.   ,----------------------------.
     * | S(H) | S(V) | S(T) | S(E) | S(A) |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------|   |------+------+------+------+------|
     * | S(R) | S(F) | S(D) | S(G) | S(X) |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * |------+------+------+------+------+------|   |------+------+------+------+------|
     * |  NO  |  NO  |  NO  |  NO  |  NO  |   | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `----------------------------'   `----------------------------'
     * ,------------.                      ,------------.
     * |  NO  |  NO  | ESC  |                      | TRNS | TRNS | TG(7)|
     * `------------'                      `------------'
     */
    [7] = LAYOUT_split_3x5_3(
        LSFT(KC_H), LSFT(KC_V), LSFT(KC_T), LSFT(KC_E), LSFT(KC_A), LSFT(KC_R), LSFT(KC_F), LSFT(KC_D), LSFT(KC_G), LSFT(KC_X),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_NO,   KC_ESCAPE, // Left thumb keys (from VIAL row 3, skipping -1, -1)
        KC_TRNS, KC_TRNS, TG(7)    // Right thumb keys (from VIAL row 7, skipping -1, -1)
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
