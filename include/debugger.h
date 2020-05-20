#ifndef _GB_DEBUGGERH
#define _GB_DEBUGGERH

#include "types.h"
#include "gameboy.h"

void gb_debug(gameboy_t*);

void gb_print_disassembly(gameboy_t, uint16_t, uint16_t);
void gb_print_stack(gameboy_t*, uint16_t, uint16_t);
void gb_print_registers(gameboy_t);

#endif
