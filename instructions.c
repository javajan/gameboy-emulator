// Implements all ~512 instructions taken from the
// CPU manual at http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#include "gameboy.h"
#include "memory.h"

// ############################################################
// ############################################################
// ############################################################
// #################### BASE INSTRUCTIONS  ####################
// ############################################################
// ############################################################
// ############################################################

void NOP(gameboy_t* gameboy) {}

// ############################################################
// #################### LOAD / SAVE / MOVE ####################
// ############################################################

// Loads R1 with immediate value (next value after this instruction)
void LD_R1_N(gameboy_t* gameboy, uint8_t* r1) {
	uint8_t n = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	*r1 = n;	
}
void LD_A_N(gameboy_t* gameboy) { LD_R1_N(gameboy, &(gameboy->cpu.a)); }
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
void LD_H_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.a); } // H
void LD_H_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.b); }
void LD_H_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.c); }
void LD_H_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.d); }
void LD_H_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.e); }
void LD_H_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.h); }
void LD_H_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.h, &gameboy->cpu.l); }
void LD_L_A(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.a); } // L
void LD_L_B(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.b); }
void LD_L_C(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.c); }
void LD_L_D(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.d); }
void LD_L_E(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.e); }
void LD_L_H(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.h); }
void LD_L_L(gameboy_t* gameboy) { LD_R1_R2(&gameboy->cpu.l, &gameboy->cpu.l); }

// Moves the value in memory at address R2 to R1
void LD_LOAD_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint16_t r2) {
	*r1 = gb_mem_read(gameboy->memory, r2);
}
void LD_LOAD_A_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.hl); } // HL
void LD_LOAD_B_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.b, gameboy->cpu.hl); }
void LD_LOAD_C_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.c, gameboy->cpu.hl); }
void LD_LOAD_D_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.d, gameboy->cpu.hl); }
void LD_LOAD_E_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.e, gameboy->cpu.hl); }
void LD_LOAD_H_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.h, gameboy->cpu.hl); }
void LD_LOAD_L_HL(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.l, gameboy->cpu.hl); }
void LD_LOAD_A_BC(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.bc); } // BC
void LD_LOAD_A_DE(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.de); } // DE
void LD_LOAD_A_C_HIGH(gameboy_t* gameboy) { LD_LOAD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c + 0xFF00); } // C + 0xFF00

// Moves the value of r2 into memory at address r1
void LD_SAVE_R1_R2(gameboy_t* gameboy, uint16_t r1, uint8_t r2) {
	gb_mem_write(gameboy->memory, r1, r2);
}
void LD_SAVE_HL_A(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.a); } // HL
void LD_SAVE_HL_B(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.b); }
void LD_SAVE_HL_C(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.c); }
void LD_SAVE_HL_D(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.d); }
void LD_SAVE_HL_E(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.e); }
void LD_SAVE_HL_H(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.h); }
void LD_SAVE_HL_L(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.hl, gameboy->cpu.l); }
void LD_SAVE_BC_A(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.bc, gameboy->cpu.a); } // BC
void LD_SAVE_DE_A(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.de, gameboy->cpu.a); } // DE
void LD_SAVE_C_HIGH_A(gameboy_t* gameboy) { LD_SAVE_R1_R2(gameboy, gameboy->cpu.c + 0xFF00, gameboy->cpu.a); } // C + 0xFF00

// Moves the immediate value to memory at address R1
void LD_SAVE_R1_N(gameboy_t* gameboy, uint16_t r1) {
	uint8_t n = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	gb_mem_write(gameboy->memory, r1, n);
}
void LD_SAVE_HL_N(gameboy_t* gameboy) { LD_SAVE_R1_N(gameboy, gameboy->cpu.hl); } // 0x36

// Loads R1 with the value in memory at address nn
void LD_LOAD_A_NN(gameboy_t* gameboy) {
	uint8_t n1 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	uint8_t n2 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	
	uint16_t nn = ((uint16_t)n2) << 8 | n1;
	gameboy->cpu.a = gb_mem_read(gameboy->memory, nn);
}

// Saves R1 in memory at the at address nn
void LD_SAVE_A_NN(gameboy_t* gameboy) {
	uint8_t n1 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	uint8_t n2 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	
	uint16_t nn = ((uint16_t)n2) << 8 | n1;
	gb_mem_write(gameboy->memory, nn, gameboy->cpu.a);
}

void LDD_LOAD_A_HL(gameboy_t* gameboy) { LD_LOAD_A_HL(gameboy); gameboy->cpu.hl--; }
void LDD_SAVE_HL_A(gameboy_t* gameboy) { LD_SAVE_HL_A(gameboy); gameboy->cpu.hl--; }
void LDI_LOAD_A_HL(gameboy_t* gameboy) { LD_LOAD_A_HL(gameboy); gameboy->cpu.hl++; }
void LDI_SAVE_HL_A(gameboy_t* gameboy) { LD_SAVE_HL_A(gameboy); gameboy->cpu.hl++; }

// Put A into memory address 0xFF00+n
void LDH_SAVE_A_N(gameboy_t* gameboy) { 
	uint16_t n = (uint16_t)gb_mem_read(gameboy->memory, gameboy->cpu.pc) + 0xFF00;
	gameboy->cpu.pc++;
	gb_mem_write(gameboy->memory, n, gameboy->cpu.a);
}
// Put memory address 0xFF00+n into A
void LDH_LOAD_A_N(gameboy_t* gameboy) { 
	uint16_t n = (uint16_t)gb_mem_read(gameboy->memory, gameboy->cpu.pc) + 0xFF00;
	gameboy->cpu.pc++;
	gameboy->cpu.a = gb_mem_read(gameboy->memory, n);
}

// Put nn into r1
void LD_R1_NN(gameboy_t* gameboy, uint16_t* r1) {
	uint8_t n1 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	uint8_t n2 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	
	*r1 = ((uint16_t)n2) << 8 | n1;
}
void LD_BC_NN(gameboy_t* gameboy) { LD_R1_NN(gameboy, &gameboy->cpu.bc); }
void LD_DE_NN(gameboy_t* gameboy) { LD_R1_NN(gameboy, &gameboy->cpu.de); }
void LD_HL_NN(gameboy_t* gameboy) { LD_R1_NN(gameboy, &gameboy->cpu.hl); }
void LD_SP_NN(gameboy_t* gameboy) { LD_R1_NN(gameboy, &gameboy->cpu.sp); }

// Copies r2 to r1
void LD_R1_R2_16Bit(uint16_t* r1, uint16_t* r2) {
	*r1 = *r2;
}
void LD_SP_HL(gameboy_t* gameboy) { LD_R1_R2_16Bit(&gameboy->cpu.sp, &gameboy->cpu.hl); }

// Put SP + n into HL
void LDHL_SP_N(gameboy_t* gameboy) {
	uint16_t n = (uint16_t)(int8_t)gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	uint16_t sp = gameboy->cpu.sp;
	uint16_t sum = sp + n;

	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, ((n ^ sp ^ sum) & 0x10) == 0x10);
	gb_flag_set(gameboy, GB_FLAG_CARRY, ((n ^ sp ^ sum) & 0x100) != 0);
	
	gameboy->cpu.hl = sum;
}
// Put Stack Pointer (SP) at address 
void LD_NN_SP(gameboy_t* gameboy) {
	uint8_t n1 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	uint8_t n2 = gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	
	uint16_t nn = ((uint16_t)n2) << 8 | n1;
	gb_mem_write(gameboy->memory, nn, (uint8_t)gameboy->cpu.sp);
	gb_mem_write(gameboy->memory, nn+1, (uint8_t)(gameboy->cpu.sp >> 8));
}

void PUSH(gameboy_t* gameboy, uint16_t r1) {
	gameboy->cpu.sp -= 2;
	
	gb_mem_write(gameboy->memory, gameboy->cpu.sp, (uint8_t)r1);
	gb_mem_write(gameboy->memory, gameboy->cpu.sp+1, (uint8_t)(r1 >> 8));
}
void PUSH_AF(gameboy_t* gameboy) { PUSH(gameboy, gameboy->cpu.af); }
void PUSH_BC(gameboy_t* gameboy) { PUSH(gameboy, gameboy->cpu.bc); }
void PUSH_DE(gameboy_t* gameboy) { PUSH(gameboy, gameboy->cpu.de); }
void PUSH_HL(gameboy_t* gameboy) { PUSH(gameboy, gameboy->cpu.hl); }

void POP(gameboy_t* gameboy, uint16_t* r1) {
	*r1 = ((uint16_t)gb_mem_read(gameboy->memory, gameboy->cpu.sp+1)) << 8 | gb_mem_read(gameboy->memory, gameboy->cpu.sp);
	gameboy->cpu.sp += 2;
}
void POP_AF(gameboy_t* gameboy) { POP(gameboy, &gameboy->cpu.af); }
void POP_BC(gameboy_t* gameboy) { POP(gameboy, &gameboy->cpu.bc); }
void POP_DE(gameboy_t* gameboy) { POP(gameboy, &gameboy->cpu.de); }
void POP_HL(gameboy_t* gameboy) { POP(gameboy, &gameboy->cpu.hl); }



// ############################################################
// ####################      ADD   SUB     ####################
// ############################################################


// Adds r2 to r1
void ADD_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	uint8_t lowAdd = ((*r1) & 0x0F) + (r2 & 0x0F);
	uint16_t result = *r1 + r2;

	*r1 = (uint8_t) result;

	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, lowAdd > 0x0F);
	gb_flag_set(gameboy, GB_FLAG_CARRY, result > 0xFF);
}
void ADD_A_A(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); };
void ADD_A_B(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); };
void ADD_A_C(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); };
void ADD_A_D(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); };
void ADD_A_E(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); };
void ADD_A_H(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); };
void ADD_A_L(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); };
void ADD_A_mHL(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void ADD_A_N(gameboy_t* gameboy) { ADD_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }

// Also adds carry bit
void ADC_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	uint8_t carry = 0;
	if (gb_flag_get(*gameboy, GB_FLAG_CARRY))
		carry = 1;

	uint8_t nibbleAdd = ((*r1) & 0x0F) + (r2 & 0x0F) + carry;
	uint16_t byteAdd = *r1 + r2 + carry;

	*r1 = (uint8_t) byteAdd;

	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, nibbleAdd > 0x0F);
	gb_flag_set(gameboy, GB_FLAG_CARRY, byteAdd > 0xFF);
}
void ADC_A_A(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); };
void ADC_A_B(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); };
void ADC_A_C(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); };
void ADC_A_D(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); };
void ADC_A_E(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); };
void ADC_A_H(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); };
void ADC_A_L(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); };
void ADC_A_mHL(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void ADC_A_N(gameboy_t* gameboy) { ADC_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }

// Subtracts r2 from r1
void SUB_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	uint8_t nibbleSub = ((*r1) & 0x0F) - (r2 & 0x0F);
	uint16_t byteSub = *r1 - r2;

	*r1 = (uint8_t) byteSub;

	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, true);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, nibbleSub > 0x0F);
	gb_flag_set(gameboy, GB_FLAG_CARRY, byteSub > 0xFF);
}
void SUB_A_A(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); };
void SUB_A_B(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); };
void SUB_A_C(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); };
void SUB_A_D(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); };
void SUB_A_E(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); };
void SUB_A_H(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); };
void SUB_A_L(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); };
void SUB_A_mHL(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void SUB_A_N(gameboy_t* gameboy) { SUB_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }

// Also subtracts carry bit
void SBC_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	uint8_t carry = 0;
	if (gb_flag_get(*gameboy, GB_FLAG_CARRY))
		carry = 1;

	uint8_t nibbleSub = ((*r1) & 0x0F) - (r2 & 0x0F) - carry;
	uint16_t byteSub = *r1 - r2 - carry;

	*r1 = (uint8_t) byteSub;

	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, true);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, nibbleSub > 0x0F);
	gb_flag_set(gameboy, GB_FLAG_CARRY, byteSub > 0xFF);
}
void SBC_A_A(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); };
void SBC_A_B(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); };
void SBC_A_C(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); };
void SBC_A_D(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); };
void SBC_A_E(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); };
void SBC_A_H(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); };
void SBC_A_L(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); };
void SBC_A_mHL(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void SBC_A_N(gameboy_t* gameboy) { SBC_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }

// Adds r2 to r1 for 16 bit registers
void ADD_R1_R2_16Bit(gameboy_t* gameboy, uint16_t* r1, uint16_t r2) {
	uint16_t lowAdd = ((*r1) & 0x00FF) + (r2 & 0x00FF);
	uint32_t result = *r1 + r2;

	*r1 = (uint16_t) result;

	bool oldZero = gb_flag_get(*gameboy, GB_FLAG_ZERO);
	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, oldZero);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, lowAdd > 0x0FFF);
	gb_flag_set(gameboy, GB_FLAG_CARRY, result > 0xFFFF);
}
void ADD_HL_HL(gameboy_t* gameboy) { ADD_R1_R2_16Bit(gameboy, &gameboy->cpu.hl, gameboy->cpu.hl); }
void ADD_HL_BC(gameboy_t* gameboy) { ADD_R1_R2_16Bit(gameboy, &gameboy->cpu.hl, gameboy->cpu.hl); }
void ADD_HL_DE(gameboy_t* gameboy) { ADD_R1_R2_16Bit(gameboy, &gameboy->cpu.hl, gameboy->cpu.hl); }
void ADD_HL_SP(gameboy_t* gameboy) { ADD_R1_R2_16Bit(gameboy, &gameboy->cpu.hl, gameboy->cpu.hl); }

void ADD_SP_N(gameboy_t* gameboy) {
	uint16_t n = (uint16_t)(int8_t)gb_mem_read(gameboy->memory, gameboy->cpu.pc);
	gameboy->cpu.pc++;
	uint16_t sp = gameboy->cpu.sp;
	uint16_t sum = sp + n;

	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, ((n ^ sp ^ sum) & 0x10) == 0x10);
	gb_flag_set(gameboy, GB_FLAG_CARRY, ((n ^ sp ^ sum) & 0x100) == 0x100);
	
	gameboy->cpu.sp = sum;
}


// ############################################################
// ####################     AND OR XOR     ####################
// ############################################################


// Logical AND operation, stores result in r1, sets zero flag accordingly
void AND_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	*r1 = (*r1) & r2;
	
	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, true);
}
void AND_A_A(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); }
void AND_A_B(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); }
void AND_A_C(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); }
void AND_A_D(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); }
void AND_A_E(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); }
void AND_A_H(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); }
void AND_A_L(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); }
void AND_A_mHL(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void AND_A_N(gameboy_t* gameboy) { AND_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }

// Logical OR operation, stores result in r1, sets zero flag accordingly
void OR_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	*r1 = (*r1) | r2;
	
	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
}
void OR_A_A(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); }
void OR_A_B(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); }
void OR_A_C(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); }
void OR_A_D(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); }
void OR_A_E(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); }
void OR_A_H(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); }
void OR_A_L(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); }
void OR_A_mHL(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void OR_A_N(gameboy_t* gameboy) { OR_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }

// Logical XOR operation, stores result in r1, sets zero flag accordingly
void XOR_R1_R2(gameboy_t* gameboy, uint8_t* r1, uint8_t r2) {
	*r1 = (*r1) ^ r2;
	
	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
}
void XOR_A_A(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.a); }
void XOR_A_B(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.b); }
void XOR_A_C(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.c); }
void XOR_A_D(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.d); }
void XOR_A_E(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.e); }
void XOR_A_H(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.h); }
void XOR_A_L(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gameboy->cpu.l); }
void XOR_A_mHL(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.hl)); }
void XOR_A_N(gameboy_t* gameboy) { XOR_R1_R2(gameboy, &gameboy->cpu.a, gb_mem_read(gameboy->memory, gameboy->cpu.pc)); gameboy->cpu.pc++; }




// ############################################################
// ####################     CMP INC DEC    ####################
// ############################################################

void CMP_A_A(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_A(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_B(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_B(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_C(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_C(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_D(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_D(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_E(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_E(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_H(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_H(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_L(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_L(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_mHL(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_mHL(gameboy); gameboy->cpu.a = tmp; }
void CMP_A_N(gameboy_t* gameboy) { uint8_t tmp = gameboy->cpu.a; SUB_A_N(gameboy); gameboy->cpu.a = tmp; }

void INC(gameboy_t* gameboy, uint8_t* r1) {
	(*r1)++;
	
	bool oldCarry = gb_flag_get(*gameboy, GB_FLAG_CARRY);
	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, ((*r1) & 0xF) == 0);
	gb_flag_set(gameboy, GB_FLAG_CARRY, oldCarry);
}
void INC_A(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.a); }
void INC_B(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.b); }
void INC_C(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.c); }
void INC_D(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.d); }
void INC_E(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.e); }
void INC_H(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.h); }
void INC_L(gameboy_t* gameboy) { INC(gameboy, &gameboy->cpu.l); }
void INC_mHL(gameboy_t* gameboy) { 
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	INC(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}

void DEC(gameboy_t* gameboy, uint8_t* r1) {
	(*r1)--;
	
	bool oldCarry = gb_flag_get(*gameboy, GB_FLAG_CARRY);
	gb_flag_reset(gameboy);
	gb_flag_set(gameboy, GB_FLAG_ZERO, *r1 == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, true);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, ((*r1) & 0xF) == 0xF);
	gb_flag_set(gameboy, GB_FLAG_CARRY, oldCarry);
}
void DEC_A(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.a); }
void DEC_B(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.b); }
void DEC_C(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.c); }
void DEC_D(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.d); }
void DEC_E(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.e); }
void DEC_H(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.h); }
void DEC_L(gameboy_t* gameboy) { DEC(gameboy, &gameboy->cpu.l); }
void DEC_mHL(gameboy_t* gameboy) { 
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	DEC(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}

void INC16Bit(gameboy_t* gameboy, uint16_t* r1) {
	(*r1)++;
}
void INC_BC(gameboy_t* gameboy) { INC16Bit(gameboy, &gameboy->cpu.bc); }
void INC_DE(gameboy_t* gameboy) { INC16Bit(gameboy, &gameboy->cpu.de); }
void INC_HL(gameboy_t* gameboy) { INC16Bit(gameboy, &gameboy->cpu.hl); }
void INC_SP(gameboy_t* gameboy) { INC16Bit(gameboy, &gameboy->cpu.sp); }

void DEC16Bit(gameboy_t* gameboy, uint16_t* r1) {
	(*r1)--;
}
void DEC_BC(gameboy_t* gameboy) { DEC16Bit(gameboy, &gameboy->cpu.bc); }
void DEC_DE(gameboy_t* gameboy) { DEC16Bit(gameboy, &gameboy->cpu.de); }
void DEC_HL(gameboy_t* gameboy) { DEC16Bit(gameboy, &gameboy->cpu.hl); }
void DEC_SP(gameboy_t* gameboy) { DEC16Bit(gameboy, &gameboy->cpu.sp); }




// ############################################################
// ####################    Miscellaneous   ####################
// ############################################################
// TODO: DAA 0x27

void CPL_A(gameboy_t* gameboy) {
	gameboy->cpu.a = ~(gameboy->cpu.a);

	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, true);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, true);
}

void CCF(gameboy_t* gameboy) {
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_flip(gameboy, GB_FLAG_CARRY);
}

void SCF(gameboy_t* gameboy) {
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, true);
}

void HALT(gameboy_t* gameboy) { gb_halt(gameboy); }
void STOP(gameboy_t* gameboy) { gameboy->cpu.pc++; gb_stop(gameboy); }
void DI(gameboy_t* gameboy) { gb_disable_interrupts(gameboy); };
void EI(gameboy_t* gameboy) { gb_enable_interrupts(gameboy); };

// ############################################################
// ##################   Rotates and Shifts   ##################
// ############################################################

void RLCA(gameboy_t* gameboy) {
	bool bit7 = (gameboy->cpu.a & (0x01 << 7)) != 0;
	gameboy->cpu.a = gameboy->cpu.a << 1 | (bit7 ? 1 : 0);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, gameboy->cpu.a == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit7);
}

void RLA(gameboy_t* gameboy) {
	bool bit7 = (gameboy->cpu.a & (0x01 << 7)) != 0;
	gameboy->cpu.a = gameboy->cpu.a << 1 | (gb_flag_get(*gameboy, GB_FLAG_CARRY) ? 1 : 0);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, gameboy->cpu.a == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit7);
}

void RRCA(gameboy_t* gameboy) {
	bool bit0 = (gameboy->cpu.a & 0x01) != 0;
	gameboy->cpu.a = gameboy->cpu.a >> 1 | ((bit0 ? 1 : 0) << 7);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, gameboy->cpu.a == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit0);
}

void RRA(gameboy_t* gameboy) {
	bool bit0 = (gameboy->cpu.a & 0x01) != 0;
	gameboy->cpu.a = gameboy->cpu.a >> 1 | ((gb_flag_get(*gameboy, GB_FLAG_CARRY) ? 1 : 0) << 7);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, gameboy->cpu.a == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit0);
}

// ############################################################
// ##################          JUMPS         ##################
// ############################################################

void JMP(gameboy_t* gameboy, uint16_t pos) {
	gameboy->cpu.pc = pos;
}

void JP_HL(gameboy_t* gameboy) { JMP(gameboy, gameboy->cpu.hl); }

// jump absolute
void JP_NN(gameboy_t* gameboy) {
	JMP(gameboy, gb_read_nn(gameboy));
}

// jump absolute if flag
void JP_Z_NN(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_ZERO))
		JP_NN(gameboy);
	else
		gameboy->cpu.pc += 2;
}
void JP_NZ_NN(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_ZERO))
		JP_NN(gameboy);
	else
		gameboy->cpu.pc += 2;
}
void JP_C_NN(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_CARRY))
		JP_NN(gameboy);
	else
		gameboy->cpu.pc += 2;
}
void JP_NC_NN(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_CARRY))
		JP_NN(gameboy);
	else
		gameboy->cpu.pc += 2;
}

// jump to relative position
void JR(gameboy_t* gameboy) {
	// order is important since gb_read_n increases pc
	int8_t n = (int8_t) gb_read_n(gameboy);
	JMP(gameboy, gameboy->cpu.pc + n);
}

// jump relative if flag
void JR_Z(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_ZERO))
		JR(gameboy);
	else
		gameboy->cpu.pc += 1;
}
void JR_NZ(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_ZERO))
		JR(gameboy);
	else
		gameboy->cpu.pc += 1;
}
void JR_C(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_CARRY))
		JR(gameboy);
	else
		gameboy->cpu.pc += 1;
}
void JR_NC(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_CARRY))
		JR(gameboy);
	else
		gameboy->cpu.pc += 1;
}

// ############################################################
// ##################       CALL RETURN      ##################
// ############################################################

// Push next instruction address on stack and jump to nn
void CALL(gameboy_t* gameboy) {
	PUSH(gameboy, gameboy->cpu.pc+2);
	JP_NN(gameboy);
}

void CALL_Z(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_ZERO))
		CALL(gameboy);
	else
		gameboy->cpu.pc += 2;
}

void CALL_NZ(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_ZERO))
		CALL(gameboy);
	else
		gameboy->cpu.pc += 2;
}

void CALL_C(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_CARRY))
		CALL(gameboy);
	else
		gameboy->cpu.pc += 2;
}

void CALL_NC(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_CARRY))
		CALL(gameboy);
	else
		gameboy->cpu.pc += 2;
}

// Pop nn from stack and jump to nn
void RET(gameboy_t* gameboy) {
	POP(gameboy, &gameboy->cpu.pc);
}

void RET_Z(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_ZERO))
		RET(gameboy);
}

void RET_NZ(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_ZERO))
		RET(gameboy);
}

void RET_C(gameboy_t* gameboy) {
	if (gb_flag_get(*gameboy, GB_FLAG_CARRY))
		RET(gameboy);
}

void RET_NC(gameboy_t* gameboy) {
	if (!gb_flag_get(*gameboy, GB_FLAG_CARRY))
		RET(gameboy);
}

void RETI(gameboy_t* gameboy) {
	RET(gameboy);
	gb_enable_interrupts(gameboy);
}

// Save current pc and jump to address
void RST(gameboy_t* gameboy, uint16_t pc) {
	PUSH(gameboy, gameboy->cpu.pc);
	gameboy->cpu.pc = pc;
}
void RST_00(gameboy_t* gameboy) { RST(gameboy, 0x00); }
void RST_08(gameboy_t* gameboy) { RST(gameboy, 0x08); }
void RST_10(gameboy_t* gameboy) { RST(gameboy, 0x10); }
void RST_18(gameboy_t* gameboy) { RST(gameboy, 0x18); }
void RST_20(gameboy_t* gameboy) { RST(gameboy, 0x20); }
void RST_28(gameboy_t* gameboy) { RST(gameboy, 0x28); }
void RST_30(gameboy_t* gameboy) { RST(gameboy, 0x30); }
void RST_38(gameboy_t* gameboy) { RST(gameboy, 0x38); }


const instruction_t gb_base_instructions[256] = {
	{ "NOP", 0, 0, NOP }, 						// 0x00
	{ "LD BC, $%02x%02x", 2, 12, LD_BC_NN }, 	// 0x01
	{ "LD [BC], A", 0, 8, LD_SAVE_BC_A }, 		// 0x02
	{ "INC BC", 0, 8, INC_BC }, 				// 0x03
	{ "INC B", 0, 4, INC_B }, 					// 0x04
	{ "DEC B", 0, 4, DEC_B }, 					// 0x05
	{ "LD B, n", 1, 8, LD_B_N }, 				// 0x06
	{ "RLCA", 0, 4, RLCA }, 					// 0x07
	{ "LD [$%02x%02x], SP", 2, 20, LD_NN_SP }, 	// 0x08
	{ "ADD HL, BC", 0, 8, ADD_HL_BC }, 		// 0x09
	{ "LD A, [BC]", 0, 8, LD_LOAD_A_BC }, 		// 0x0a
	{ "DEC BC", 0, 8, DEC_BC }, 				// 0x0b
	{ "INC C", 0, 4, INC_C }, 					// 0x0c
	{ "DEC C", 0, 4, DEC_C }, 					// 0x0d
	{ "LD C, $%02x", 1, 8, LD_C_N }, 			// 0x0e
	{ "RCA", 0, 4, RRCA }, 						// 0x0f
	{ "STOP", 0, 4, STOP }, 					// 0x10
	{ "LD DE, $%02x%02x", 2, 12, LD_DE_NN },	// 0x11
	{ "LD [DE], A", 0, 8, LD_SAVE_DE_A }, 		// 0x12
	{ "INC DE", 0, 8, INC_DE }, 				// 0x13
	{ "INC D", 0, 4, INC_D }, 					// 0x14
	{ "DEC D", 0, 4, DEC_D }, 					// 0x15
	{ "LD D, $%02x", 1, 8, LD_D_N }, 			// 0x16
	{ "RLA", 0, 4, RLA }, 						// 0x17
	{ "JR $%02x", 1, 8, JR }, 					// 0x18
	{ "ADD HL, DE", 0, 8, ADD_HL_DE },			// 0x19
	{ "LD A, [DE]", 0, 8, LD_LOAD_A_DE }, 		// 0x1a
	{ "DEC DE", 0, 8, DEC_DE }, 				// 0x1b
	{ "INC E", 0, 4, INC_E }, 					// 0x1c
	{ "DEC E", 0, 4, DEC_E }, 					// 0x1d
	{ "LD E, $%02x", 1, 8, LD_E_N }, 			// 0x1e
	{ "RRA", 0, 4, RRA }, 						// 0x1f
	{ "JR NZ $%02x", 1, 8, JR_NZ }, 			// 0x20
	{ "LD HL, $%02x%02x", 2, 12, LD_HL_NN }, 	// 0x21
	{ "LDI [HL], A", 0, 8, LDI_SAVE_HL_A }, 	// 0x22
	{ "INC HL", 0, 8, INC_HL }, 				// 0x23
	{ "INC H", 0, 4, INC_H }, 					// 0x24
	{ "DEC H", 0, 4, DEC_H }, 					// 0x25
	{ "LD H, $%02x", 0, 8, LD_H_N }, 			// 0x26
	{ NULL, 0, 0, NULL }, 						// 0x27
	{ "JR Z $%02x", 1, 8, JR_Z }, 				// 0x28
	{ "ADD HL, HL", 0, 8, ADD_HL_HL }, 			// 0x29
	{ "LDI A, [HL]", 0, 8, LDI_LOAD_A_HL }, 	// 0x2a
	{ "DEC HL", 0, 8, DEC_HL }, 				// 0x2b
	{ "INC L", 0, 4, INC_L }, 					// 0x2c
	{ "DEC L", 0, 4, DEC_L }, 					// 0x2d
	{ "LD L, $%02x", 1, 8, LD_L_N }, 			// 0x2e
	{ "CPL A", 0, 4, CPL_A }, 					// 0x2f
	{ "JR NC $%02x", 1, 8, JR_NC }, 			// 0x30
	{ "LD SP, $%02x%02x", 2, 12, LD_SP_NN },	// 0x31
	{ "LDD [HL], A", 0, 8, LDD_SAVE_HL_A }, 	// 0x32
	{ "INC SP", 0, 8, INC_SP }, // 0x33
	{ "INC [HL]", 0, 12, INC_mHL }, // 0x34
	{ "DEC [HL]", 0, 12, DEC_mHL }, // 0x35
	{ "LD [HL], $%02x", 1, 12, LD_SAVE_HL_N }, // 0x36
	{ "SCF", 0, 4, SCF }, // 0x37
	{ "JR C $%02x", 1, 8, JR_C }, // 0x38
	{ "ADD HL, SP", 0, 8, ADD_HL_SP }, // 0x39
	{ "LDD A, [HL]", 0, 8, LDD_LOAD_A_HL }, // 0x3a
	{ "DEC SP", 0, 8, DEC_SP }, // 0x3b
	{ "INC A", 0, 4, INC_A }, // 0x3c
	{ "DEC A", 0, 4, DEC_A }, // 0x3d
	{ "LD A, $%02x", 1, 8, LD_A_N }, // 0x3e
	{ "CCF", 0, 4, CCF }, // 0x3f
	{ "LD B, B", 0, 4, LD_B_B }, // 0x40
	{ "LD B, C", 0, 4, LD_B_C }, // 0x41
	{ "LD B, D", 0, 4, LD_B_D }, // 0x42
	{ "LD B, E", 0, 4, LD_B_E }, // 0x43
	{ "LD B, H", 0, 4, LD_B_H }, // 0x44
	{ "LD B, L", 0, 4, LD_B_L }, // 0x45
	{ "LD B, [HL]", 0, 8, LD_LOAD_B_HL }, // 0x46
	{ "LD B, A", 0, 4, LD_B_A }, // 0x47
	{ "LD C, B", 0, 4, LD_C_B }, // 0x48
	{ "LD C, C", 0, 4, LD_C_C }, // 0x49
	{ "LD C, D", 0, 4, LD_C_D }, // 0x4a
	{ "LD C, E", 0, 4, LD_C_E }, // 0x4b
	{ "LD C, H", 0, 4, LD_C_H }, // 0x4c
	{ "LD C, L", 0, 4, LD_C_L }, // 0x4d
	{ "LD C, [HL]", 0, 8, LD_LOAD_C_HL }, // 0x4e
	{ "LD C, A", 0, 4, LD_C_A }, // 0x4f
	{ "LD D, B", 0, 4, LD_D_B }, // 0x50
	{ "LD D, C", 0, 4, LD_D_C }, // 0x51
	{ "LD D, D", 0, 4, LD_D_D }, // 0x52
	{ "LD D, E", 0, 4, LD_D_E }, // 0x53
	{ "LD D, H", 0, 4, LD_D_H }, // 0x54
	{ "LD D, L", 0, 4, LD_D_L }, // 0x55
	{ "LD D, [HL]", 0, 8, LD_LOAD_D_HL }, // 0x56
	{ "LD D, A", 0, 4, LD_D_A }, // 0x57
	{ "LD E, B", 0, 4, LD_E_B },// 0x58
	{ "LD E, C", 0, 4, LD_E_C }, // 0x59
	{ "LD E, D", 0, 4, LD_E_D }, // 0x5a
	{ "LD E, E", 0, 4, LD_E_E }, // 0x5b
	{ "LD E, H", 0, 4, LD_E_H }, // 0x5c
	{ "LD E, L", 0, 4, LD_E_L }, // 0x5d
	{ "LD E, [HL]", 0, 8, LD_LOAD_E_HL }, // 0x5e
	{ "LD E, A", 0, 4, LD_E_A }, // 0x5f
	{ "LD H, B", 0, 4, LD_H_B }, // 0x60
	{ "LD H, C", 0, 4, LD_H_C }, // 0x61
	{ "LD H, D", 0, 4, LD_H_D }, // 0x62
	{ "LD H, E", 0, 4, LD_H_E }, // 0x63
	{ "LD H, H", 0, 4, LD_H_H }, // 0x64
	{ "LD H, L", 0, 4, LD_H_L }, // 0x65
	{ "LD H, [HL]", 0, 8, LD_LOAD_H_HL }, // 0x66
	{ "LD H, A", 0, 4, LD_H_A }, // 0x67
	{ "LD L, B", 0, 4, LD_L_B }, // 0x68
	{ "LD L, C", 0, 4, LD_L_C }, // 0x69
	{ "LD L, D", 0, 4, LD_L_D }, // 0x6a
	{ "LD L, E", 0, 4, LD_L_E }, // 0x6b
	{ "LD L, H", 0, 4, LD_L_H }, // 0x6c
	{ "LD L, L", 0, 4, LD_L_L }, // 0x6d
	{ "LD L, [HL]", 0, 8, LD_LOAD_L_HL }, // 0x6e
	{ "LD L, A", 0, 4, LD_L_A }, // 0x6f
	{ "LD [HL], B", 0, 8, LD_SAVE_HL_B }, // 0x70
	{ "LD [HL], C", 0, 8, LD_SAVE_HL_C }, // 0x71
	{ "LD [HL], D", 0, 8, LD_SAVE_HL_D }, // 0x72
	{ "LD [HL], E", 0, 8, LD_SAVE_HL_E }, // 0x73
	{ "LD [HL], H", 0, 8, LD_SAVE_HL_H }, // 0x74
	{ "LD [HL], L", 0, 8, LD_SAVE_HL_L }, // 0x75
	{ "HALT", 0, 4, HALT }, // 0x76
	{ "LD [HL], A", 0, 8, LD_SAVE_HL_A }, // 0x77
	{ "LD A, B", 0, 4, LD_A_B }, // 0x78
	{ "LD A, C", 0, 4, LD_A_C }, // 0x79
	{ "LD A, D", 0, 4, LD_A_D }, // 0x7a
	{ "LD A, E", 0, 4, LD_A_E }, // 0x7b
	{ "LD A, H", 0, 4, LD_A_H }, // 0x7c
	{ "LD A, L", 0, 4, LD_A_L }, // 0x7d
	{ "LD A, [HL]", 0, 8, LD_LOAD_A_HL }, // 0x7e
	{ "LD A, A", 0, 4, LD_A_A }, // 0x7f
	{ "ADD A, B", 0, 4, ADD_A_B }, // 0x80
	{ "ADD A, C", 0, 4, ADD_A_C }, // 0x81
	{ "ADD A, D", 0, 4, ADD_A_D }, // 0x82
	{ "ADD A, E", 0, 4, ADD_A_E }, // 0x83
	{ "ADD A, H", 0, 4, ADD_A_H }, // 0x84
	{ "ADD A, L", 0, 4, ADD_A_L }, // 0x85
	{ "ADD A, [HL]", 0, 8, ADD_A_mHL }, // 0x86
	{ "ADD A, A", 0, 4, ADD_A_A }, // 0x87
	{ "ADC A, B", 0, 4, ADC_A_B }, // 0x88
	{ "ADC A, C", 0, 4, ADC_A_C }, // 0x89
	{ "ADC A, D", 0, 4, ADC_A_D }, // 0x8a
	{ "ADC A, E", 0, 4, ADC_A_E }, // 0x8b
	{ "ADC A, H", 0, 4, ADC_A_H }, // 0x8c
	{ "ADC A, L", 0, 4, ADC_A_L }, // 0x8d
	{ "ADC A, [HL]", 0, 8, ADC_A_mHL }, // 0x8e
	{ "ADC A, A", 0, 4, ADC_A_A }, // 0x8f
	{ "SUB A, B", 0, 4, SUB_A_B }, // 0x90
	{ "SUB A, C", 0, 4, SUB_A_C }, // 0x91
	{ "SUB A, D", 0, 4, SUB_A_D }, // 0x92
	{ "SUB A, E", 0, 4, SUB_A_E }, // 0x93
	{ "SUB A, H", 0, 4, SUB_A_H }, // 0x94
	{ "SUB A, L", 0, 4, SUB_A_L }, // 0x95
	{ "SUB A, [HL]", 0, 8, SUB_A_mHL }, // 0x96
	{ "SUB A, A", 0, 4, SUB_A_A }, // 0x97
	{ "SBC A, B", 0, 4, SBC_A_B }, // 0x98
	{ "SBC A, C", 0, 4, SBC_A_C }, // 0x99
	{ "SBC A, D", 0, 4, SBC_A_D }, // 0x9a
	{ "SBC A, E", 0, 4, SBC_A_E }, // 0x9b
	{ "SBC A, H", 0, 4, SBC_A_H }, // 0x9c
	{ "SBC A, L", 0, 4, SBC_A_L }, // 0x9d
	{ "SBC A, [HL]", 0, 8, SBC_A_mHL }, // 0x9e
	{ "SBC A, A", 0, 4, SBC_A_A }, // 0x9f
	{ "AND A, B", 0, 4, AND_A_B }, // 0xa0
	{ "AND A, C", 0, 4, AND_A_C }, // 0xa1
	{ "AND A, D", 0, 4, AND_A_D }, // 0xa2
	{ "AND A, E", 0, 4, AND_A_E }, // 0xa3
	{ "AND A, H", 0, 4, AND_A_H }, // 0xa4
	{ "AND A, L", 0, 4, AND_A_L }, // 0xa5
	{ "AND A, [HL]", 0, 8, AND_A_mHL }, // 0xa6
	{ "AND A, A", 0, 4, AND_A_A }, // 0xa7
	{ "XOR A, B", 0, 4, XOR_A_B }, // 0xa8
	{ "XOR A, C", 0, 4, XOR_A_C }, // 0xa9
	{ "XOR A, D", 0, 4, XOR_A_D }, // 0xaa
	{ "XOR A, E", 0, 4, XOR_A_E }, // 0xab
	{ "XOR A, H", 0, 4, XOR_A_H }, // 0xac
	{ "XOR A, L", 0, 4, XOR_A_L }, // 0xad
	{ "XOR A, [HL]", 0, 8, XOR_A_mHL }, // 0xae
	{ "XOR A, A", 0, 4, XOR_A_A }, // 0xaf
	{ "OR A, B", 0, 4, OR_A_B }, // 0xb0
	{ "OR A, C", 0, 4, OR_A_C }, // 0xb1
	{ "OR A, D", 0, 4, OR_A_D }, // 0xb2
	{ "OR A, E", 0, 4, OR_A_E }, // 0xb3
	{ "OR A, H", 0, 4, OR_A_H }, // 0xb4
	{ "OR A, L", 0, 4, OR_A_L }, // 0xb5
	{ "OR A, [HL]", 0, 8, OR_A_mHL }, // 0xb6
	{ "OR A, A", 0, 4, OR_A_A }, // 0xb7
	{ "CP A, B", 0, 4, CMP_A_B }, // 0xb8
	{ "CP A, C", 0, 4, CMP_A_C }, // 0xb9
	{ "CP A, D", 0, 4, CMP_A_D },// 0xba
	{ "CP A, E", 0, 4, CMP_A_E }, // 0xbb
	{ "CP A, H", 0, 4, CMP_A_H }, // 0xbc
	{ "CP A, L", 0, 4, CMP_A_L }, // 0xbd
	{ "CP A, [HL]", 0, 8, CMP_A_mHL }, // 0xbe
	{ "CP A, A", 0, 4, CMP_A_A }, // 0xbf
	{ "RETNZ", 0, 20, RET_NZ }, // 0xc0
	{ "POP BC", 0, 12, POP_BC }, // 0xc1
	{ "JPNZ $%02x%02x", 2, 12, JP_NZ_NN }, // 0xc2
	{ "JP $%02x%02x", 2, 12, JP_NN }, // 0xc3
	{ "CALLNZ $%02x%02x", 2, 12, CALL_NZ }, // 0xc4
	{ "PUSH BC", 0, 16, PUSH_BC }, // 0xc5
	{ "ADD A, $%02x", 1, 8, ADD_A_N }, // 0xc6
	{ "RST 0x00", 0, 32, RST_00 }, // 0xc7
	{ "RETZ", 0, 20, RET_Z }, // 0xc8
	{ "RET", 0, 8, RET }, // 0xc9
	{ "JP Z $%02x%02x", 2, 12, JP_Z_NN }, // 0xca
	{ NULL, 0, 0, NULL }, // 0xcb
	{ "CALL Z $%02x%02x", 2, 12, CALL_Z }, // 0xcc
	{ "CALL $%02x%02x", 2, 24, CALL }, // 0xcd
	{ "ADC A, $%02x", 1, 8, ADC_A_N }, // 0xce
	{ "RST 0x08", 0, 32, RST_08 }, // 0xcf
	{ "RETNC", 0, 20, RET_NC }, // 0xd0
	{ "POP DE", 0, 12, POP_DE }, // 0xd1
	{ "JP NC $%02x%02x", 2, 12, JP_NC_NN }, // 0xd2
	{ NULL, 0, 0, NULL }, // 0xd3
	{ "CALL NC $%02x%02x", 2, 12, CALL_NC }, // 0xd4
	{ "PUSH DE", 0, 16, PUSH_DE }, // 0xd5
	{ "SUB A, $%02x", 1, 8, SUB_A_N }, // 0xd6
	{ "RST 0x10", 0, 32, RST_10 }, // 0xd7
	{ "RETC", 0, 20, RET_C }, // 0xd8
	{ "RETI", 0, 16, RETI }, // 0xd9
	{ "JPC $%02x%02x", 2, 12, JP_C_NN }, // 0xda
	{ NULL, 0, 0, NULL }, // 0xdb
	{ "CALL C $%02x%02x", 2, 12, CALL_C }, // 0xdc
	{ NULL, 0, 0, NULL }, // 0xdd
	{ NULL, 0, 0, NULL }, // 0xde
	{ "RST 0x18", 0, 32, RST_18 }, // 0xdf
	{ "LDH [%02x+0xFF00], A", 1, 12, LDH_SAVE_A_N }, // 0xe0
	{ "POP HL", 0, 12, POP_HL }, // 0xe1
	{ "LD [C+0xFF00], A", 0, 8, LD_SAVE_C_HIGH_A }, // 0xe2
	{ NULL, 0, 0, NULL }, // 0xe3
	{ NULL, 0, 0, NULL }, // 0xe4
	{ "PUSH HL", 0, 16, PUSH_HL }, // 0xe5
	{ "AND A, $%02x", 1, 8, AND_A_N }, // 0xe6
	{ "RST 0x20", 0, 32, RST_20 }, // 0xe7
	{ "ADD SP, $%02x", 1, 16, ADD_SP_N }, // 0xe8
	{ "JP HL", 0, 4, JP_HL }, // 0xe9
	{ "LD [$%02x%02x], A", 2, 16, LD_SAVE_A_NN }, // 0xea
	{ NULL, 0, 0, NULL }, // 0xeb
	{ NULL, 0, 0, NULL }, // 0xec
	{ NULL, 0, 0, NULL }, // 0xed
	{ "XOR A, $%02x", 1, 8, XOR_A_N }, // 0xee
	{ "RST 0x28", 0, 32, RST_28 }, // 0xef
	{ "LDH A, [%02x+0xFF00]", 1, 12, LDH_LOAD_A_N }, // 0xf0
	{ "POP AF", 0, 12, POP_AF }, // 0xf1
	{ "LD A, [C+0xFF00]", 0, 8, LD_LOAD_A_C_HIGH }, // 0xf2
	{ "DI", 0, 4, DI }, // 0xf3
	{ NULL, 0, 0, NULL }, // 0xf4
	{ "PUSH AF", 0, 16, PUSH_AF }, // 0xf5
	{ "OR A, $%02x", 1, 8, OR_A_N }, // 0xf6
	{ "RST 0x30", 0, 32, RST_30 }, // 0xf7
	{ "LDHL SP, $%02x", 1, 12, LDHL_SP_N }, // 0xf8
	{ "LD SP, HL", 0, 8, LD_SP_HL }, // 0xf9
	{ "LD A, [$%02x%02x]", 2, 16, LD_LOAD_A_NN }, // 0xfa
	{ "EI", 0, 4, EI }, // 0xfb
	{ NULL, 0, 0, NULL }, // 0xfc
	{ NULL, 0, 0, NULL }, // 0xfd
	{ "CP A, $%02x", 1, 8, CMP_A_N }, // 0xfe
	{ "RST 0x38", 0, 32, RST_38 },  // 0xff
};


// ############################################################
// ############################################################
// ############################################################
// ####################  CB INSTRUCTIONS   ####################
// ############################################################
// ############################################################
// ############################################################


// ############################################################
// ####################        BIT         ####################
// ############################################################

void BIT(gameboy_t* gameboy, uint8_t val, uint8_t pos) {
	gb_flag_set(gameboy, GB_FLAG_ZERO, (val & (0x01 << pos)) != 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, true);
}

void BIT_B_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 0); }
void BIT_C_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 0); }
void BIT_D_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 0); }
void BIT_E_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 0); }
void BIT_H_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 0); }
void BIT_L_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 0); }
void BIT_mHL_0(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 0); }
void BIT_A_0(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 0); }

void BIT_B_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 1); }
void BIT_C_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 1); }
void BIT_D_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 1); }
void BIT_E_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 1); }
void BIT_H_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 1); }
void BIT_L_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 1); }
void BIT_mHL_1(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 1); }
void BIT_A_1(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 1); }

void BIT_B_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 2); }
void BIT_C_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 2); }
void BIT_D_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 2); }
void BIT_E_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 2); }
void BIT_H_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 2); }
void BIT_L_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 2); }
void BIT_mHL_2(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 2); }
void BIT_A_2(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 2); }

void BIT_B_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 3); }
void BIT_C_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 3); }
void BIT_D_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 3); }
void BIT_E_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 3); }
void BIT_H_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 3); }
void BIT_L_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 3); }
void BIT_mHL_3(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 3); }
void BIT_A_3(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 3); }

void BIT_B_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 4); }
void BIT_C_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 4); }
void BIT_D_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 4); }
void BIT_E_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 4); }
void BIT_H_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 4); }
void BIT_L_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 4); }
void BIT_mHL_4(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 4); }
void BIT_A_4(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 4); }

void BIT_B_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 5); }
void BIT_C_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 5); }
void BIT_D_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 5); }
void BIT_E_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 5); }
void BIT_H_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 5); }
void BIT_L_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 5); }
void BIT_mHL_5(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 5); }
void BIT_A_5(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 5); }

void BIT_B_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 6); }
void BIT_C_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 6); }
void BIT_D_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 6); }
void BIT_E_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 6); }
void BIT_H_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 6); }
void BIT_L_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 6); }
void BIT_mHL_6(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 6); }
void BIT_A_6(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 6); }

void BIT_B_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.b, 7); }
void BIT_C_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.c, 7); }
void BIT_D_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.d, 7); }
void BIT_E_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.e, 7); }
void BIT_H_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.h, 7); }
void BIT_L_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.l, 7); }
void BIT_mHL_7(gameboy_t* gameboy) { BIT(gameboy, gb_mem_read(gameboy->memory, gameboy->cpu.hl), 7); }
void BIT_A_7(gameboy_t* gameboy) { BIT(gameboy, gameboy->cpu.a, 7); }


// ############################################################
// ####################        RES         ####################
// ############################################################

void RES(gameboy_t* gameboy, uint8_t* val, uint8_t pos) {
	*val = *val & ~(0x01 << pos);
}

void RES_B_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 0); }
void RES_C_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 0); }
void RES_D_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 0); }
void RES_E_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 0); }
void RES_H_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 0); }
void RES_L_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 0); }
void RES_mHL_0(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 0); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_0(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 0); }

void RES_B_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 1); }
void RES_C_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 1); }
void RES_D_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 1); }
void RES_E_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 1); }
void RES_H_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 1); }
void RES_L_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 1); }
void RES_mHL_1(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 1); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_1(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 1); }

void RES_B_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 2); }
void RES_C_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 2); }
void RES_D_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 2); }
void RES_E_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 2); }
void RES_H_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 2); }
void RES_L_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 2); }
void RES_mHL_2(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 2); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_2(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 2); }

void RES_B_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 3); }
void RES_C_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 3); }
void RES_D_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 3); }
void RES_E_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 3); }
void RES_H_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 3); }
void RES_L_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 3); }
void RES_mHL_3(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 3); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_3(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 3); }

void RES_B_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 4); }
void RES_C_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 4); }
void RES_D_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 4); }
void RES_E_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 4); }
void RES_H_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 4); }
void RES_L_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 4); }
void RES_mHL_4(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 4); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_4(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 4); }

void RES_B_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 5); }
void RES_C_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 5); }
void RES_D_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 5); }
void RES_E_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 5); }
void RES_H_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 5); }
void RES_L_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 5); }
void RES_mHL_5(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 5); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_5(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 5); }

void RES_B_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 6); }
void RES_C_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 6); }
void RES_D_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 6); }
void RES_E_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 6); }
void RES_H_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 6); }
void RES_L_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 6); }
void RES_mHL_6(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 6); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_6(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 6); }

void RES_B_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.b, 7); }
void RES_C_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.c, 7); }
void RES_D_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.d, 7); }
void RES_E_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.e, 7); }
void RES_H_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.h, 7); }
void RES_L_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.l, 7); }
void RES_mHL_7(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); RES(gameboy, &val, 7); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void RES_A_7(gameboy_t* gameboy) { RES(gameboy, &gameboy->cpu.a, 7); }


// ############################################################
// ####################        SET         ####################
// ############################################################

void SET(gameboy_t* gameboy, uint8_t* val, uint8_t pos) {
	*val = *val | (0x01 << pos);
}

void SET_B_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 0); }
void SET_C_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 0); }
void SET_D_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 0); }
void SET_E_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 0); }
void SET_H_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 0); }
void SET_L_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 0); }
void SET_mHL_0(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 0); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_0(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 0); }

void SET_B_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 1); }
void SET_C_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 1); }
void SET_D_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 1); }
void SET_E_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 1); }
void SET_H_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 1); }
void SET_L_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 1); }
void SET_mHL_1(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 1); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_1(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 1); }

void SET_B_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 2); }
void SET_C_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 2); }
void SET_D_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 2); }
void SET_E_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 2); }
void SET_H_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 2); }
void SET_L_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 2); }
void SET_mHL_2(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 2); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_2(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 2); }

void SET_B_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 3); }
void SET_C_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 3); }
void SET_D_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 3); }
void SET_E_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 3); }
void SET_H_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 3); }
void SET_L_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 3); }
void SET_mHL_3(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 3); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_3(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 3); }

void SET_B_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 4); }
void SET_C_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 4); }
void SET_D_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 4); }
void SET_E_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 4); }
void SET_H_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 4); }
void SET_L_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 4); }
void SET_mHL_4(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 4); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_4(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 4); }

void SET_B_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 5); }
void SET_C_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 5); }
void SET_D_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 5); }
void SET_E_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 5); }
void SET_H_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 5); }
void SET_L_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 5); }
void SET_mHL_5(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 5); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_5(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 5); }

void SET_B_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 6); }
void SET_C_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 6); }
void SET_D_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 6); }
void SET_E_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 6); }
void SET_H_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 6); }
void SET_L_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 6); }
void SET_mHL_6(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 6); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_6(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 6); }

void SET_B_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.b, 7); }
void SET_C_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.c, 7); }
void SET_D_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.d, 7); }
void SET_E_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.e, 7); }
void SET_H_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.h, 7); }
void SET_L_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.l, 7); }
void SET_mHL_7(gameboy_t* gameboy) { uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl); SET(gameboy, &val, 7); gb_mem_write(gameboy->memory, gameboy->cpu.hl, val); }
void SET_A_7(gameboy_t* gameboy) { SET(gameboy, &gameboy->cpu.a, 7); }






// ############################################################
// ####################       Rotates      ####################
// ############################################################

// Rotate left and save bit 7 in zero flag
void RLC_VAL(gameboy_t* gameboy, uint8_t* val) {
	bool bit7 = (*val & (0x01 << 7)) != 0;
	*val = *val << 1 | (bit7 ? 1 : 0);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit7);
}
void RLC_B(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.b); }
void RLC_C(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.c); }
void RLC_D(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.d); }
void RLC_E(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.e); }
void RLC_H(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.h); }
void RLC_L(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.l); }
void RLC_mHL(gameboy_t* gameboy) { 
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	RLC_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void RLC_A(gameboy_t* gameboy) { RLC_VAL(gameboy, &gameboy->cpu.a); }


// Rotate right and save bit 0 in zero flag
void RRC_VAL(gameboy_t* gameboy, uint8_t* val) {
	bool bit0 = (*val & 0x01) != 0;
	*val = *val >> 1 | (bit0 ? 128 : 0);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit0);
}
void RRC_B(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.b); }
void RRC_C(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.c); }
void RRC_D(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.d); }
void RRC_E(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.e); }
void RRC_H(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.h); }
void RRC_L(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.l); }
void RRC_mHL(gameboy_t* gameboy) { 
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	RRC_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void RRC_A(gameboy_t* gameboy) { RRC_VAL(gameboy, &gameboy->cpu.a); }


// Rotate left through carry
void RL_VAL(gameboy_t* gameboy, uint8_t* val) {
	bool bit7 = (*val & (0x01 << 7)) != 0;
	*val = *val << 1 | (gb_flag_get(*gameboy, GB_FLAG_CARRY) ? 1 : 0);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit7);
}
void RL_B(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.b); }
void RL_C(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.c); }
void RL_D(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.d); }
void RL_E(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.e); }
void RL_H(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.h); }
void RL_L(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.l); }
void RL_mHL(gameboy_t* gameboy) { 
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	RL_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void RL_A(gameboy_t* gameboy) { RL_VAL(gameboy, &gameboy->cpu.a); }

// Rotate right through carry
void RR_VAL(gameboy_t* gameboy, uint8_t* val) {
	bool bit0 = (*val & 0x01) != 0;
	*val = *val >> 1 | (gb_flag_get(*gameboy, GB_FLAG_CARRY) ? 128 : 0);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, bit0);
}
void RR_B(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.b); }
void RR_C(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.c); }
void RR_D(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.d); }
void RR_E(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.e); }
void RR_H(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.h); }
void RR_L(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.l); }
void RR_mHL(gameboy_t* gameboy) { 
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	RR_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void RR_A(gameboy_t* gameboy) { RR_VAL(gameboy, &gameboy->cpu.a); }





// ############################################################
// ####################       Shifts       ####################
// ############################################################


// Shift val left into carry flag, LSB set to 0
void SLA_VAL(gameboy_t* gameboy, uint8_t* val) {
	gb_flag_set(gameboy, GB_FLAG_CARRY, (*val & 128) != 0);
	
	*val = *val << 1;
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
}
void SLA_B(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.b); }
void SLA_C(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.c); }
void SLA_D(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.d); }
void SLA_E(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.e); }
void SLA_H(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.h); }
void SLA_L(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.l); }
void SLA_mHL(gameboy_t* gameboy) {
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	SLA_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void SLA_A(gameboy_t* gameboy) { SLA_VAL(gameboy, &gameboy->cpu.a); }

// Shift val right into carry flag, MSB stays the same (preserving sign)
void SRA_VAL(gameboy_t* gameboy, uint8_t* val) {
	uint8_t sign = (*val & 128);

	gb_flag_set(gameboy, GB_FLAG_CARRY, (*val & 1) != 0);
	
	*val = *val >> 1 | sign;
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
}
void SRA_B(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.b); }
void SRA_C(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.c); }
void SRA_D(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.d); }
void SRA_E(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.e); }
void SRA_H(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.h); }
void SRA_L(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.l); }
void SRA_mHL(gameboy_t* gameboy) {
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	SRA_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void SRA_A(gameboy_t* gameboy) { SRA_VAL(gameboy, &gameboy->cpu.a); }


// Shift val right into carry flag, MSB set to 0
void SRL_VAL(gameboy_t* gameboy, uint8_t* val) {
	gb_flag_set(gameboy, GB_FLAG_CARRY, (*val & 1) != 0);
	
	*val = *val >> 1;
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
}
void SRL_B(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.b); }
void SRL_C(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.c); }
void SRL_D(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.d); }
void SRL_E(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.e); }
void SRL_H(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.h); }
void SRL_L(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.l); }
void SRL_mHL(gameboy_t* gameboy) {
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	SRL_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void SRL_A(gameboy_t* gameboy) { SRL_VAL(gameboy, &gameboy->cpu.a); }


// ############################################################
// ####################       SWAP       ####################
// ############################################################

// Swaps upper and lower nibbles of val
void SWAP_VAL(gameboy_t* gameboy, uint8_t* val) {
	
	*val = (*val << 4) | (*val >> 4);
	
	gb_flag_set(gameboy, GB_FLAG_ZERO, *val == 0);
	gb_flag_set(gameboy, GB_FLAG_NEGATIVE, false);
	gb_flag_set(gameboy, GB_FLAG_HALF_CARRY, false);
	gb_flag_set(gameboy, GB_FLAG_CARRY, false);
}
void SWAP_B(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.b); }
void SWAP_C(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.c); }
void SWAP_D(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.d); }
void SWAP_E(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.e); }
void SWAP_H(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.h); }
void SWAP_L(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.l); }
void SWAP_mHL(gameboy_t* gameboy) {
	uint8_t val = gb_mem_read(gameboy->memory, gameboy->cpu.hl);
	SWAP_VAL(gameboy, &val);
	gb_mem_write(gameboy->memory, gameboy->cpu.hl, val);
}
void SWAP_A(gameboy_t* gameboy) { SWAP_VAL(gameboy, &gameboy->cpu.a); }


const instruction_t gb_cb_instructions[256] = {
	{ "RLC B", 0, 8, RLC_B }, // 0x00
	{ "RLC C", 0, 8, RLC_C }, // 0x01
	{ "RLC D", 0, 8, RLC_D }, // 0x02
	{ "RLC E", 0, 8, RLC_E }, // 0x03
	{ "RLC H", 0, 8, RLC_H }, // 0x04
	{ "RLC L", 0, 8, RLC_L }, // 0x05
	{ "RLC [HL]", 0, 16, RLC_mHL }, // 0x06
	{ "RLC A", 0, 8, RLC_A }, // 0x07
	
	{ "RRC B", 0, 8, RRC_B },// 0x08
	{ "RRC C", 0, 8, RRC_C },// 0x09
	{ "RRC D", 0, 8, RRC_D }, // 0x0a
	{ "RRC E", 0, 8, RRC_E }, // 0x0b
	{ "RRC H", 0, 8, RRC_H }, // 0x0c
	{ "RRC L", 0, 8, RRC_L }, // 0x0d
	{ "RRC [HL]", 0, 16, RRC_mHL }, // 0x0e
	{ "RRC A", 0, 8, RRC_A }, // 0x0f
	
	{ "RL B", 0, 8, RL_B }, // 0x10
	{ "RL C", 0, 8, RL_C }, // 0x11
	{ "RL D", 0, 8, RL_D }, // 0x12
	{ "RL E", 0, 8, RL_E }, // 0x13
	{ "RL H", 0, 8, RL_H }, // 0x14
	{ "RL L", 0, 8, RL_L }, // 0x15
	{ "RL [HL]", 0, 16, RL_mHL }, // 0x16
	{ "RL A", 0, 8, RL_A }, // 0x17
	
	{ "RR B", 0, 8, RR_B }, // 0x18
	{ "RR C", 0, 8, RR_C }, // 0x19
	{ "RR D", 0, 8, RR_D }, // 0x1a
	{ "RR E", 0, 8, RR_E }, // 0x1b
	{ "RR H", 0, 8, RR_H }, // 0x1c
	{ "RR L", 0, 8, RR_L }, // 0x1d
	{ "RR [HL]", 0, 16, RR_mHL },// 0x1e
	{ "RR A", 0, 8, RR_A }, // 0x1f
	
	{ "SLA B", 0, 8, SLA_B }, // 0x20
	{ "SLA C", 0, 8, SLA_C }, // 0x21
	{ "SLA D", 0, 8, SLA_D }, // 0x22
	{ "SLA E", 0, 8, SLA_E }, // 0x23
	{ "SLA H", 0, 8, SLA_H }, // 0x24
	{ "SLA L", 0, 8, SLA_L }, // 0x25
	{ "SLA [HL]", 0, 16, SLA_mHL }, // 0x26
	{ "SLA A", 0, 8, SLA_A }, // 0x27
	
	{ "SRA B", 0, 8, SRA_B }, // 0x28
	{ "SRA C", 0, 8, SRA_C }, // 0x29
	{ "SRA D", 0, 8, SRA_D }, // 0x2a
	{ "SRA E", 0, 8, SRA_E }, // 0x2b
	{ "SRA H", 0, 8, SRA_H }, // 0x2c
	{ "SRA L", 0, 8, SRA_L }, // 0x2d
	{ "SRA [HL]", 0, 16, SRA_mHL }, // 0x2e
	{ "SRA A", 0, 8, SRA_A }, // 0x2f
	
	{ "SWAP B", 0, 8, SWAP_B }, // 0x30
	{ "SWAP C", 0, 8, SWAP_C }, // 0x31
	{ "SWAP D", 0, 8, SWAP_D }, // 0x32
	{ "SWAP E", 0, 8, SWAP_E }, // 0x33
	{ "SWAP H", 0, 8, SWAP_H }, // 0x34
	{ "SWAP L", 0, 8, SWAP_L }, // 0x35
	{ "SWAP [HL]", 0, 16, SWAP_mHL }, // 0x36
	{ "SWAP A", 0, 8, SWAP_A }, // 0x37
	
	{ "SRA B", 0, 8, SRL_B }, // 0x38
	{ "SRA C", 0, 8, SRL_C }, // 0x39
	{ "SRA D", 0, 8, SRL_D }, // 0x3a
	{ "SRA E", 0, 8, SRL_E }, // 0x3b
	{ "SRA H", 0, 8, SRL_H }, // 0x3c
	{ "SRA L", 0, 8, SRL_L }, // 0x3d
	{ "SRA [HL]", 0, 16, SRL_mHL }, // 0x3e
	{ "SRA A", 0, 8, SRL_A }, // 0x3f
	
	 // 0x40
	{ "BIT 0, B", 0, 8, BIT_B_0 },
	{ "BIT 0, C", 0, 8, BIT_C_0 }, // 0x41
	{ "BIT 0, D", 0, 8, BIT_D_0 }, // 0x42
	{ "BIT 0, E", 0, 8, BIT_E_0 }, // 0x43
	{ "BIT 0, H", 0, 8, BIT_H_0 }, // 0x44
	{ "BIT 0, L", 0, 8, BIT_L_0 }, // 0x45
	{ "BIT 0, [HL]", 0, 16, BIT_mHL_0 }, // 0x46
	{ "BIT 0, A", 0, 8, BIT_A_0 }, // 0x47
	
	{ "BIT 1, B", 0, 8, BIT_B_1 }, // 0x48
	{ "BIT 1, C", 0, 8, BIT_C_1 }, // 0x49
	{ "BIT 1, D", 0, 8, BIT_D_1 }, // 0x4a
	{ "BIT 1, E", 0, 8, BIT_E_1 }, // 0x4b
	{ "BIT 1, H", 0, 8, BIT_H_1 }, // 0x4c
	{ "BIT 1, L", 0, 8, BIT_L_1 }, // 0x4d
	{ "BIT 1, [HL]", 0, 16, BIT_mHL_1 }, // 0x4e
	{ "BIT 1, A", 0, 8, BIT_A_1 }, // 0x4f
	
	{ "BIT 2, B", 0, 8, BIT_B_2 }, // 0x50
	{ "BIT 2, C", 0, 8, BIT_C_2 }, // 0x51
	{ "BIT 2, D", 0, 8, BIT_D_2 }, // 0x52
	{ "BIT 2, E", 0, 8, BIT_E_2 }, // 0x53
	{ "BIT 2, H", 0, 8, BIT_H_2 }, // 0x54
	{ "BIT 2, L", 0, 8, BIT_L_2 }, // 0x55
	{ "BIT 2, [HL]", 0, 16, BIT_mHL_2 }, // 0x56
	{ "BIT 2, A", 0, 8, BIT_A_2 }, // 0x57
	
	{ "BIT 3, B", 0, 8, BIT_B_3 }, // 0x58
	{ "BIT 3, C", 0, 8, BIT_C_3 }, // 0x59
	{ "BIT 3, D", 0, 8, BIT_D_3 }, // 0x5a
	{ "BIT 3, E", 0, 8, BIT_E_3 }, // 0x5b
	{ "BIT 3, H", 0, 8, BIT_H_3 }, // 0x5c
	{ "BIT 3, L", 0, 8, BIT_L_3 }, // 0x5d
	{ "BIT 3, [HL]", 0, 16, BIT_mHL_3 }, // 0x5e
	{ "BIT 3, A", 0, 8, BIT_A_3 }, // 0x5f
	
	{ "BIT 4, B", 0, 8, BIT_B_4 }, // 0x60
	{ "BIT 4, C", 0, 8, BIT_C_4 }, // 0x61
	{ "BIT 4, D", 0, 8, BIT_D_4 }, // 0x62
	{ "BIT 4, E", 0, 8, BIT_E_4 }, // 0x63
	{ "BIT 4, H", 0, 8, BIT_H_4 }, // 0x64
	{ "BIT 4, L", 0, 8, BIT_L_4 }, // 0x65
	{ "BIT 4, [HL]", 0, 8, BIT_mHL_4 }, // 0x66
	{ "BIT 4, A", 0, 8, BIT_A_4 }, // 0x67
	
	{ "BIT 5, B", 0, 8, BIT_B_5 }, // 0x68
	{ "BIT 5, C", 0, 8, BIT_C_5 }, // 0x69
	{ "BIT 5, D", 0, 8, BIT_D_5 }, // 0x6a
	{ "BIT 5, E", 0, 8, BIT_E_5 }, // 0x6b
	{ "BIT 5, H", 0, 8, BIT_H_5 }, // 0x6c
	{ "BIT 5, L", 0, 8, BIT_L_5 }, // 0x6d
	{ "BIT 5, [HL]", 0, 16, BIT_mHL_5 }, // 0x6e
	{ "BIT 5, A", 0, 8, BIT_A_5 }, // 0x6f
	
	{ "BIT 6, B", 0, 8, BIT_B_6 }, // 0x70
	{ "BIT 6, C", 0, 8, BIT_C_6 }, // 0x71
	{ "BIT 6, D", 0, 8, BIT_D_6 }, // 0x72
	{ "BIT 6, E", 0, 8, BIT_E_6 }, // 0x73
	{ "BIT 6, H", 0, 8, BIT_H_6 }, // 0x74
	{ "BIT 6, L", 0, 8, BIT_L_6 }, // 0x75
	{ "BIT 6, [HL]", 0, 16, BIT_mHL_6 }, // 0x76
	{ "BIT 6, A", 0, 8, BIT_A_6 }, // 0x77
	
	{ "BIT 7, B", 0, 8, BIT_B_7 }, // 0x78
	{ "BIT 7, C", 0, 8, BIT_C_7 }, // 0x79
	{ "BIT 7, D", 0, 8, BIT_D_7 }, // 0x7a
	{ "BIT 7, E", 0, 8, BIT_E_7 }, // 0x7b
	{ "BIT 7, H", 0, 8, BIT_H_7 }, // 0x7c
	{ "BIT 7, L", 0, 8, BIT_L_7 }, // 0x7d
	{ "BIT 7, [HL]", 0, 16, BIT_mHL_7 }, // 0x7e
	{ "BIT 7, A", 0, 8, BIT_A_7 }, // 0x7f

	// 0x80
	{ "RES 0, B", 0, 8, RES_B_0 },
	{ "RES 0, C", 0, 8, RES_C_0 },
	{ "RES 0, D", 0, 8, RES_D_0 },
	{ "RES 0, E", 0, 8, RES_E_0 },
	{ "RES 0, H", 0, 8, RES_H_0 },
	{ "RES 0, L", 0, 8, RES_L_0 },
	{ "RES 0, [HL]", 0, 16, RES_mHL_0 },
	{ "RES 0, A", 0, 8, RES_A_0 },

	{ "RES 1, B", 0, 8, RES_B_1 },
	{ "RES 1, C", 0, 8, RES_C_1 },
	{ "RES 1, D", 0, 8, RES_D_1 },
	{ "RES 1, E", 0, 8, RES_E_1 },
	{ "RES 1, H", 0, 8, RES_H_1 },
	{ "RES 1, L", 0, 8, RES_L_1 },
	{ "RES 1, [HL]", 0, 16, RES_mHL_1 },
	{ "RES 1, A", 0, 8, RES_A_1 },

	{ "RES 2, B", 0, 8, RES_B_2 },
	{ "RES 2, C", 0, 8, RES_C_2 },
	{ "RES 2, D", 0, 8, RES_D_2 },
	{ "RES 2, E", 0, 8, RES_E_2 },
	{ "RES 2, H", 0, 8, RES_H_2 },
	{ "RES 2, L", 0, 8, RES_L_2 },
	{ "RES 2, [HL]", 0, 16, RES_mHL_2 },
	{ "RES 2, A", 0, 8, RES_A_2 },

	{ "RES 3, B", 0, 8, RES_B_3 },
	{ "RES 3, C", 0, 8, RES_C_3 },
	{ "RES 3, D", 0, 8, RES_D_3 },
	{ "RES 3, E", 0, 8, RES_E_3 },
	{ "RES 3, H", 0, 8, RES_H_3 },
	{ "RES 3, L", 0, 8, RES_L_3 },
	{ "RES 3, [HL]", 0, 16, RES_mHL_3 },
	{ "RES 3, A", 0, 8, RES_A_3 },

	{ "RES 4, B", 0, 8, RES_B_4 },
	{ "RES 4, C", 0, 8, RES_C_4 },
	{ "RES 4, D", 0, 8, RES_D_4 },
	{ "RES 4, E", 0, 8, RES_E_4 },
	{ "RES 4, H", 0, 8, RES_H_4 },
	{ "RES 4, L", 0, 8, RES_L_4 },
	{ "RES 4, [HL]", 0, 16, RES_mHL_4 },
	{ "RES 4, A", 0, 8, RES_A_4 },

	{ "RES 5, B", 0, 8, RES_B_5 },
	{ "RES 5, C", 0, 8, RES_C_5 },
	{ "RES 5, D", 0, 8, RES_D_5 },
	{ "RES 5, E", 0, 8, RES_E_5 },
	{ "RES 5, H", 0, 8, RES_H_5 },
	{ "RES 5, L", 0, 8, RES_L_5 },
	{ "RES 5, [HL]", 0, 16, RES_mHL_5 },
	{ "RES 5, A", 0, 8, RES_A_5 },

	{ "RES 6, B", 0, 8, RES_B_6 },
	{ "RES 6, C", 0, 8, RES_C_6 },
	{ "RES 6, D", 0, 8, RES_D_6 },
	{ "RES 6, E", 0, 8, RES_E_6 },
	{ "RES 6, H", 0, 8, RES_H_6 },
	{ "RES 6, L", 0, 8, RES_L_6 },
	{ "RES 6, [HL]", 0, 16, RES_mHL_6 },
	{ "RES 6, A", 0, 8, RES_A_6 },

	{ "RES 7, B", 0, 8, RES_B_7 },
	{ "RES 7, C", 0, 8, RES_C_7 },
	{ "RES 7, D", 0, 8, RES_D_7 },
	{ "RES 7, E", 0, 8, RES_E_7 },
	{ "RES 7, H", 0, 8, RES_H_7 },
	{ "RES 7, L", 0, 8, RES_L_7 },
	{ "RES 7, [HL]", 0, 16, RES_mHL_7 },
	{ "RES 7, A", 0, 8, RES_A_7 },

	// 0xc0
	{ "SET 0, B", 0, 8, SET_B_0 },
	{ "SET 0, C", 0, 8, SET_C_0 },
	{ "SET 0, D", 0, 8, SET_D_0 },
	{ "SET 0, E", 0, 8, SET_E_0 },
	{ "SET 0, H", 0, 8, SET_H_0 },
	{ "SET 0, L", 0, 8, SET_L_0 },
	{ "SET 0, [HL]", 0, 16, SET_mHL_0 },
	{ "SET 0, A", 0, 8, SET_A_0 },

	{ "SET 1, B", 0, 8, SET_B_1 },
	{ "SET 1, C", 0, 8, SET_C_1 },
	{ "SET 1, D", 0, 8, SET_D_1 },
	{ "SET 1, E", 0, 8, SET_E_1 },
	{ "SET 1, H", 0, 8, SET_H_1 },
	{ "SET 1, L", 0, 8, SET_L_1 },
	{ "SET 1, [HL]", 0, 16, SET_mHL_1 },
	{ "SET 1, A", 0, 8, SET_A_1 },

	{ "SET 2, B", 0, 8, SET_B_2 },
	{ "SET 2, C", 0, 8, SET_C_2 },
	{ "SET 2, D", 0, 8, SET_D_2 },
	{ "SET 2, E", 0, 8, SET_E_2 },
	{ "SET 2, H", 0, 8, SET_H_2 },
	{ "SET 2, L", 0, 8, SET_L_2 },
	{ "SET 2, [HL]", 0, 16, SET_mHL_2 },
	{ "SET 2, A", 0, 8, SET_A_2 },

	{ "SET 3, B", 0, 8, SET_B_3 },
	{ "SET 3, C", 0, 8, SET_C_3 },
	{ "SET 3, D", 0, 8, SET_D_3 },
	{ "SET 3, E", 0, 8, SET_E_3 },
	{ "SET 3, H", 0, 8, SET_H_3 },
	{ "SET 3, L", 0, 8, SET_L_3 },
	{ "SET 3, [HL]", 0, 16, SET_mHL_3 },
	{ "SET 3, A", 0, 8, SET_A_3 },

	{ "SET 4, B", 0, 8, SET_B_4 },
	{ "SET 4, C", 0, 8, SET_C_4 },
	{ "SET 4, D", 0, 8, SET_D_4 },
	{ "SET 4, E", 0, 8, SET_E_4 },
	{ "SET 4, H", 0, 8, SET_H_4 },
	{ "SET 4, L", 0, 8, SET_L_4 },
	{ "SET 4, [HL]", 0, 16, SET_mHL_4 },
	{ "SET 4, A", 0, 8, SET_A_4 },

	{ "SET 5, B", 0, 8, SET_B_5 },
	{ "SET 5, C", 0, 8, SET_C_5 },
	{ "SET 5, D", 0, 8, SET_D_5 },
	{ "SET 5, E", 0, 8, SET_E_5 },
	{ "SET 5, H", 0, 8, SET_H_5 },
	{ "SET 5, L", 0, 8, SET_L_5 },
	{ "SET 5, [HL]", 0, 16, SET_mHL_5 },
	{ "SET 5, A", 0, 8, SET_A_5 },

	{ "SET 6, B", 0, 8, SET_B_6 },
	{ "SET 6, C", 0, 8, SET_C_6 },
	{ "SET 6, D", 0, 8, SET_D_6 },
	{ "SET 6, E", 0, 8, SET_E_6 },
	{ "SET 6, H", 0, 8, SET_H_6 },
	{ "SET 6, L", 0, 8, SET_L_6 },
	{ "SET 6, [HL]", 0, 16, SET_mHL_6 },
	{ "SET 6, A", 0, 8, SET_A_6 },

	{ "SET 7, B", 0, 8, SET_B_7 },
	{ "SET 7, C", 0, 8, SET_C_7 },
	{ "SET 7, D", 0, 8, SET_D_7 },
	{ "SET 7, E", 0, 8, SET_E_7 },
	{ "SET 7, H", 0, 8, SET_H_7 },
	{ "SET 7, L", 0, 8, SET_L_7 },
	{ "SET 7, [HL]", 0, 16, SET_mHL_7 },
	{ "SET 7, A", 0, 8, SET_A_7 }
};
