#ifndef GB_SCREENH
#define GB_SCREENH

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "types.h"
#include "gameboy.h"

void gb_init_screen(gameboy_t*);
void gb_screen_update(gameboy_t*);
void gb_screen_destroy(gameboy_t*);

void gb_screen_scanline(gameboy_t*);

#endif
