#include QMK_KEYBOARD_H
#define MAX_MACRO_SIZE 128
#define MACRO_ADDR(macro) (uint16_t)&(macro)
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

char macroBuffer[MAX_MACRO_SIZE];

const char macroShrug[] PROGMEM = "00AF 005C 005F 0028 30C4 0029 005F 002F 00AF";
const char macroLenny[] PROGMEM = "0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029";
const char macroDisap[] PROGMEM = "0CA0 005F 0CA0";
const char macroTableFlip[] PROGMEM = "0028 256F 00B0 25A1 00B0 FF09 256F FE35 0020 253B 2501 253B";
const char macroAngry[] PROGMEM = "10DA 0028 0CA0 76CA 0CA0 10DA 0029";
const char macroCrying[] PROGMEM = "0CA5 FE4F 0CA5";
const char macroThrow[] PROGMEM = "0028 30CE 0CA0 0020 2229 0CA0 0029 30CE 5F61 0028 0020 005C 006F 00B0 006F 0029 005C";
const char macroBoi[] PROGMEM = "1F171 1F17E 2139 FE0F";

void load_macro_in_buffer(uint16_t addr) {
  char b = ' ';
  for (uint16_t ptr = addr; b != '\0'; ptr++) {
    b = pgm_read_byte(ptr);
    macroBuffer[ptr-addr] = b;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SHRUG:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroShrug));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case LENNY:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroLenny));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case DISAP:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroDisap));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case TABFLIP:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroTableFlip));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case ANGRY:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroAngry));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case CRYING:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroCrying));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case THROW:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroThrow));
        send_unicode_hex_string(macroBuffer);
      }
      break;
    case BOI:
      if (record->event.pressed) {
        load_macro_in_buffer(MACRO_ADDR(macroBoi));
        send_unicode_hex_string(macroBuffer);
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

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("base\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("rgb\n"), false);
            break;
        case _MACROS:
            oled_write_P(PSTR("macros\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif