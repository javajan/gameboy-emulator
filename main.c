#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include<time.h>

#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "types.h"
#include "gameboy.h"
#include "memory.h"
#include "screen.h"

int main() {
	// read game rom
	FILE* game = fopen("Tetris.gb", "r");
	fseek(game, 0, SEEK_END);
	uint16_t rom_size = ftell(game);
	rewind(game);
	uint8_t rom[rom_size];
	int read_size = fread(rom, sizeof(uint8_t), rom_size, game);
	fclose(game);

	if (rom_size != read_size) {
		printf("Something went wrong while reading the game rom.\n");
		return 1;
	}
	
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		puts("could not init sdl");
	}
	
	SDL_Window *win = SDL_CreateWindow( "Hello World!", 
										100, 100, 
										GB_SCREEN_WIDTH*GB_SCREEN_SCALE_FACTOR, 
										GB_SCREEN_HEIGHT*GB_SCREEN_SCALE_FACTOR, 
										SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer= SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(renderer, GB_SCREEN_WIDTH, GB_SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	// init gameboy
	gameboy_t gameboy = gb_init(rom, rom_size);
	
	uint32_t time = SDL_GetTicks();
	uint32_t fpsTimer = 0;
	
	bool canContinue = true;
	while (canContinue && !gameboy.quit) {

		if (gameboy.memory.biosActive) {
			if (gameboy.cpu.pc == 0x100) {
				printf("started game rom\n");
				
				gameboy.cpu.pc = 0;
				gameboy.memory.biosActive = false;
				gameboy.inDebugMode = true;
			}
			
		}
		
		if (gameboy.inDebugMode) {
			bool executeNextInstruction = false;
			
			gb_print_registers(gameboy);
			gb_print_disassembly(gameboy, gameboy.cpu.pc, 7);
			
			while(!executeNextInstruction) {
				puts("Please enter a command: ");
				char input = getchar();
				getchar(); // consume \n
				
				if (input == 'n') {
					executeNextInstruction = true;
				}
				else if(input == 'c') {
					gameboy.inDebugMode = false;
					executeNextInstruction = true;
				}
				else if (input == 'q') {
					gameboy.quit = true;
					gameboy.inDebugMode = false;
					executeNextInstruction = true;
				}
				else {
					printf("Unkown command '%c', try again.\n", input);
				}
			}
		}
	
		uint8_t opcode = gb_mem_read(&gameboy.memory, gameboy.cpu.pc);
		gameboy.cpu.pc++;
		
		instruction_t instr;
		
		if (opcode == 0xcb) {
			// fetch cb instruction from different array
			opcode = gb_mem_read(&gameboy.memory, gameboy.cpu.pc);
			gameboy.cpu.pc++;
			
			instr = gb_cb_instructions[opcode];
		}
		else {
			instr = gb_base_instructions[opcode];
		}
		
		if (instr.execute == NULL) {
			printf("OPCODE 0x%02x NOT IMPLEMENTED\n", opcode);
			canContinue = false;
		}
		else {
			instr.execute(&gameboy);
		}
		gb_screen_update(&gameboy.screen, &gameboy.memory);
		
		
		// SDL stuff
		SDL_Event e;
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				gameboy.quit = true;
			}
		}
		
		fpsTimer += SDL_GetTicks() - time;
		if (fpsTimer >= 16) {
			fpsTimer = fpsTimer - 16;
			
			for (int y=0; y<GB_SCREEN_HEIGHT; y++) {
				for (int x=0; x<GB_SCREEN_WIDTH; x++) {
					uint8_t color = gameboy.screen.pixels[y*GB_SCREEN_WIDTH + x];
					
					SDL_SetRenderDrawColor(renderer, color, color, color, 255);
					SDL_RenderDrawPoint(renderer, x, y);
				}	
			}
			
			SDL_RenderPresent(renderer);
		}
		
		time = SDL_GetTicks();
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}

