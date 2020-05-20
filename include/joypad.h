#ifndef _GB_JOYPADH
#define _GB_JOYPADH

#include <stdint.h>
#include "memory.h"

#define GB_JOYPAD_MODE_DPAD 	1
#define GB_JOYPAD_MODE_BUTTONS 	2
#define GB_JOYPAD_MODE_NONE 	0

#define GB_JOYPAD_PRESSED 	1
#define GB_JOYPAD_RELEASED 	0

#define GB_JOYPAD_A 		0
#define GB_JOYPAD_B 		1
#define GB_JOYPAD_SELECT 	2
#define GB_JOYPAD_START 	3
#define GB_JOYPAD_RIGHT 	4
#define GB_JOYPAD_LEFT 		5
#define GB_JOYPAD_UP 		6
#define GB_JOYPAD_DOWN 		7

void gb_joypad_reset(memory_t*);
void gb_joypad_set(memory_t*, uint8_t flag, uint8_t state);
uint8_t gb_joypad_mode(memory_t*);

#endif
