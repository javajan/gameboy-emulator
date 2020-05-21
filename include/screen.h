#ifndef GB_SCREENH
#define GB_SCREENH

#include "types.h"

#define GB_SCREEN_COLOR_WHITE 255
#define GB_SCREEN_COLOR_DARK_GRAY 192
#define GB_SCREEN_COLOR_LIGHT_GRAY 96
#define GB_SCREEN_COLOR_BLACK 0

screen_t gb_screen_init();
void gb_screen_update(screen_t*, memory_t*, uint8_t);
void gb_screen_destroy(screen_t*);

#endif
