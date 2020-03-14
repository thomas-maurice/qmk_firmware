#include QMK_KEYBOARD_H

enum {
  TD_5_ENT = 0
};

enum custom_keycodes {
  SHRUG = SAFE_RANGE,
  LENNY,
  DISAP,
  TABFLIP,
  ANGRY,
  CRYING,
  THROW,
  BOI
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
      break;
    case TABFLIP:
      if (record->event.pressed) {
          send_unicode_hex_string("0028 256F 00B0 25A1 00B0 FF09 256F FE35 0020 253B 2501 253B");
      }
      break;
    case ANGRY:
      if (record->event.pressed) {
          send_unicode_hex_string("10DA 0028 0CA0 76CA 0CA0 10DA 0029");
      }
      break;
    case CRYING:
      if (record->event.pressed) {
          send_unicode_hex_string("0CA5 FE4F 0CA5");
      }
      break;
    case THROW:
      if (record->event.pressed) {
          send_unicode_hex_string("0028 30CE 0CA0 0020 2229 0CA0 0029 30CE 5F61 0028 0020 005C 006F 00B0 006F 0029 005C");
      }
      break;
    case BOI:
      if (record->event.pressed) {
          send_unicode_hex_string("1F171 1F17E 2139 FE0F");
      }
      break;
  }

  return true;
};

enum unicode_names {
    POOP
};

const uint32_t PROGMEM unicode_map[] = {
    [POOP]  = 0x1F4A9
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
    KC_A,          KC_B,                          KC_C,        KC_D, \
    KC_E,          KC_F,                          KC_G,        KC_H, \
    KC_I,          KC_J,                          KC_K,        KC_L, \
    MO(_MACROS),   KC_N,                          KC_O,        MO(_RGB) \
  ),
  [_RGB] = LAYOUT( \
    RGB_TOG,       RGB_MODE_REVERSE,              RGB_MODE_FORWARD,        RGB_MODE_RGBTEST, \
    RGB_HUI,       RGB_SAI,                       RGB_VAI,                 KC_NO, \
    KC_NO,         KC_NO,                         KC_NO,                   KC_NO, \
    KC_LSHIFT,     KC_NO,                         KC_NO,                   KC_NO \
  ),
  [_MACROS] = LAYOUT( \
    SHRUG,         BOI,                           DISAP,                  LENNY, \
    X(POOP),       TABFLIP,                       ANGRY,                  CRYING, \
    THROW,         KC_NO,                         KC_NO,                  KC_NO, \
    KC_NO,         KC_NO,                         KC_NO,                  KC_NO \
  )
};
