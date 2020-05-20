#include "joypad.h"
#include "interrupts.h"

void gb_joypad_reset(memory_t* memory) {
	gb_mem_write(memory, GB_REGISTER_JOYP, gb_mem_read(memory, GB_REGISTER_JOYP) | 0x0F);
}

void gb_joypad_set(memory_t* memory, uint8_t flag, uint8_t state) {
	switch(state) {
		case GB_JOYPAD_PRESSED:
			memory->joyp = memory->joyp & ~(0x1 << flag);
			
			// request joypad interrupt
			gb_interrupt_request(memory, GB_INT_JOYPAD);
			
			break;
		case GB_JOYPAD_RELEASED:
			memory->joyp = memory->joyp | (0x1 << flag);
			break;
	}
}
