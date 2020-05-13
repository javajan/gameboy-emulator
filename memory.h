#ifndef _GB_MEMORYH
#define _GB_MEMORYH

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

void gb_init_memory(memory_t*, uint8_t*, uint16_t, uint8_t*, uint16_t);

void gb_mem_write(memory_t*, uint16_t, uint8_t);
uint8_t gb_mem_read(memory_t*, uint16_t);

#endif
