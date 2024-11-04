// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_hungarian.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐┌───┬───┬───┬         ┌───┬───┬───┬───┐┌───┬───┬───┬
     * │esc│ 0 │ 1 │ 2 ││ 3 │ 4 │ 5 │         │ 6 │ 7 │ 8 │ 9 ││ Ö │ Ü │ Ó │
     * ├───┼───┼───┼───┤├───┼───┼───┼         ├───┼───┼───┼───┤├───┼───┼───┼
     * │   │tab│ Q │ W ││ E │ R │ T │         │ Z │ U │ I │ O ││ P │ Ő │ Ú │
     * ├───┼───┼───┼───┤├───┼───┼───┼         ├───┼───┼───┼───┤├───┼───┼───┼
     * │   │shf│ A │ S ││ D │ F │ G │         │ H │ J │ K │ L ││ É │ Á │ Ű │
     * ├───┼───┼───┼───┤├───┼───┼───┼         ├───┼───┼───┼───┤├───┼───┼───┼
     * │ctr│ Í │ Y │ X ││ C │ V │ B │         │ N │ M │ , │ . ││ - │   │   │
     * └───┴───┴───┴───┘└───┴───┴───┴         └───┴───┴───┴───┘└───┴───┴───┴
     *               ───┼───┼───┼───┤          ───┼───┼───┼───┤
     *              │ 5 │alt│spa│ fn│         │del│ent│bsp│   │
     *              └───┴───┴───┴───┘         └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,   KC_0,    KC_1,   KC_2,   KC_3,    KC_4,   KC_5,         KC_6,   KC_7,   KC_8,     KC_9,   HU_ODIA,   HU_UDIA,   HU_OACU,
        KC_NO,    KC_TAB,  KC_Q,   KC_W,   KC_E,    KC_R,   KC_T,         KC_Z,   KC_U,   KC_I,     KC_O,   KC_P,      HU_ODAC,   HU_UACU,
        KC_NO,    KC_LSFT, KC_A,   KC_S,   KC_D,    KC_F,   KC_G,         KC_H,   KC_J,   KC_K,     KC_L,   HU_EACU,   HU_AACU,   HU_UDAC,
        KC_LCTL,  HU_IACU, KC_Y,   KC_X,   KC_C,    KC_V,   KC_B,         KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_MINUS,  KC_NO,     KC_NO,
                           KC_5,   KC_NO,  KC_LALT, KC_SPC, KC_NO,        KC_DEL, KC_ENT, KC_BSPC,  KC_NO
    )
};
