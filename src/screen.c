#include <stdbool.h>

#include "screen.h"
#include "memory.h"
#include "util.h"
#include "interrupts.h"

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
		
	uint8_t lcdc = gb_mem_read(memory, 0xFF40);
	bool bgWindowEnable = (lcdc & (1 << 0)) == 0x1; // bg and window are enabled
	bool spriteEnable = (lcdc & (1 << 1)) == 0x2;
	bool spriteSize = (lcdc & (1 << 2)) == 0x4;
	bool tileMap = (lcdc & (1 << 3)) == 0x8;
	bool tileData = (lcdc & (1 << 4)) == 0x10;
	bool windowEnable = (lcdc & (1 << 5)) == 0x20; // window enabled, ignored if bgWindowEnable is 0
	bool windowTileMap = (lcdc & (1 << 6)) == 0x40;
	bool lcdEnable = (lcdc & (1 << 7)) == 0x80;
	
	if (!lcdEnable)
	{
		for (int x=0; x<GB_SCREEN_WIDTH; x++)
			screen->pixels[screen->line * GB_SCREEN_WIDTH + x] = GB_SCREEN_COLOR_WHITE;
		return;
	}

	if (bgWindowEnable)
	{
		uint8_t bgPalette = gb_mem_read(memory, 0xFF47);
		uint8_t color0 = bgPalette & 0x03; 			// shade for color number 0
		uint8_t color1 = (bgPalette >> 2) & 0x03; 	// shade for color number 1
		uint8_t color2 = (bgPalette >> 4) & 0x03; 	// shade for color number 2
		uint8_t color3 = (bgPalette >> 6) & 0x03; 	// shade for color number 3
		
		uint16_t mapOffset = tileMap ? 0x9C00 : 0x9800;
		uint16_t tileDataOffset = tileData ? 0x8000 : 0x8800;

		uint8_t scrolly = gb_mem_read(memory, 0xFF42);
		uint8_t scrollx = gb_mem_read(memory, 0xFF43);

		uint8_t bgy = (screen->line + scrolly) / 8;
		uint8_t pixely = (screen->line + scrolly) % 8;
		
		int bgx = scrollx / 8;
		int x = 0;
		
		while (x < GB_SCREEN_WIDTH)
		{
			uint8_t tile_number = gb_mem_read(memory, mapOffset + bgy * 32 + bgx);
			
			// tile_number is signed value, convert to unsigned
			if (tileData && tile_number < 128)
				tile_number += 256;
			
			uint8_t byte1 = gb_mem_read(memory, tileDataOffset + tile_number * 16 + pixely * 2);
			uint8_t byte2 = gb_mem_read(memory, tileDataOffset + tile_number * 16 + pixely * 2 + 1);
			
			for (int pixelx=7; pixelx>=0; pixelx--)
			{
				uint8_t paletteNumber = ((byte1 >> pixelx) & 1) | (((byte2 >> pixelx) & 1) * 2);
				uint8_t paletteColor = 0;
				
				switch(paletteNumber) {
					case 0:
						paletteColor = color0;
						break;
					case 1:
						paletteColor = color1;
						break;
					case 2:
						paletteColor = color2;
						break;
					case 3:
						paletteColor = color3;
						break;
				}
				
				uint8_t color = 0;
				switch(paletteColor) {
					case 0:
						color = GB_SCREEN_COLOR_WHITE;
						break;
					case 1:
						color = GB_SCREEN_COLOR_LIGHT_GRAY;
						break;
					case 2:
						color = GB_SCREEN_COLOR_DARK_GRAY;
						break;
					case 3:
						color = GB_SCREEN_COLOR_BLACK;
						break;
				}
				
				screen->pixels[screen->line * GB_SCREEN_WIDTH + x] = color;
				x++;
			}

			bgx++;
		}
	}
	else
	{
		for (int x=0; x<GB_SCREEN_WIDTH; x++)
			screen->pixels[screen->line * GB_SCREEN_WIDTH + x] = GB_SCREEN_COLOR_WHITE;
	}

	
	if (spriteEnable)
	{
		for (int s=0; s<40; s++)
		{
			uint8_t sy = gb_mem_read(memory, 0xFE00 + s * 4) - 16;
			
			if (sy <= screen->line && sy + 8 > screen->line) {
				uint8_t sx = gb_mem_read(memory, 0xFE00 + s * 4 + 1) - 8;
				uint8_t stile = gb_mem_read(memory, 0xFE00 + s * 4 + 2);
				uint8_t sflags = gb_mem_read(memory, 0xFE00 + s * 4 + 3);
				
				uint8_t tilerow = 0;
				
				bool prio = (sflags & (1 << 7)) == 0x80;
				bool flipY = (sflags & (1 << 6)) == 0x40;
				bool flipX = (sflags & (1 << 5)) == 0x20;
				
				if (flipY)
					tilerow = 7 - (screen->line - sy);
				else
					tilerow = screen->line - sy;
				
				uint8_t byte1 = gb_mem_read(memory, 0x8000 + stile * 16 + tilerow * 2);
				uint8_t byte2 = gb_mem_read(memory, 0x8000 + stile * 16 + tilerow * 2 + 1);
				
				for (int pixelx=0; pixelx<8; pixelx++)
				{
					// calc color TODO: use palette
					uint8_t bit1 = (byte1 >> pixelx) & 1;
					uint8_t bit2 = ((byte2 >> pixelx) & 1) * 2;
					
					uint8_t combined = bit1 | bit2;
					uint8_t color = 0;
					switch(combined)
					{
						case 0:
							color = GB_SCREEN_COLOR_WHITE;
							break;
						case 1:
							color = GB_SCREEN_COLOR_DARK_GRAY;
							break;
						case 2:
							color = GB_SCREEN_COLOR_LIGHT_GRAY;
							break;
						case 3:
							color = GB_SCREEN_COLOR_BLACK;
							break;
					}
					
					// pixel is on screen, is not invis, has prio or bg pixel is invis
					if ( pixelx + sx >= 0 && pixelx + sx < 160 && color != GB_SCREEN_COLOR_WHITE
						 && (prio || (screen->pixels[screen->line * GB_SCREEN_WIDTH + sx + pixelx] == GB_SCREEN_COLOR_WHITE)) )
					{
						uint8_t px = flipX ? 7-pixelx : pixelx;
						screen->pixels[screen->line * GB_SCREEN_WIDTH + sx + px] = color;
					}
					
				}
			}
		}
	}
}


// Correctly times the time it takes to render with the cpu clocks
void gb_screen_update(screen_t* screen, memory_t* memory, uint8_t cycles) {
	
	screen->modeClock += cycles;
	
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
					gb_interrupt_request(memory, GB_INT_VBLANK);
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
