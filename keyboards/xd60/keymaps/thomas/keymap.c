#include QMK_KEYBOARD_H
#include "action_layer.h"

#define _BASE 0
#define _FN   1

enum custom_keycodes {
  SHRUG = SAFE_RANGE,
  LENNY,
  DISAP
};

enum unicode_names {
    POOP
};

const uint32_t PROGMEM unicode_map[] = {
    [POOP]  = 0x1F4A9
};

qk_tap_dance_action_t tap_dance_actions[] = {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHRUG:
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            break;
        case LENNY:
            if (record->event.pressed) {
                send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
            }
            break;
        case DISAP:
            if (record->event.pressed) {
                send_unicode_hex_string("0CA0 005F 0CA0");
            }
    }

  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_DEL,  KC_BSPC,   \
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,          KC_BSLS,   \
      KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,            KC_ENT,    \
      KC_LSFT,  KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  MO(_FN), KC_UP,   KC_RSFT,   \
      KC_LCTL,  KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RIGHT),
  [_FN] = LAYOUT_all(
      KC_TILDE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,  KC_F13,  KC_F14,  \
      LENNY,      UNICODE_MODE_FORWARD,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, X(POOP),  KC_TRNS,   KC_TRNS, KC_TRNS, \
      KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PGUP,   KC_TRNS,          SHRUG,   \
      KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_PGUP, KC_INS,  \
      KC_LCTL,    DISAP,   KC_LALT,                           KC_SPC,                          KC_RGUI, F(0), KC_TRNS, KC_PGDOWN,  KC_TRNS),
};
