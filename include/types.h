#ifndef GB_TYPESH
#define GB_TYPESH

#include <stdint.h>
#include <stdbool.h>

#define MEMORY_SIZE_BIOS 0x100  // 256 bytes
#define MEMORY_SIZE_ROM  0x8000 // 32k bytes
#define MEMORY_SIZE_VRAM 0x2000 //  8k bytes
#define MEMORY_SIZE_ERAM 0x2000 //  8k bytes
#define MEMORY_SIZE_WRAM 0x2000 //  8k bytes (*2)
#define MEMORY_SIZE_ZRAM 0x80   // 128 bytes
#define MEMORY_SIZE_OAM  0x100	// 256 bytes

typedef struct {
	uint8_t bios[MEMORY_SIZE_BIOS];
	uint8_t rom[MEMORY_SIZE_ROM];  		// rom bank 0 and 1
	uint8_t vram[MEMORY_SIZE_VRAM]; 	// video ram
	uint8_t eram[MEMORY_SIZE_ERAM]; 	// external ram
	uint8_t wram[MEMORY_SIZE_WRAM]; 	// working ram (also used for shadow)
	uint8_t zram[MEMORY_SIZE_ZRAM];		// zero page
	uint8_t oam[MEMORY_SIZE_OAM];		// object attribute memory (should be in gpu, but here for now)
	
	// interrupt enable register 0FFFF
	uint8_t ienable; // 0 vblank, 1 lcd stat, 2 timer, 3 serial, 4 joypad
	// interrupt flag register 0xFF0F
	uint8_t iflag; // 0 vblank, 1 lcd stat, 2 timer, 3 serial, 4 joypad
	
	bool biosActive;
} memory_t;

typedef struct {
	union {
		struct {
			uint8_t f;
			uint8_t a;
		};
		uint16_t af;
	};
	union {
		struct {
			uint8_t c;
			uint8_t b;
		};
		uint16_t bc;
	};
	union {
		struct {
			uint8_t e;
			uint8_t d;
		};
		uint16_t de;
	};
	union {
		struct {
			uint8_t l;
			uint8_t h;
		};
		uint16_t hl;
	};
	uint16_t sp;
	uint16_t pc;
	
	// interrupt master enable;
	uint8_t ime;
} cpu_t;


#define GB_SCREEN_WIDTH 160
#define GB_SCREEN_HEIGHT 144
#define GB_SCREEN_SCALE_FACTOR 3

typedef struct {
	int mode;
	int modeClock;
	int line;
	
	uint8_t pixels[GB_SCREEN_WIDTH*GB_SCREEN_HEIGHT];
} screen_t;

typedef struct {
	cpu_t cpu;
	screen_t screen;
	memory_t memory;

	bool inDebugMode;
	bool quit;
} gameboy_t;

typedef struct {
	char* identifier;
	uint8_t immediates;
	uint8_t cycles;
	void (*execute)(gameboy_t*);
} instruction_t;


#endif
