#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

	// implement opcodes table

	typedef struct {
		char *mnemonic;
		uint8_t size;
		unsigned char opcode;
		bool RmMod; 
	} Opcode;

	typedef struct {
		int Scale;
		int Index;
		int Base;
	} SIB;


	Opcode opcodes_table[] = {
		{"add ", 0x00, 8, true},
		{"add ", 0x01, 32, true},
		{"add ", 0x02, 8, true},
		{"add ", 0x03, 32, true},
		{"add ", 0x04, 8, false},
		{"add ", 0x05, 32, false},
		{"push es ", 0x06, 8, false},
		{"or ", 0x07, 32, false},
		{"or ", 0x08, 8, true},
		{"or ", 0x09, 32, true},
		{"or ", 0x0a, 8, true},
		{"or ", 0x0b, 32, true},
		{"or ", 0x0c, 8, false},
		{"or ", 0x0d, 32, false},
		{"push cs ", 0x0e, 8, false},
		{" ", 0x0f, 32, false}, // tqt mon reuf (two bytes insructions)
		{"adc ", 0x10, 8, true},
		{"adc ", 0x11, 32, true},
		{"adc ", 0x12, 8, true},
		{"adc ", 0x13, 32, true},
		{"adc ", 0x14, 8, false},
		{"adc ", 0x15, 32, false},
		{"push ss ", 0x16, 8, false},
		{"pop ss ", 0x17, 32, false},
		{"sbb ", 0x18, 8, true},
		{"sbb ", 0x19, 32, true},
		{"sbb ", 0x1a, 8, true},
		{"sbb ", 0x1b, 32, true},
		{"sbb ", 0x1c, 8, false},
		{"sbb ", 0x1d, 32, false},
		{"push ds ", 0x1e, 8, false},
		{"pop ds ", 0x1f, 32, false},
		{"and ", 0x20, 8, true},
		{"and ", 0x21, 32, false},
		{"and ", 0x22, 8, false},
		{"and ", 0x23, 32, false},
		{"and ", 0x24, 8, false},
		{"and ", 0x25, 32, false},
		{"es ", 0x26, 8, false},
		{"daa ", 0x27, 32, false},
		{"sub ", 0x28, 8, true},
		{"sub ", 0x29, 32, true},
		{"sub ", 0x2a, 8, true},
		{"sub ", 0x2b, 32, true},
		{"sub ", 0x2c, 8, false},
		{"sub ", 0x2d, 32, false},
		{"cs ", 0x2e, 8, false},
		{"das ", 0x2f, 32, false},
		{"xor ", 0x30, 8, true},
		{"xor ", 0x31, 32, true},
		{"xor ", 0x32, 8, true},
		{"xor ", 0x33, 32, true},
		{"xor ", 0x34, 8, false},
		{"xor ", 0x35, 32, false},
		{"ss ", 0x36, 8, false},
		{"aaa ", 0x37, 32, false},
		{"cmp ", 0x38, 8, true},
		{"cmp ", 0x39, 32, true},
		{"cmp ", 0x3a, 8, true},
		{"cmp ", 0x3b, 32, true},
		{"cmp ", 0x3c, 8, false},
		{"cmp ", 0x3d, 32, false},
		{"ds ", 0x3e, 8, false},
		{"aas ", 0x3f, 32, false},
		{"inc ", 0x40, 8, false},
		{"inc ", 0x41, 32, false},
		{"inc ", 0x42, 8, false},
		{"inc ", 0x43, 32, false},
		{"inc ", 0x44, 8, false},
		{"inc ", 0x45, 32, false},
		{"inc ", 0x46, 8, false},
		{"inc ", 0x47, 32, false},
		{"dec ", 0x48, 8, false},
		{"dec ", 0x49, 32, false},
		{"dec ", 0x4a, 8, false},
		{"dec ", 0x4b, 32, false},
		{"dec ", 0x4c, 8, false},
		{"dec ", 0x4d, 32, false},
		{"dec ", 0x4e, 8, false},
		{"dec ", 0x4f, 32, false},
		{"push ", 0x50, 8, false},
		{"push ", 0x51, 32, false},
		{"push ", 0x52, 8, false},
		{"push ", 0x53, 32, false},
		{"push ", 0x54, 8, false},
		{"push ", 0x55, 32, false},
		{"push ", 0x56, 8, false},
		{"push ", 0x57, 32, false},
		{"pop ", 0x58, 8, false},
		{"pop ", 0x59, 32, false},
		{"pop ", 0x5a, 8, false},
		{"pop ", 0x5b, 32, false},
		{"pop ", 0x5c, 8, false},
		{"pop ", 0x5d, 32, false},
		{"pop ", 0x5e, 8, false},
		{"pop ", 0x5f, 32, false},
		{"pusha ", 0x60, 8, false},
		{"popa ", 0x61, 32, false},
		{" ", 0x62, 8, false}, // jsp c quoi "bound"
		{"arpl ", 0x63, 32, true},
		{"fs ", 0x64, 8, false},
		{"gs ", 0x65, 32, false},
		{"opsize ", 0x66, 8, false},
		{"adsize ", 0x67, 32, false},
		{"push ", 0x68, 8, false},
		{"imul ", 0x69, 32, true},
		{"push ", 0x6a, 8, false},
		{"imul ", 0x6b, 32, true},
		{"insb ", 0x6c, 8, false},
		{"insw ", 0x6d, 32, false},
		{"outsb ", 0x6e, 8, false},
		{"outsw ", 0x6f, 32, false},
		{"jo ", 0x70, 8, false},
		{"jno ", 0x71, 32, false},
		{"jb ", 0x72, 8, false},
		{"jnb ", 0x73, 32, false},
		{"jz ", 0x74, 8, false},
		{"jnz ", 0x75, 32, false},
		{"jbe ", 0x76, 8, false},
		{"ja ", 0x77, 32, false},
		{"js ", 0x78, 8, false},
		{"jns ", 0x79, 32, false},
		{"jp ", 0x7a, 8, false},
		{"jnp ", 0x7b, 32, false},
		{"jl ", 0x7c, 8, false},
		{"jnl ", 0x7d, 32, false},
		{"jle ", 0x7e, 8, false},
		{"jnle ", 0x7f, 32, false},
		{"add ", 0x80, 8, true},
		{"add ", 0x81, 32, true},
		{"sub ", 0x82, 8, true},
		{"sub ", 0x83, 32, true},
		{"test ", 0x84, 8, true},
		{"test ", 0x85, 32, true},
		{"xchg ", 0x86, 8, true},
		{"xchg ", 0x87, 32, true},
		{"mov ", 0x88, 8, true},
		{"mov ", 0x89, 32, true},
		{"mov ", 0x8a, 8, true},
		{"mov ", 0x8b, 32, true},
		{"mov ", 0x8c, 8, true},
		{"lea ", 0x8d, 32, false},
		{"mov ", 0x8e, 8, true},
		{"pop ", 0x8f, 32, true},
		{"nop ", 0x90, 8, false},
		{"xchg ", 0x91, 32, false},
		{"xchg ", 0x92, 8, false},
		{"xchg ", 0x93, 32, false},
		{"xchg ", 0x94, 8, false},
		{"xchg ", 0x95, 32, false},
		{"xchg ", 0x96, 8, false},
		{"xchg ", 0x97, 32, false},
		{"cbw ", 0x98, 8, false},
		{"cwd ", 0x99, 32, false},
		{"call ", 0x9a, 8, false},
		{"wait ", 0x9b, 32, false},
		{"pushf ", 0x9c, 8, false},
		{"popf ", 0x9d, 32, false},
		{"sahf ", 0x9e, 8, false},
		{"lahf ", 0x9f, 32, false},
		{"mov ", 0xa0, 8, false},
		{"mov ", 0xa1, 32, false},
		{"mov ", 0xa2, 8, false},
		{"mov ", 0xa3, 32, false},
		{"movsb ", 0xa4, 8, false},
		{"movsw ", 0xa5, 32, false},
		{"cmpsb ", 0xa6, 8, false},
		{"cmpsw ", 0xa7, 32, false},
		{"test ", 0xa8, 8, false},
		{"test ", 0xa9, 32, false},
		{"stopsb ", 0xaa, 8, false},
		{"stopsw ", 0xab, 32, false},
		{"lodsb ", 0xac, 8, false},
		{"lodsw ", 0xad, 32, false},
		{"scasb ", 0xae, 8, false},
		{"scasw ", 0xaf, 32, false},
		{"mov ", 0xb0, 8, false},
		{"mov ", 0xb1, 32, false},
		{"mov ", 0xb2, 8, false},
		{"mov ", 0xb3, 32, false},
		{"mov ", 0xb4, 8, false},
		{"mov ", 0xb5, 32, false},
		{"mov ", 0xb6, 8, false},
		{"mov ", 0xb7, 32, false},
		{"mov ", 0xb8, 8, false},
		{"mov ", 0xb9, 32, false},
		{"mov ", 0xba, 8, false},
		{"mov ", 0xbb, 32, false},
		{"mov ", 0xbc, 8, false},
		{"mov ", 0xbd, 32, false},
		{"mov ", 0xbe, 8, false},
		{"mov ", 0xbf, 32, false},
		{" ", 0xc0, 8, true}, //
		{" ", 0xc1, 32, true}, // c quoi ces trucs encore (#2)
		{"retn ", 0xc2, 8, false},
		{"retn ", 0xc3, 32, false},
		{"les ", 0xc4, 8, false}, // c inutile jcrois hein
		{"lds ", 0xc5, 32, false}, // ça aussi
		{"mov ", 0xc6, 8, true},
		{"mov ", 0xc7, 32, true},
		{"enter ", 0xc8, 8, false}, // wtf
		{"leave ", 0xc9, 32, false},
		{"retf ", 0xca, 8, false},
		{"retf ", 0xcb, 32, false},
		{"int3 ", 0xcc, 8, false},
		{"int ", 0xcd, 32, false},
		{"into ", 0xce, 8, false},
		{"iret ", 0xcf, 32, false},
		{" ", 0xd0, 8, false}, // ding dong
		{" ", 0xd1, 32, false}, //
		{" ", 0xd2, 8, false}, //
		{" ", 0xd3, 32, false}, //
		{"aam ", 0xd4, 8, false},
		{"aad ", 0xd5, 32, false},
		{" ", 0xd6, , false}, // bing chilling
		{"xlat ", 0xd7, 32, false},
		{" ", 0xd8, 8, false}, //
		{" ", 0xd9, 32, false}, //
		{" ", 0xda, 8, false}, //
		{" ", 0xdb, 32, false}, //
		{" ", 0xdc, 8, false}, //
		{" ", 0xdd, 32, false}, //
		{" ", 0xde, 8, false}, //
		{" ", 0xdf, 32, false}, //
		{"loopnz ", 0xe0, 8, false},
		{"loopz ", 0xe1, 32, false},
		{"loop ", 0xe2, 8, false},
		{"jcxz ", 0xe3, 32, false},
		{"in ", 0xe4, 8, false},
		{"in ", 0xe5, 32, false},
		{"out ", 0xe6, 8, false},
		{"out ", 0xe7, 32, false},
		{"call ", 0xe8, 8, false},
		{"jmp ", 0xe9, 32, false},
		{"jmp ", 0xea, 8, false},
		{"jmp ", 0xeb, 32, false},
		{"in ", 0xec, 8, false},
		{"in ", 0xed, 32, false},
		{"out ", 0xee, 8, false},
		{"out ", 0xef, 32, false},
		{"lock: ", 0xf0, 8, false},
		{"int1 ", 0xf1, 32, false}, // ça doit être ça
		{"repne: ", 0xf2, 8, false},
		{"rep: ", 0xf3, 32, false},
		{"hlt ", 0xf4, 8, false},
		{"cmc ", 0xf5, 32, false},
		{" ", 0xf6, 8, false}, // bing chilling
		{" ", 0xf7, 32, false}, // 
		{"clc ", 0xf8, 8, false},
		{"stc ", 0xf9, 32, false},
		{"cli ", 0xfa, 8, false},
		{"sti ", 0xfb, 32, false},
		{"cld ", 0xfc, 8, false},
		{"std ", 0xfd, 32, false},
		{" ", 0xfe, 8, false}, // kirikou
		{" ", 0xff, 32, false},
	};






	return 0;
}



/*

01 f8

Opcode : 0x01
Mnemonic : add
Bin : 0000 0001
x bit -> 0 R/M <- Reg
s bit -> 1 -> 32 bits

Mod R/M : 0xf8
Bin : 1111 1000
Mod : 11
Reg : 111
R/M : 000

ADD eax, edi


*/