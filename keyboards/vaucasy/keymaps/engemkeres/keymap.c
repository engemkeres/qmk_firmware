// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_hungarian.h"

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#endif

enum layer_names {
    _BASE,
    _FUNC,
    _MOUS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐┌───┬───┬───┬         ┌───┬───┬───┬───┐┌───┬───┬───┬
     * │esc│ 0 │ 1 │ 2 ││ 3 │ 4 │ 5 │         │ 6 │ 7 │ 8 │ 9 ││ Ö │ Ü │ Ó │
     * ├───┼───┼───┼───┤├───┼───┼───┼         ├───┼───┼───┼───┤├───┼───┼───┼
     * │cap│tab│ Q │ W ││ E │ R │ T │         │ Z │ U │ I │ O ││ P │ Ő │ Ú │
     * ├───┼───┼───┼───┤├───┼───┼───┼         ├───┼───┼───┼───┤├───┼───┼───┼
     * │win│shf│ A │ S ││ D │ F │ G │         │ H │ J │ K │ L ││ É │ Á │ Ű │
     * ├───┼───┼───┼───┤├───┼───┼───┼         ├───┼───┼───┼───┤├───┼───┼───┼
     * │ctr│ Í │ Y │ X ││ C │ V │ B │         │ N │ M │ , │ . ││ - │alg│   │
     * └───┴───┴───┴───┘└───┴───┴───┴         └───┴───┴───┴───┘└───┴───┴───┴
     *               ───┼───┼───┼───┤          ───┼───┼───┼───┤
     *              │pla│alt│spa│ fn│         │del│ent│bsp│cpl│
     *              └───┴───┴───┴───┘         └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_4x7(
        KC_ESC,   HU_0,               KC_1,      KC_2,    KC_3,    KC_4,               KC_5,    KC_6,    KC_7,     KC_8,     KC_9,    HU_ODIA,  HU_UDIA,  HU_OACU,
        CW_TOGG,  KC_TAB,             KC_Q,      KC_W,    KC_E,    KC_R,               KC_T,    HU_Z,    KC_U,     KC_I,     KC_O,    KC_P,     HU_ODAC,  HU_UACU,
        KC_LWIN,  KC_LSFT,            KC_A,      KC_S,    KC_D,    LT(_MOUS, KC_F),    KC_G,    KC_H,    KC_J,     KC_K,     KC_L,    HU_EACU,  HU_AACU,  HU_UDAC,
        KC_LCTL,  LT(_MOUS, HU_IACU), HU_Y,      KC_X,    KC_C,    KC_V,               KC_B,    KC_N,    KC_M,     KC_COMMA, KC_DOT,  HU_MINS,  KC_ALGR,  KC_NO,
                                      KC_MPLY,   KC_LALT, KC_SPC,  MO(_FUNC),          KC_DEL,  KC_ENT,  KC_BSPC,  KC_CPNL
    ),

    [_FUNC] = LAYOUT_4x7(
        _______,  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,      KC_F6  , KC_F7  , KC_F8  ,  KC_F9  , KC_F10 ,  KC_F11 ,  KC_F12,
        _______,  _______, _______, _______, _______, _______, _______,      _______, _______, KC_UP  ,  _______, _______,  KC_HOME,  KC_PGUP,
        _______,  _______, _______, _______, _______, _______, _______,      _______, KC_LEFT, KC_DOWN,  KC_RGHT, _______,  KC_END ,  KC_PGDN,
        _______,  _______, _______, _______, _______, _______, _______,      _______, _______, _______,  _______, _______,  _______,  _______,
                                    _______, _______, _______, _______,      _______, KC_PSCR, _______,  _______
    ),

    [_MOUS] = LAYOUT_4x7(
        _______,  _______, _______, _______, _______, _______, _______,      _______, _______, _______,  _______, _______,  _______,  _______,
        _______,  _______, _______, _______, _______, _______, _______,      _______, _______, MS_UP  ,  _______, _______,  _______,  _______,
        _______,  _______, _______, _______, _______, _______, _______,      _______, MS_LEFT, MS_DOWN,  MS_RGHT, MS_WHLU,  _______,  _______,
        _______,  _______, _______, _______, _______, _______, _______,      _______, _______, _______,  _______, MS_WHLD,  _______,  _______,
                                    _______, _______, _______, _______,      MS_BTN3, MS_BTN1, MS_BTN2,  _______
    )


};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_FUNC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_MOUS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
};
#endif

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
#include "demon.c"
#endif

// -- Probably some other stuff and then --

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_anim();
  } else {
    oled_set_cursor(0,1);
    oled_write("vaucasy - ergonomic\n split mechanical\n keyboard",false);
  }
  return false;
}
#endif
