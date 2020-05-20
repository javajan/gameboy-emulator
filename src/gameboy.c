#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gameboy.h"
#include "screen.h"
#include "util.h"

gameboy_t gb_init(uint8_t* game, uint16_t gameRomSize) {
	gameboy_t gameboy;
	
	gameboy.inDebugMode = false;
	gameboy.quit = false;
	
	gameboy.cpu.a = 0x00;
	gameboy.cpu.b = 0x00;
	gameboy.cpu.c = 0x00;
	gameboy.cpu.d = 0x00;
	gameboy.cpu.e = 0x00;
	gameboy.cpu.h = 0x00;
	gameboy.cpu.l = 0x00;
	gameboy.cpu.f = 0x00;
	
	gameboy.cpu.sp = 0xFFFE;
	gameboy.cpu.pc = 0x000;
	
	gameboy.cpu.ime = 0;
	
	gameboy.memory = gb_init_memory(game, gameRomSize);
	gameboy.screen = gb_screen_init();
	
	return gameboy;
}

void gb_stop(gameboy_t* gameboy) {
	
}

void gb_halt(gameboy_t* gameboy) {
	// TODO
}

void gb_enable_interrupts(gameboy_t* gameboy) {
	gameboy->cpu.ime = 1;
} 

void gb_disable_interrupts(gameboy_t* gameboy) {
	gameboy->cpu.ime = 0;
}

// ------------------ begin flag setters/getters ------------------

void gb_flag_reset(gameboy_t* gameboy) {
	gameboy->cpu.f = 0x00;
}

void gb_flag_set(gameboy_t* gameboy, int pos, bool set) {
	if (set) {
		gameboy->cpu.f = gameboy->cpu.f | (0x01 << pos);
	}
	else {
		gameboy->cpu.f = gameboy->cpu.f & ~(0x01 << pos);
	}
}

void gb_flag_flip(gameboy_t* gameboy, int pos) {
	gameboy->cpu.f = gameboy->cpu.f ^ (0x01 << pos);
}

bool gb_flag_get(gameboy_t gameboy, int pos) {
	return ((0x01 << pos) & gameboy.cpu.f) != 0;
}

// ------------------ end flag setters/getters ------------------

void gb_print_disassembly(gameboy_t gameboy, uint16_t start, uint16_t count) {
	uint16_t pc = start;
	uint16_t instructionsRead = 0;
	
	while (instructionsRead < count) {
		uint8_t opcode = gb_mem_read(&gameboy.memory, pc);
		
		instruction_t instr;
		if (opcode == 0xcb) {
			pc++;
			opcode = gb_mem_read(&gameboy.memory, pc);
			instr = gb_cb_instructions[opcode];
		}
		else {
			instr = gb_base_instructions[opcode];
		}
		
		if (instr.identifier != NULL) {
			char identifier[255];
			strcpy(identifier, instr.identifier);
			
			if (instr.immediates == 1) {
				uint8_t n1 = gb_mem_read(&gameboy.memory, pc+1);
				
				sprintf(identifier, identifier, n1);
				printf("%04x: %02x %02x \t\t %s", pc, opcode, n1, identifier);
			}
			else if (instr.immediates == 2) {
				uint8_t n1 = gb_mem_read(&gameboy.memory, pc+1);
				uint8_t n2 = gb_mem_read(&gameboy.memory, pc+2);
				
				sprintf(identifier, identifier, n2, n1);
				printf("%04x: %02x %02x %02x \t\t %s", pc, opcode, n1, n2, identifier);
			}
			else {
				printf("%04x: %02x \t\t %s", pc, opcode, identifier);
			}
			
			if (instructionsRead == 0)
				printf("\t<--------- PC");
			printf("\n");
			pc += instr.immediates;
		}
		else {
			printf("%04x: \t\t unknown instruction: $%02x\n", pc, opcode);
		}
		pc += 1;
		instructionsRead++;
	}
}

void gb_print_registers(gameboy_t gameboy) {
	cpu_t cpu = gameboy.cpu;
	
	printf("a: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.a), cpu.a);
	printf("b: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.b), cpu.b);
	printf("c: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.c), cpu.c);
	printf("d: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.d), cpu.d);
	printf("e: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.e), cpu.e);
	printf("h: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.h), cpu.h);
	printf("l: " BINARY_PATTERN " (%02x) \n", BYTE_TO_BINARY(cpu.l), cpu.l);
	printf("f: " BINARY_PATTERN " (Z=%d,N=%d,H=%d,C=%d)\n", 
			BYTE_TO_BINARY(cpu.f), 
			gb_flag_get(gameboy, GB_FLAG_ZERO), 
			gb_flag_get(gameboy, GB_FLAG_NEGATIVE), 
			gb_flag_get(gameboy, GB_FLAG_HALF_CARRY), 
			gb_flag_get(gameboy, GB_FLAG_CARRY));
	
	printf("af: " BINARY_PATTERN "" BINARY_PATTERN " (%04x)\n", BYTE_TO_BINARY(cpu.af>>8), BYTE_TO_BINARY(cpu.af), cpu.af);
	printf("bc: " BINARY_PATTERN "" BINARY_PATTERN " (%04x)\n", BYTE_TO_BINARY(cpu.bc>>8), BYTE_TO_BINARY(cpu.bc), cpu.bc);
	printf("de: " BINARY_PATTERN "" BINARY_PATTERN " (%04x)\n", BYTE_TO_BINARY(cpu.de>>8), BYTE_TO_BINARY(cpu.de), cpu.de);
	printf("hl: " BINARY_PATTERN "" BINARY_PATTERN " (%04x)\n", BYTE_TO_BINARY(cpu.hl>>8), BYTE_TO_BINARY(cpu.hl), cpu.hl);
	
	printf("sp: " BINARY_PATTERN "" BINARY_PATTERN " (%04x)\n", BYTE_TO_BINARY(cpu.sp>>8), BYTE_TO_BINARY(cpu.sp), cpu.sp);
	printf("pc: " BINARY_PATTERN "" BINARY_PATTERN " (%04x)\n", BYTE_TO_BINARY(cpu.pc>>8), BYTE_TO_BINARY(cpu.pc), cpu.pc);
}

void gb_print_stack(gameboy_t* gameboy, uint16_t before, uint16_t after) {
	uint16_t sp = gameboy->cpu.sp;
	
	for (int i=sp+before; i>sp-after; i--) {
		printf("%04x: \t%02x", i & 0xFFFF, gb_mem_read(&gameboy->memory, i));
		if (i == sp) {
			printf("\t<--------- SP");
		}
		printf("\n");
	}
}





