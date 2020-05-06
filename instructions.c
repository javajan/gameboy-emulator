#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#include "gameboy.h"

void NOP(gameboy_t* gameboy) {
}

// Loads R1 with the next value in memory
void LD_R1_N(gameboy_t* gameboy, uint8_t* r1) {
	uint8_t n = gb_mem_read(gameboy, gameboy->cpu.pc);
	*r1 = n;	
	gameboy->cpu.pc++;
}
void LD_B_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.b)); }
void LD_C_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.c)); }
void LD_D_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.d)); }
void LD_E_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.e)); }
void LD_H_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.h)); }
void LD_L_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.l)); }

// Copies r2 to r1
void LD_R1_R2(uint8_t* r1, uint8_t* r2) {
	*r1 = *r2;
}
void LD_A_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.a); } // A
void LD_A_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.b); }
void LD_A_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.c); }
void LD_A_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.d); }
void LD_A_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.e); }
void LD_A_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.h); }
void LD_A_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.a, &gameboy->cpu.l); }
void LD_B_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.a); } // B
void LD_B_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.b); }
void LD_B_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.c); }
void LD_B_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.d); }
void LD_B_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.e); }
void LD_B_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.h); }
void LD_B_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.b, &gameboy->cpu.l); }
void LD_C_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.a); } // C
void LD_C_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.b); }
void LD_C_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.c); }
void LD_C_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.d); }
void LD_C_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.e); }
void LD_C_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.h); }
void LD_C_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.c, &gameboy->cpu.l); }
void LD_D_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.a); } // D
void LD_D_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.b); }
void LD_D_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.c); }
void LD_D_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.d); }
void LD_D_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.e); }
void LD_D_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.h); }
void LD_D_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.d, &gameboy->cpu.l); }
void LD_E_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.a); } // E
void LD_E_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.b); }
void LD_E_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.c); }
void LD_E_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.d); }
void LD_E_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.e); }
void LD_E_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.h); }
void LD_E_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.e, &gameboy->cpu.l); }


const instruction_t gb_instructions[256] = {
	{ "NOP", 0, NOP }, // 0x00
	{ NULL, 0, NULL }, // 0x01
	{ NULL, 0, NULL }, // 0x02
	{ NULL, 0, NULL }, // 0x03
	{ NULL, 0, NULL }, // 0x04
	{ NULL, 0, NULL }, // 0x05
	{ "LD B, n", 8, LD_B_N }, // 0x06
	{ NULL, 0, NULL }, // 0x07
	{ NULL, 0, NULL }, // 0x08
	{ NULL, 0, NULL }, // 0x09
	{ NULL, 0, NULL }, // 0x0a
	{ NULL, 0, NULL }, // 0x0b
	{ NULL, 0, NULL }, // 0x0c
	{ NULL, 0, NULL }, // 0x0d
	{ "LD C, n", 8, LD_C_N }, // 0x0e
	{ NULL, 0, NULL }, // 0x0f
	{ NULL, 0, NULL }, // 0x10
	{ NULL, 0, NULL }, // 0x11
	{ NULL, 0, NULL }, // 0x12
	{ NULL, 0, NULL }, // 0x13
	{ NULL, 0, NULL }, // 0x14
	{ NULL, 0, NULL }, // 0x15
	{ "LD D, n", 8, LD_D_N }, // 0x16
	{ NULL, 0, NULL }, // 0x17
	{ NULL, 0, NULL }, // 0x18
	{ NULL, 0, NULL }, // 0x19
	{ NULL, 0, NULL }, // 0x1a
	{ NULL, 0, NULL }, // 0x1b
	{ NULL, 0, NULL }, // 0x1c
	{ NULL, 0, NULL }, // 0x1d
	{ "LD E, n", 8, LD_E_N }, // 0x1e
	{ NULL, 0, NULL }, // 0x1f
	{ NULL, 0, NULL }, // 0x20
	{ NULL, 0, NULL }, // 0x21
	{ NULL, 0, NULL }, // 0x22
	{ NULL, 0, NULL }, // 0x23
	{ NULL, 0, NULL }, // 0x24
	{ NULL, 0, NULL }, // 0x25
	{ "LD H, n", 8, LD_H_N }, // 0x26
	{ NULL, 0, NULL }, // 0x27
	{ NULL, 0, NULL }, // 0x28
	{ NULL, 0, NULL }, // 0x29
	{ NULL, 0, NULL }, // 0x2a
	{ NULL, 0, NULL }, // 0x2b
	{ NULL, 0, NULL }, // 0x2c
	{ NULL, 0, NULL }, // 0x2d
	{ "LD L, n", 8, LD_L_N }, // 0x2e
	{ NULL, 0, NULL }, // 0x2f
	{ NULL, 0, NULL }, // 0x30
	{ NULL, 0, NULL }, // 0x31
	{ NULL, 0, NULL }, // 0x32
	{ NULL, 0, NULL }, // 0x33
	{ NULL, 0, NULL }, // 0x34
	{ NULL, 0, NULL }, // 0x35
	{ NULL, 0, NULL }, // 0x36
	{ NULL, 0, NULL }, // 0x37
	{ NULL, 0, NULL }, // 0x38
	{ NULL, 0, NULL }, // 0x39
	{ NULL, 0, NULL }, // 0x3a
	{ NULL, 0, NULL }, // 0x3b
	{ NULL, 0, NULL }, // 0x3c
	{ NULL, 0, NULL }, // 0x3d
	{ NULL, 0, NULL }, // 0x3e
	{ NULL, 0, NULL }, // 0x3f
	{ "LD B, B", 4, LD_B_B }, // 0x40
	{ "LD B, C", 4, LD_B_C }, // 0x41
	{ "LD B, D", 4, LD_B_D }, // 0x42
	{ "LD B, E", 4, LD_B_E }, // 0x43
	{ "LD B, H", 4, LD_B_H }, // 0x44
	{ "LD B, L", 4, LD_B_L }, // 0x45
	{ NULL, 0, NULL }, // 0x46
	{ "LD B, A", 4, LD_B_A }, // 0x47
	{ "LD C, B", 4, LD_C_B }, // 0x48
	{ "LD C, C", 4, LD_C_C }, // 0x49
	{ "LD C, D", 4, LD_C_D }, // 0x4a
	{ "LD C, E", 4, LD_C_E }, // 0x4b
	{ "LD C, H", 4, LD_C_H }, // 0x4c
	{ "LD C, L", 4, LD_C_L }, // 0x4d
	{ NULL, 0, NULL }, // 0x4e
	{ "LD C, A", 4, LD_C_A }, // 0x4f
	{ "LD D, B", 4, LD_D_B }, // 0x50
	{ "LD D, C", 4, LD_D_C }, // 0x51
	{ "LD D, D", 4, LD_D_D }, // 0x52
	{ "LD D, E", 4, LD_D_E }, // 0x53
	{ "LD D, H", 4, LD_D_H }, // 0x54
	{ "LD D, L", 4, LD_D_L }, // 0x55
	{ NULL, 0, NULL }, // 0x56
	{ "LD D, A", 4, LD_D_A }, // 0x57
	{ "LD E, B", 4, LD_E_B },// 0x58
	{ "LD E, C", 4, LD_E_C }, // 0x59
	{ "LD E, D", 4, LD_E_D }, // 0x5a
	{ "LD E, E", 4, LD_E_E }, // 0x5b
	{ "LD E, H", 4, LD_E_H }, // 0x5c
	{ "LD E, L", 4, LD_E_L }, // 0x5d
	{ NULL, 0, NULL }, // 0x5e
	{ "LD E, A", 4, LD_E_A }, // 0x5f
	{ NULL, 0, NULL }, // 0x60
	{ NULL, 0, NULL }, // 0x61
	{ NULL, 0, NULL }, // 0x62
	{ NULL, 0, NULL }, // 0x63
	{ NULL, 0, NULL }, // 0x64
	{ NULL, 0, NULL }, // 0x65
	{ NULL, 0, NULL }, // 0x66
	{ NULL, 0, NULL }, // 0x67
	{ NULL, 0, NULL }, // 0x68
	{ NULL, 0, NULL }, // 0x69
	{ NULL, 0, NULL }, // 0x6a
	{ NULL, 0, NULL }, // 0x6b
	{ NULL, 0, NULL }, // 0x6c
	{ NULL, 0, NULL }, // 0x6d
	{ NULL, 0, NULL }, // 0x6e
	{ NULL, 0, NULL }, // 0x6f
	{ NULL, 0, NULL }, // 0x70
	{ NULL, 0, NULL }, // 0x71
	{ NULL, 0, NULL }, // 0x72
	{ NULL, 0, NULL }, // 0x73
	{ NULL, 0, NULL }, // 0x74
	{ NULL, 0, NULL }, // 0x75
	{ NULL, 0, NULL }, // 0x76
	{ NULL, 0, NULL }, // 0x77
	{ "LD A, B", 4, LD_A_B }, // 0x78
	{ "LD A, C", 4, LD_A_C }, // 0x79
	{ "LD A, D", 4, LD_A_D }, // 0x7a
	{ "LD A, E", 4, LD_A_E }, // 0x7b
	{ "LD A, H", 4, LD_A_H }, // 0x7c
	{ "LD A, L", 4, LD_A_L }, // 0x7d
	{ NULL, 0, NULL }, // 0x7e
	{ "LD A, A", 4, LD_A_A }, // 0x7f
	{ NULL, 0, NULL }, // 0x80
	{ NULL, 0, NULL }, // 0x81
	{ NULL, 0, NULL }, // 0x82
	{ NULL, 0, NULL }, // 0x83
	{ NULL, 0, NULL }, // 0x84
	{ NULL, 0, NULL }, // 0x85
	{ NULL, 0, NULL }, // 0x86
	{ NULL, 0, NULL }, // 0x87
	{ NULL, 0, NULL }, // 0x88
	{ NULL, 0, NULL }, // 0x89
	{ NULL, 0, NULL }, // 0x8a
	{ NULL, 0, NULL }, // 0x8b
	{ NULL, 0, NULL }, // 0x8c
	{ NULL, 0, NULL }, // 0x8d
	{ NULL, 0, NULL }, // 0x8e
	{ NULL, 0, NULL }, // 0x8f
	{ NULL, 0, NULL }, // 0x90
	{ NULL, 0, NULL }, // 0x91
	{ NULL, 0, NULL }, // 0x92
	{ NULL, 0, NULL }, // 0x93
	{ NULL, 0, NULL }, // 0x94
	{ NULL, 0, NULL }, // 0x95
	{ NULL, 0, NULL }, // 0x96
	{ NULL, 0, NULL }, // 0x97
	{ NULL, 0, NULL }, // 0x98
	{ NULL, 0, NULL }, // 0x99
	{ NULL, 0, NULL }, // 0x9a
	{ NULL, 0, NULL }, // 0x9b
	{ NULL, 0, NULL }, // 0x9c
	{ NULL, 0, NULL }, // 0x9d
	{ NULL, 0, NULL }, // 0x9e
	{ NULL, 0, NULL }, // 0x9f
	{ NULL, 0, NULL }, // 0xa0
	{ NULL, 0, NULL }, // 0xa1
	{ NULL, 0, NULL }, // 0xa2
	{ NULL, 0, NULL }, // 0xa3
	{ NULL, 0, NULL }, // 0xa4
	{ NULL, 0, NULL }, // 0xa5
	{ NULL, 0, NULL }, // 0xa6
	{ NULL, 0, NULL }, // 0xa7
	{ NULL, 0, NULL }, // 0xa8
	{ NULL, 0, NULL }, // 0xa9
	{ NULL, 0, NULL }, // 0xaa
	{ NULL, 0, NULL }, // 0xab
	{ NULL, 0, NULL }, // 0xac
	{ NULL, 0, NULL }, // 0xad
	{ NULL, 0, NULL }, // 0xae
	{ NULL, 0, NULL }, // 0xaf
	{ NULL, 0, NULL }, // 0xb0
	{ NULL, 0, NULL }, // 0xb1
	{ NULL, 0, NULL }, // 0xb2
	{ NULL, 0, NULL }, // 0xb3
	{ NULL, 0, NULL }, // 0xb4
	{ NULL, 0, NULL }, // 0xb5
	{ NULL, 0, NULL }, // 0xb6
	{ NULL, 0, NULL }, // 0xb7
	{ NULL, 0, NULL }, // 0xb8
	{ NULL, 0, NULL }, // 0xb9
	{ NULL, 0, NULL }, // 0xba
	{ NULL, 0, NULL }, // 0xbb
	{ NULL, 0, NULL }, // 0xbc
	{ NULL, 0, NULL }, // 0xbd
	{ NULL, 0, NULL }, // 0xbe
	{ NULL, 0, NULL }, // 0xbf
	{ NULL, 0, NULL }, // 0xc0
	{ NULL, 0, NULL }, // 0xc1
	{ NULL, 0, NULL }, // 0xc2
	{ NULL, 0, NULL }, // 0xc3
	{ NULL, 0, NULL }, // 0xc4
	{ NULL, 0, NULL }, // 0xc5
	{ NULL, 0, NULL }, // 0xc6
	{ NULL, 0, NULL }, // 0xc7
	{ NULL, 0, NULL }, // 0xc8
	{ NULL, 0, NULL }, // 0xc9
	{ NULL, 0, NULL }, // 0xca
	{ NULL, 0, NULL }, // 0xcb
	{ NULL, 0, NULL }, // 0xcc
	{ NULL, 0, NULL }, // 0xcd
	{ NULL, 0, NULL }, // 0xce
	{ NULL, 0, NULL }, // 0xcf
	{ NULL, 0, NULL }, // 0xd0
	{ NULL, 0, NULL }, // 0xd1
	{ NULL, 0, NULL }, // 0xd2
	{ NULL, 0, NULL }, // 0xd3
	{ NULL, 0, NULL }, // 0xd4
	{ NULL, 0, NULL }, // 0xd5
	{ NULL, 0, NULL }, // 0xd6
	{ NULL, 0, NULL }, // 0xd7
	{ NULL, 0, NULL }, // 0xd8
	{ NULL, 0, NULL }, // 0xd9
	{ NULL, 0, NULL }, // 0xda
	{ NULL, 0, NULL }, // 0xdb
	{ NULL, 0, NULL }, // 0xdc
	{ NULL, 0, NULL }, // 0xdd
	{ NULL, 0, NULL }, // 0xde
	{ NULL, 0, NULL }, // 0xdf
	{ NULL, 0, NULL }, // 0xe0
	{ NULL, 0, NULL }, // 0xe1
	{ NULL, 0, NULL }, // 0xe2
	{ NULL, 0, NULL }, // 0xe3
	{ NULL, 0, NULL }, // 0xe4
	{ NULL, 0, NULL }, // 0xe5
	{ NULL, 0, NULL }, // 0xe6
	{ NULL, 0, NULL }, // 0xe7
	{ NULL, 0, NULL }, // 0xe8
	{ NULL, 0, NULL }, // 0xe9
	{ NULL, 0, NULL }, // 0xea
	{ NULL, 0, NULL }, // 0xeb
	{ NULL, 0, NULL }, // 0xec
	{ NULL, 0, NULL }, // 0xed
	{ NULL, 0, NULL }, // 0xee
	{ NULL, 0, NULL }, // 0xef
	{ NULL, 0, NULL }, // 0xf0
	{ NULL, 0, NULL }, // 0xf1
	{ NULL, 0, NULL }, // 0xf2
	{ NULL, 0, NULL }, // 0xf3
	{ NULL, 0, NULL }, // 0xf4
	{ NULL, 0, NULL }, // 0xf5
	{ NULL, 0, NULL }, // 0xf6
	{ NULL, 0, NULL }, // 0xf7
	{ NULL, 0, NULL }, // 0xf8
	{ NULL, 0, NULL }, // 0xf9
	{ NULL, 0, NULL }, // 0xfa
	{ NULL, 0, NULL }, // 0xfb
	{ NULL, 0, NULL }, // 0xfc
	{ NULL, 0, NULL }, // 0xfd
	{ NULL, 0, NULL }, // 0xfe
	{ NULL, 0, NULL }  // 0xff
};
