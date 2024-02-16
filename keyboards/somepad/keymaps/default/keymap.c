// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    D_ZERO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case D_ZERO:
        if (record->event.pressed)
            SEND_STRING(SS_TAP(X_P0) SS_TAP(X_P0));
        break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │Esc│Tab│MO1│Bsp│
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,  KC_TAB,  TG(1),   KC_BSPC,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_COMM, KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┐───┬───┬───┐
     * │Rst│Tab│MO1│Bsp│
     * └───┘───┼───┼───┤
     * │Num│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [1] = LAYOUT(
        _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_BTN1, KC_MS_U, KC_BTN2,
        KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,
        KC_BTN4, KC_BTN3, KC_BTN5,
        KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_D
    )
};
