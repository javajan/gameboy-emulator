#include <stdbool.h>

#include "screen.h"
#include "memory.h"
#include "util.h"

screen_t gb_screen_init() {
	screen_t screen;
	
	screen.mode = 0;
	screen.modeClock = 0;
	screen.line = 0;
	
	for(int i=0; i<GB_SCREEN_WIDTH*GB_SCREEN_HEIGHT; i++) {
		screen.pixels[i] = 255;
	}
	
	return screen;
}

void gb_screen_scanline(screen_t* screen, memory_t* memory) {
	if (screen->line >= GB_SCREEN_HEIGHT)
		return;

	uint8_t scrolly = gb_mem_read(memory, 0xFF42);
	uint8_t scrollx = gb_mem_read(memory, 0xFF43);

	uint8_t bgy = (screen->line + scrolly) / 8;
	uint8_t pixely = (screen->line + scrolly) % 8;
	
	int bgx = scrollx / 8;
	int x = 0;
	
	while (x < GB_SCREEN_WIDTH) {
		uint8_t tile_number = gb_mem_read(memory, 0x9800 + bgy * 32 + bgx);
		
		uint8_t byte1 = gb_mem_read(memory, 0x8000 + tile_number * 16 + pixely * 2);
		uint8_t byte2 = gb_mem_read(memory, 0x8000 + tile_number * 16 + pixely * 2 + 1);
		
		for (int pixelx=7; pixelx>=0; pixelx--) {
			
			uint8_t bit1 = (byte1 >> pixelx) & 1;
			uint8_t bit2 = ((byte2 >> pixelx) & 1) * 2;
			
			uint8_t combined = bit1 | bit2;
			uint8_t color = 0;
			
			//if (byte1 != 0 || byte2 != 0)
				//printf(""BINARY_PATTERN "\n"BINARY_PATTERN" bit %d -> %d\n", BYTE_TO_BINARY(byte1), BYTE_TO_BINARY(byte2), pixelx, combined);
			
			switch(combined) {
				case 0:
					color = 255;
					break;
				case 1:
					color = 192;
					break;
				case 2:
					color = 96;
					break;
				case 3:
					color = 0;
					break;
			}
			
			screen->pixels[screen->line * GB_SCREEN_WIDTH + x] = color;
			x++;
		}

		bgx++;
	}
}


// Correctly times the time it takes to render with the cpu clocks
void gb_screen_update(screen_t* screen, memory_t* memory) {
	
	//TODO use actual clock time
	screen->modeClock += 4;
	
	switch (screen->mode)
	{
		// HBLANK
		case 0:
			if (screen->modeClock >= 204) {
				screen->modeClock = 0;
				screen->line++;
				
				gb_mem_write(memory, 0xFF44, screen->line);
				
				if(screen->line == 143) {
					screen->mode = 1;
					
					// vblank interrupt
					gb_mem_write(memory, GB_INT_FLAG, gb_mem_read(memory, GB_INT_FLAG) | GB_INT_VBLANK);
				}
				else {
					screen->mode = 2;
				}
			}
			break;
		// VBLANK
		case 1:
			if (screen->modeClock >= 456) {
				screen->modeClock = 0;
				screen->line++;
				
				gb_mem_write(memory, 0xFF44, screen->line);
				
				if(screen->line > 153) {
					screen->mode = 2;
					screen->line = 0;
				}
			}
			break;
		// OAM mode, scanline active
		case 2:
			if (screen->modeClock >= 80) {
				screen->modeClock = 0;
				screen->mode = 3;
			}
			break;
		// VRAM mode, scanline active
		case 3:
			if (screen->modeClock >= 172) {
				screen->modeClock = 0;
				screen->mode = 0;
				
				gb_screen_scanline(screen, memory);
			}
			break;
	}
}

void gb_screen_destroy(screen_t* screen) {
	
}
