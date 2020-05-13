#include "screen.h"
#include "memory.h"

void gb_init_screen(gameboy_t* gameboy) {
	gameboy->screen.mode = 0;
	gameboy->screen.modeClock = 0;

	// SDL setup
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Could not init SDL: %s\n", SDL_GetError());
	}
	SDL_Window* win = SDL_CreateWindow( "Hello World!", 
										100, 100, 
										GB_SCREEN_WIDTH * GB_SCREEN_SCALE_FACTOR, 
										GB_SCREEN_HEIGHT * GB_SCREEN_SCALE_FACTOR, 
										SDL_WINDOW_SHOWN );
	if (win == NULL) {
		printf("Could not create SDL window: %s\n", SDL_GetError());
		SDL_Quit();
	}
	
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED );
	if (renderer == NULL) {
		printf("Could not create SDL renderer: %s\n", SDL_GetError());
		SDL_Quit();
	}
	SDL_RenderSetLogicalSize(renderer, GB_SCREEN_WIDTH, GB_SCREEN_HEIGHT);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	gameboy->screen.win = win;
	gameboy->screen.renderer = renderer;
}

// Correctly times the time it takes to render
void gb_screen_update(gameboy_t* gameboy) {
	screen_t* screen = &gameboy->screen;
	
	//TODO use actual clock time
	screen->modeClock += 4;
	
	switch (screen->mode)
	{
		// HBLANK
		case 0:
			if (screen->modeClock >= 204) {
				screen->modeClock = 0;
				screen->line++;
				
				gb_mem_write(gameboy->memory, 0xFF44, screen->line+1);
				
				if(screen->line == 143) {
					screen->mode = 1;
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
				
				gb_mem_write(gameboy->memory, 0xFF44, screen->line+1);
				
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
				
				gb_screen_scanline(gameboy);
			}
			break;
	}
	
	// TODO handle input somewhere else
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			gameboy->quit = true;
		}
	}
	
	/*if (gameboy->memory->inBios) {
		gb_mem_write(gameboy->memory, 0xFF44, 0x90);
	}*/
}

void gb_screen_scanline(gameboy_t* gameboy) {
	screen_t* screen = &gameboy->screen;
	SDL_Renderer* renderer = screen->renderer;

	uint8_t scrolly = gb_mem_read(gameboy->memory, 0xFF42);
	uint8_t scrollx = gb_mem_read(gameboy->memory, 0xFF43);

	// same as div 32
	uint8_t bgy = (screen->line + scrolly) / 8;
	uint8_t pixely = (screen->line + scrolly) % 8;
	
	//printf("scanline = %d scrolly = %d bgy = %d\n", screen->line, scrolly, bgy);
	
	int bgx = scrollx / 8;
	
	while (bgx < 32) {
		uint8_t tile_number = gb_mem_read(gameboy->memory, 0x9800 + bgy * 32 + bgx);
		
		uint8_t byte1 = gb_mem_read(gameboy->memory, 0x8000 + tile_number * 16 + pixely * 2);
		uint8_t byte2 = gb_mem_read(gameboy->memory, 0x8000 + tile_number * 16 + pixely * 2 + 1);
		
		for (int pixelx=7; pixelx>=0; pixelx--) {
			
			uint8_t bit1 = (byte1 >> pixelx) & 1;
			uint8_t bit2 = (byte2 >> (pixelx-1)) & 2;
			
			uint8_t combined = bit1 | bit2;
			uint8_t color = 0;
			
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
			
			SDL_SetRenderDrawColor(renderer, color, color, color, 255);
			SDL_RenderDrawPoint(renderer, scrollx + bgx * 8 - pixelx - (scrollx % 32), scrolly + bgy * 8 + pixely);
		}
		
		bgx++;
	}
	
	SDL_RenderPresent(renderer);
}

void gb_screen_destroy(gameboy_t* gameboy) {
	SDL_Renderer* renderer = gameboy->screen.renderer;
	SDL_Window* win = gameboy->screen.win;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
