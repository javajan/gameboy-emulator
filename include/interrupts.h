#ifndef _GB_INTERRTUPS_H
#define _GB_INTERRTUPS_H

#include <stdint.h>
#include "types.h"

#define GB_INT_FLAG 0xFF0F

#define GB_INT_VBLANK 	0x01
#define GB_INT_LCD 		0x02
#define GB_INT_TIMER 	0x03
#define GB_INT_SERIAL 	0x04
#define GB_INT_JOYPAD 	0x05

void gb_interrupt_handle(gameboy_t*);
void gb_interrupt_request(memory_t*, uint8_t);

#endif
