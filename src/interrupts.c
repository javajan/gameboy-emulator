
#include <stdint.h>

#include "interrupts.h"
#include "instructions.h"
#include "memory.h"

void gb_interrupt_handle(gameboy_t* gameboy) {
	//printf("ime=%d ie=%02x if=%02x\n", gameboy->cpu.ime, gameboy->memory.ienable, gameboy->memory.iflag);

	if (gameboy->cpu.ime == 1 && gameboy->memory.ienable && gameboy->memory.iflag) {
		// interrupt occured
	
		uint8_t interrupts = gameboy->memory.ienable & gameboy->memory.iflag;
		
		// disable other interrupts
		// will be enabled if interrupt handler returns with RETI
		
		if (interrupts & GB_INT_VBLANK) {
			// vblank
			gb_disable_interrupts(gameboy);
		
			gameboy->memory.iflag &= 0xFE;
			INT(gameboy, 0x40);
		}
		else if (interrupts & GB_INT_JOYPAD) {
			// joypad press
			gb_disable_interrupts(gameboy);
			
			gameboy->memory.iflag &= 0xEF;
			INT(gameboy, 0x60);
		}
	}
}

void gb_interrupt_request(memory_t* memory, uint8_t i) {
	gb_mem_write(memory, GB_INT_FLAG, gb_mem_read(memory, GB_INT_FLAG) | i);
}
