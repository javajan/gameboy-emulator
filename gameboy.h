#include <stdint.h>

#define RAM_SIZE 0xFFFF

typedef struct {
	union {
		struct {
			uint8_t a;
			uint8_t f;
		};
		uint16_t af;
	};
	union {
		struct {
			uint8_t b;
			uint8_t c;
		};
		uint16_t bc;
	};
	union {
		struct {
			uint8_t d;
			uint8_t e;
		};
		uint16_t de;
	};
	union {
		struct {
			uint8_t h;
			uint8_t l;
		};
		uint16_t hl;
	};
	uint16_t sp;
	uint16_t pc;
} cpu_t;

typedef struct {
	cpu_t cpu;
	uint8_t memory[RAM_SIZE];
} gameboy_t;

typedef struct {
	char* identifier;
	uint8_t cycles;
	void (*execute)(gameboy_t*);
} instruction_t;

extern const instruction_t gb_instructions[256];

void gb_init(gameboy_t*, uint8_t*, uint16_t);
void gb_stop(gameboy_t*);

void gb_execute(gameboy_t*);
void gb_mem_write(gameboy_t*, uint16_t, uint8_t);
uint8_t gb_mem_read(gameboy_t*, uint16_t);

void gb_print_registers(gameboy_t);











