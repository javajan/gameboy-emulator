#ifndef GB_SCREENH
#define GB_SCREENH

#include "types.h"

screen_t gb_screen_init();
void gb_screen_update(screen_t*, memory_t*, uint8_t);
void gb_screen_destroy(screen_t*);

#endif
