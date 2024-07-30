/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include "layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_4x6_5(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, /*                 */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             KC_HOME, KC_Q, KC_W, KC_E, KC_R, KC_T, /*                */ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_END,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G, /*                */ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, /*                */ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             KC_LSFT, KC_SPC, KC_BSPC, /*                               */ TG(2), KC_ENT, KC_RGUI,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             KC_TAB, TG(1), /*                                      */ KC_DEL, KC_RCTL),

    [1] = LAYOUT_split_4x6_5(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, /*     */ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             QK_BOOT, _______, KC_UP, _______, _______, KC_LBRC, /*   */ KC_RBRC, KC_7, KC_8, KC_9, KC_DOT, KC_PLUS,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_LPRN, /*  */ KC_RPRN, KC_4, KC_5, KC_6, KC_MINS, KC_PIPE,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, /* */ KC_0, KC_1, KC_2, KC_3, KC_EQL, KC_UNDS,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, /*                            */ _______, _______, _______,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, /*                                     */ _______, _______),

    [2] = LAYOUT_split_4x6_5(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*             */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             QK_BOOT, _______, RGB_RMOD, RGB_TOG, RGB_MOD, _______, /* */ _______, _______, _______, _______, _______, KC_MUTE,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, /* */ _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, KC_VOLD,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, /*                            */ _______, _______, _______,
                             //-----------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, /*                                     */ _______, _______),
};

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE); // Start-up color
}

void set_rgb_matrix_by_layer(uint32_t layer) {
    switch (layer) {
        case _BASE:
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case _NUMPAD:
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            break;
        case _FUNC_KEYS:
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_rgb_matrix_by_layer(biton32(state));
    return state;
}
