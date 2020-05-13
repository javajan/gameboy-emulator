#include <stdio.h>
#include "memory.h"
#include "util.h"

void gb_init_memory(memory_t* memory, uint8_t* boot, uint16_t bootRomSize, uint8_t* rom, uint16_t romSize) {
	memory->inBios = true;
	
	// Load BIOS
	for (int i = 0; i < MEMORY_SIZE_BIOS; i++) {
		if (i < bootRomSize) {
			memory->bios[i] = boot[i];
		}
		else {
			memory->bios[i] = 0;
		}
	}
	
	// Load game ROM
	for (int i = 0; i < MEMORY_SIZE_ROM; i++) {
		if (i < romSize) {
			memory->rom[i] = rom[i];
		}
		else {
			memory->rom[i] = 0;
		}
	}
	
	for (int i = 0; i < MEMORY_SIZE_ZRAM; i++) {
		memory->zram[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_OAM; i++) {
		memory->oam[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_ERAM; i++) {
		memory->eram[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_VRAM; i++) {
		memory->vram[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_WRAM; i++) {
		memory->wram[i] = 0;
	}
}

void gb_mem_write(memory_t* memory, uint16_t addr, uint8_t val) {
	switch (addr & 0xF000) {
		// BIOS or ROM 0
		case 0x0000:
			if (memory->inBios) {
				if (addr < 0x100)
					memory->bios[addr] = val;
			}
			else {
				memory->rom[addr] = val;
			}
			break;
		// ROM 0
		case 0x1000:
		case 0x2000:
		case 0x3000:
			memory->rom[addr] = val;
			break;
		// ROM 1
		case 0x4000:
		case 0x5000:
		case 0x6000:
		case 0x7000:
			memory->rom[addr] = val;
			break;
		// VRAM
		case 0x8000:
		case 0x9000:
			memory->vram[addr & 0x1FFF] = val;
			break;
		// ERAM
		case 0xA000:
		case 0xB000:
			memory->eram[addr & 0x1FFF] = val;
			break;
		// WRAM
		case 0xC000:
		case 0xD000:
			memory->wram[addr & 0x1FFF] = val;
			break;
		// WRAM shadow
		case 0xE000:
			memory->wram[addr & 0x1FFF] = val;
			break;
		// WRAM shadow or ZRAM
		case 0xF000:
			switch(addr & 0x0F00) {
				// WRAM shadown
				case 0x000: case 0x100: case 0x200:
				case 0x300: case 0x400: case 0x500:
				case 0x600: case 0x700: case 0x800:
				case 0x900: case 0xA00: case 0xB00:
				case 0xC00: case 0xD00:
					memory->wram[addr & 0x1FFF] = val;
					break;
				// OAM
				case 0xE00:
					if (addr < 0xFEA0) {
						memory->oam[addr & 0xFF] = val;
					}
					else {
						// not used
					}
					break;
				case 0xF00:
					// ZRAM
					if (addr >= 0xFF80) {
						memory->zram[addr & 0x7F] = val;
					}
					// I/O
					else {
						memory->wram[addr & 0x1FFF] = val;
						//printf("trying to write io value %d to address %04x\n", val, addr);
					}
					break;
			}
			break;
		default:
			printf("Could not map memory write: 0x%04x\n. This should never happen!\n", addr);
	}
}

uint8_t gb_mem_read(memory_t* memory, uint16_t addr) {
	switch (addr & 0xF000) {
		// BIOS or ROM 0
		case 0x0000:
			if (memory->inBios) {
				if (addr < 0x0100)
					return memory->bios[addr];
			}
			return memory->rom[addr];
		// ROM 0
		case 0x1000:
		case 0x2000:
		case 0x3000:
			return memory->rom[addr];
		// ROM 1
		case 0x4000:
		case 0x5000:
		case 0x6000:
		case 0x7000:
			return memory->rom[addr];
		// VRAM
		case 0x8000:
		case 0x9000:
			return memory->vram[addr & 0x1FFF];
		// ERAM
		case 0xA000:
		case 0xB000:
			return memory->eram[addr & 0x1FFF];
		// WRAM
		case 0xC000:
		case 0xD000:
			return memory->wram[addr & 0x1FFF];
		// WRAM shadow
		case 0xE000:
			return memory->wram[addr & 0x1FFF];
		// WRAM shadow or ZRAM
		case 0xF000:
			switch(addr & 0x0F00) {
				// WRAM shadown
				case 0x000: case 0x100: case 0x200:
				case 0x300: case 0x400: case 0x500:
				case 0x600: case 0x700: case 0x800:
				case 0x900: case 0xA00: case 0xB00:
				case 0xC00: case 0xD00:
					return memory->wram[addr & 0x1FFF];
				// OAM
				case 0xE00:
					if (addr < 0xFEA0) {
						return memory->oam[addr & 0xFF];
					}
					else {
						return 0;
					}
				case 0xF00:
					// ZRAM
					if (addr >= 0xFF80) {
						return memory->zram[addr & 0x7F];
					}
					// I/O
					else {
						//printf("trying to read io value %d at address %04x \n", memory->wram[addr & 0x1FFF], addr);
						return memory->wram[addr & 0x1FFF]; // TODO handle IO
					}
			}
	}
	
	printf("Could not map memory request: 0x%04x\n. This should never happen!\n", addr);
	return 0;
}
