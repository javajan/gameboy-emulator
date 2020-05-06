#include <stdio.h>
#include <stdlib.h>

#include "gameboy.h"

#define BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

void gb_init(gameboy_t* gameboy, uint8_t* rom, uint16_t romSize) {
	gameboy->cpu.a = 0x00;
	gameboy->cpu.b = 0x00;
	gameboy->cpu.c = 0x00;
	gameboy->cpu.d = 0x00;
	gameboy->cpu.e = 0x00;
	gameboy->cpu.h = 0x00;
	gameboy->cpu.l = 0x00;
	gameboy->cpu.f = 0x00;
	
	gameboy->cpu.sp = 0xFFFE;
	gameboy->cpu.pc = 0x0000;
	
	// Loads rom into memory and sets all other values to 0
	for (int i = 0; i < RAM_SIZE; i++) {
		if (i < romSize) {
			gb_mem_write(gameboy, i, rom[i]);
		}
		else {
			gb_mem_write(gameboy, i, 0);
		}
	}
}

void gb_execute(gameboy_t* gameboy) {
	uint16_t pc = gameboy->cpu.pc;
	gameboy->cpu.pc++;
	uint8_t opcode = gb_mem_read(gameboy, pc);
	
	instruction_t instr = gb_instructions[opcode];
	
	if (instr.execute == NULL) {
		printf("OPCODE %d NOT IMPLEMENTED\n", opcode);
	}
	else {
		instr.execute(gameboy);
	}
}

void gb_mem_write(gameboy_t* gameboy, uint16_t pos, uint8_t value) {
	gameboy->memory[pos] = value;
}

uint8_t gb_mem_read(gameboy_t* gameboy, uint16_t pos) {
	return gameboy->memory[pos];
}

void gb_stop(gameboy_t* gameboy) {
	
}

void gb_print_registers(gameboy_t gameboy) {
	cpu_t cpu = gameboy.cpu;
	
	printf("a: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.a));
	printf("b: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.b));
	printf("c: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.c));
	printf("d: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.d));
	printf("e: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.e));
	printf("h: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.h));
	printf("l: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.l));
	printf("f: " BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.f));
	
	printf("af: " BINARY_PATTERN "" BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.af>>8), BYTE_TO_BINARY(cpu.af));
	printf("bc: " BINARY_PATTERN "" BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.bc>>8), BYTE_TO_BINARY(cpu.bc));
	printf("de: " BINARY_PATTERN "" BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.de>>8), BYTE_TO_BINARY(cpu.de));
	printf("hl: " BINARY_PATTERN "" BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.hl>>8), BYTE_TO_BINARY(cpu.hl));
	
	printf("sp: " BINARY_PATTERN "" BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.sp>>8), BYTE_TO_BINARY(cpu.sp));
	printf("pc: " BINARY_PATTERN "" BINARY_PATTERN "\n", BYTE_TO_BINARY(cpu.pc>>8), BYTE_TO_BINARY(cpu.pc));
}
