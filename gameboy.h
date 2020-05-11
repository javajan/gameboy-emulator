#include <stdint.h>
#include <stdbool.h>

#define RAM_SIZE 0xFFFF

// flag bit positions
#define GB_FLAG_ZERO 7
#define GB_FLAG_NEGATIVE 6
#define GB_FLAG_HALF_CARRY 5
#define GB_FLAG_CARRY 4

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
} cpu_t;

typedef struct {
	cpu_t cpu;
	uint8_t memory[RAM_SIZE];
} gameboy_t;

typedef struct {
	char* identifier;
	uint8_t immediates;
	uint8_t cycles;
	void (*execute)(gameboy_t*);
} instruction_t;

extern const instruction_t gb_base_instructions[256];
extern const instruction_t gb_cb_instructions[256];

void gb_init(gameboy_t*, uint8_t*, uint16_t);
void gb_stop(gameboy_t*);

void gb_run(gameboy_t*);
void gb_execute(gameboy_t*);

void gb_mem_write(gameboy_t*, uint16_t, uint8_t);
uint8_t gb_mem_read(gameboy_t*, uint16_t);

void gb_flag_reset(gameboy_t* gameboy);
void gb_flag_set(gameboy_t*, int, bool);
void gb_flag_flip(gameboy_t*, int);
bool gb_flag_get(gameboy_t, int);

void gb_stop(gameboy_t*);
void gb_halt(gameboy_t*);
void gb_enable_interrupts(gameboy_t*);
void gb_disable_interrupts(gameboy_t*);

// read immediates (values after instruction)
uint8_t gb_read_n(gameboy_t*);
uint16_t gb_read_nn(gameboy_t*);

void gb_print_registers(gameboy_t);











