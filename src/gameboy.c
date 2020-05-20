#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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




