#include <util/delay.h>
#include "16keys_thomas.h"

// LED1 is the right one
// LED2 is the left one

void turn_on_led1(void) {
	PORTB |= (1<<0);
}

void turn_off_led1(void) {
	PORTB &= ~(1<<0);
}

void turn_on_led2(void) {
	PORTB |= (1<<1);
}

void turn_off_led2(void) {
	PORTB &= ~(1<<1);
}

void matrix_init_kb(void) {
	DDRB |= (1<<1);
	DDRB |= (1<<0);

	for(int i = 0; i < 3; i++) {
		turn_on_led1();
		turn_on_led2();
		_delay_ms(50);
		turn_off_led1();
		turn_off_led2();
		_delay_ms(50);
	}

	matrix_init_user();
	set_unicode_input_mode(UC_LNX);
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _BASE:
		turn_off_led1();
		turn_off_led2();
        break;
    case _RGB:
		turn_on_led1();
		turn_off_led2();
        break;
    case _MACROS:
		turn_off_led1();
		turn_on_led2();
        break;
    default:
		turn_off_led1();
		turn_off_led2();
        break;
    }
  return state;
}