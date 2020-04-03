/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0007
#define DEVICE_VER 		0x0001
#define MANUFACTURER    tmaurice
#define PRODUCT         16Key
#define DESCRIPTION     Thomas 16keys pad
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

/* 16Key PCB default pin-out */
#define MATRIX_ROW_PINS { D0, D1, D3, D4 }
#define MATRIX_COL_PINS { C0, C1, C2, C3 }
//#define UNUSED_PINS

#define RGB_DI_PIN D5
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 4
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10

// Bootmagic config
#define BOOTMAGIC_KEY_SALT KC_A
#define BOOTMAGIC_KEY_EEPROM_CLEAR KC_C

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define TAPPING_TERM 250

#define UNICODE_SELECTED_MODES UC_LNX, UC_WIN, UC_OSX
#define UNICODE_CYCLE_PERSIST false
#define OLED_DISPLAY_128X64

#endif
