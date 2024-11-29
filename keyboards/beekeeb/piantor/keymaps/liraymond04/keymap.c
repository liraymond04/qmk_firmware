// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT),
        KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                                            MO(_LOWER), KC_SPC, KC_LCTL,        MO(_RAISE), KC_SPC,  KC_LALT
    ),
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LSFT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
        KC_LALT, MO(_ADJUST), KC_AUDIO_MUTE, KC_KB_VOLUME_DOWN, KC_AUDIO_VOL_UP, OSM(MOD_LGUI),   KC_MINS, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSPC,
                                            _______, OSM(MOD_LALT), KC_LCTL,    MO(_RAISE), KC_SPC,  KC_LALT
    ),
    [_RAISE] = LAYOUT_split_3x6_3(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_RPRN, KC_TILD,
        MO(_ADJUST), KC_Z,  KC_X,  KC_C,    KC_F11,  KC_F12,                             KC_MINS, KC_UNDS, KC_EQL,  KC_LCBR,  KC_RCBR, KC_BSLS,
                                            KC_LGUI, KC_LALT, KC_LCTL,           MO(_RAISE),  KC_ENT,  KC_SPC
    ),
    [_ADJUST] = LAYOUT_split_3x6_3(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_LSFT, KC_EXLM, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,                            KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_INS,  KC_PSCR,
        KC_LCTL, _______, QK_LOCK, KC_CAPS, OSM(MOD_LALT), OSM(MOD_LGUI),                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                                            _______, KC_BSPC, KC_LCTL,           MO(_RAISE),  KC_ENT,  KC_SPC
    ),
};
