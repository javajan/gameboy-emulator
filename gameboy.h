#ifndef _GB_GAMEBOYH
#define _GB_GAMEBOYH

#include <stdint.h>
#include <stdbool.h>

#include "types.h"
#include "memory.h"


// flag bit positions
#define GB_FLAG_ZERO 7
#define GB_FLAG_NEGATIVE 6
#define GB_FLAG_HALF_CARRY 5
#define GB_FLAG_CARRY 4


extern const instruction_t gb_base_instructions[256];
extern const instruction_t gb_cb_instructions[256];

void gb_init(gameboy_t*, uint8_t*, uint16_t, uint8_t*, uint16_t);
void gb_stop(gameboy_t*);

void gb_run(gameboy_t*);
void gb_execute(gameboy_t*);

void gb_flag_reset(gameboy_t* gameboy);
void gb_flag_set(gameboy_t*, int, bool);
void gb_flag_flip(gameboy_t*, int);
bool gb_flag_get(gameboy_t, int);

void gb_stop(gameboy_t*);
void gb_halt(gameboy_t*);
void gb_enable_interrupts(gameboy_t*);
void gb_disable_interrupts(gameboy_t*);

// read immediates (values after instruction)
uint8_t gb_read_n(gameboy_t*);
uint16_t gb_read_nn(gameboy_t*);

void gb_print_disassembly(gameboy_t, uint16_t, uint16_t);
void gb_print_registers(gameboy_t);


#endif
