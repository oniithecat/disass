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
		{"add ", 0x01, 8, true},
		{"add ", 0x02, 8, true},
		{"add ", 0x03, 8, true},
		{"add ", 0x04, 8, false},
		{"add ", 0x05, 8, false},
		{"push es ", 0x06, 8, false},
		{"or ", 0x07, 8, false},
		{"or ", 0x08, 8, true},
		{"or ", 0x09, 8, true},
		{"or ", 0x0a, 8, true},
		{"or ", 0x0b, 8, true},
		{"or ", 0x0c, 8, false},
		{"or ", 0x0d, 8, false},
		{"push cs ", 0x0e, 8, false},
		{" ", 0x0f, 8, false}, // tqt mon reuf (two bytes insructions)
		{"adc ", 0x10, 8, true},
		{"adc ", 0x11, 8, true},
		{"adc ", 0x12, 8, true},
		{"adc ", 0x13, 8, true},
		{"adc ", 0x14, 8, false},
		{"adc ", 0x15, 8, false},
		{"push ss ", 0x16, 8, false},
		{"pop ss ", 0x17, 8, false},
		{"sbb ", 0x18, 8, true},
		{"sbb ", 0x19, 8, true},
		{"sbb ", 0x1a, 8, true},
		{"sbb ", 0x1b, 8, true},
		{"sbb ", 0x1c, 8, false},
		{"sbb ", 0x1d, 8, false},
		{"push ds ", 0x1e, 8, false},
		{"pop ds ", 0x1f, 8, false},
		{"and ", 0x20, 8, true
		{"and ", 0x21, 8, false},
		{"and ", 0x23, 8, false},
		{"and ", 0x24, 8, false},
		{"and ", 0x25, 8, false},
		{"es ", 0x26, 8, false},
		{"daa ", 0x27, 8, false},
		{"sub ", 0x28, 8, true},
		{"sub ", 0x29, 8, true},
		{"sub ", 0x2a, 8, true},
		{"sub ", 0x2b, 8, true},
		{"sub ", 0x2c, 8, false},
		{"sub ", 0x2d, 8, false},
		{"cs ", 0x2e, 8, false},
		{"das ", 0x2f, 8, false},
		{"xor ", 0x30, 8, true},
		{"xor ", 0x31, 8, true},
		{"xor ", 0x32, 8, true},
		{"xor ", 0x33, 8, true},
		{"xor ", 0x34, 8, false},
		{"xor ", 0x35, 8, false},
		{"ss ", 0x36, 8, false},
		{"aaa ", 0x37, 8, false},
		{"cmp ", 0x38, 8, true},
		{"cmp ", 0x39, 8, true},
		{"cmp ", 0x3a, 8, true},
		{"cmp ", 0x3b, 8, true},
		{"cmp ", 0x3c, 8, false},
		{"cmp ", 0x3d, 8, false},
		{"ds ", 0x3e, 8, false},
		{"aas ", 0x3f, 8, false},
		{"inc ", 0x40, 8, false},
		{"inc ", 0x41, 8, false},
		{"inc ", 0x42, 8, false},
		{"inc ", 0x43, 8, false},
		{"inc ", 0x44, 8, false},
		{"inc ", 0x45, 8, false},
		{"inc ", 0x46, 8, false},
		{"inc ", 0x47, 8, false},
		{"dec ", 0x48, 8, false},
		{"dec ", 0x49, 8, false},
		{"dec ", 0x4a, 8, false},
		{"dec ", 0x4b, 8, false},
		{"dec ", 0x4c, 8, false},


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