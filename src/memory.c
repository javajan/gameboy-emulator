#include <stdio.h>
#include <unistd.h>

#include "memory.h"
#include "util.h"

static uint8_t GB_BOOT_ROM[] = { 0x31,0xfe,0xff,0xaf,0x21,0xff,0x9f,0x32,0xcb,0x7c,0x20,0xfb,0x21,0x26,0xff,0x0e,0x11,0x3e,0x80,0x32,0xe2,0x0c,0x3e,0xf3,0xe2,0x32,0x3e,0x77,0x77,0x3e,0xfc,0xe0,0x47,0x11,0x04,0x01,0x21,0x10,0x80,0x1a,0xcd,0x95,0x00,0xcd,0x96,0x00,0x13,0x7b,0xfe,0x34,0x20,0xf3,0x11,0xd8,0x00,0x06,0x08,0x1a,0x13,0x22,0x23,0x05,0x20,0xf9,0x3e,0x19,0xea,0x10,0x99,0x21,0x2f,0x99,0x0e,0x0c,0x3d,0x28,0x08,0x32,0x0d,0x20,0xf9,0x2e,0x0f,0x18,0xf3,0x67,0x3e,0x64,0x57,0xe0,0x42,0x3e,0x91,0xe0,0x40,0x04,0x1e,0x02,0x0e,0x0c,0xf0,0x44,0xfe,0x90,0x20,0xfa,0x0d,0x20,0xf7,0x1d,0x20,0xf2,0x0e,0x13,0x24,0x7c,0x1e,0x83,0xfe,0x62,0x28,0x06,0x1e,0xc1,0xfe,0x64,0x20,0x06,0x7b,0xe2,0x0c,0x3e,0x87,0xe2,0xf0,0x42,0x90,0xe0,0x42,0x15,0x20,0xd2,0x05,0x20,0x4f,0x16,0x20,0x18,0xcb,0x4f,0x06,0x04,0xc5,0xcb,0x11,0x17,0xc1,0xcb,0x11,0x17,0x05,0x20,0xf5,0x22,0x23,0x22,0x23,0xc9,0xce,0xed,0x66,0x66,0xcc,0x0d,0x00,0x0b,0x03,0x73,0x00,0x83,0x00,0x0c,0x00,0x0d,0x00,0x08,0x11,0x1f,0x88,0x89,0x00,0x0e,0xdc,0xcc,0x6e,0xe6,0xdd,0xdd,0xd9,0x99,0xbb,0xbb,0x67,0x63,0x6e,0x0e,0xec,0xcc,0xdd,0xdc,0x99,0x9f,0xbb,0xb9,0x33,0x3e,0x3c,0x42,0xb9,0xa5,0xb9,0xa5,0x42,0x3c,0x21,0x04,0x01,0x11,0xa8,0x00,0x1a,0x13,0xbe,0x20,0xfe,0x23,0x7d,0xfe,0x34,0x20,0xf5,0x06,0x19,0x78,0x86,0x23,0x05,0x20,0xfb,0x86,0x20,0xfe,0x3e,0x01,0xe0,0x50 };

memory_t gb_init_memory(uint8_t* rom, uint16_t romSize) {
	memory_t memory;
	
	memory.biosActive = true;
	memory.ienable = 0;
	memory.iflag = 0;
	
	// Load BIOS
	for (int i = 0; i < MEMORY_SIZE_BIOS; i++) {
		memory.bios[i] = GB_BOOT_ROM[i];
	}
	
	// Load game ROM
	for (int i = 0; i < MEMORY_SIZE_ROM; i++) {
		if (i < romSize) {
			memory.rom[i] = rom[i];
		}
		else {
			memory.rom[i] = 0;
		}
	}
	
	for (int i = 0; i < MEMORY_SIZE_ZRAM; i++) {
		memory.zram[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_OAM; i++) {
		memory.oam[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_ERAM; i++) {
		memory.eram[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_VRAM; i++) {
		memory.vram[i] = 0;
	}
	for (int i = 0; i < MEMORY_SIZE_WRAM; i++) {
		memory.wram[i] = 0;
	}
	
	return memory;
}

void gb_mem_write(memory_t* memory, uint16_t addr, uint8_t val) {
	switch (addr & 0xF000) {
		// BIOS or ROM 0
		case 0x0000:
			if (memory->biosActive) {
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
					if (addr == 0xFFFF) {
						memory->ienable = val;
					}
					else if (addr >= 0xFF80) {
						memory->zram[addr & 0x7F] = val;
					}
					// I/O
					else {
						if (addr == 0xFF0F) {
							memory->iflag = val;
						}
						else {
							if (addr == 0xFF02 && val == 0x81) {
								// prints test rom output
								printf("%c", memory->wram[0xFF01 & 0x1FFF]);
							}
							memory->wram[addr & 0x1FFF] = val;
						}
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
			if (memory->biosActive) {
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
					if (addr == 0xFFFF) {
						return memory->ienable;
					}
					else if (addr >= 0xFF80) {
						return memory->zram[addr & 0x7F];
					}
					// I/O
					else {
						if (addr == 0xFF0F) {
							return memory->iflag;
						}
						else {
							return memory->wram[addr & 0x1FFF]; // TODO handle IO
						}
					}
			}
	}
	
	printf("Could not map memory request: 0x%04x\n. This should never happen!\n", addr);
	return 0;
}