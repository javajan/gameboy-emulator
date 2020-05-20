#ifndef _GB_MEMORYH
#define _GB_MEMORYH

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

#define GB_INT_FLAG 0xFF0F

#define GB_INT_VBLANK 	0x01
#define GB_INT_LCD 		0x02
#define GB_INT_TIMER 	0x03
#define GB_INT_SERIAL 	0x04
#define GB_INT_JOYPAD 	0x05


memory_t gb_init_memory(uint8_t*, uint16_t);

void gb_mem_write(memory_t*, uint16_t, uint8_t);
uint8_t gb_mem_read(memory_t*, uint16_t);

#endif
