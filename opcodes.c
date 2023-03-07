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
		{"add ", 0x00, 8, true}
		{"add ", 0x01, 8, true}
		{"add ", 0x02, 8, true}
		{"add ", 0x03, 8, true}
		{"add ", 0x04, 8, false}
		{"add ", 0x05, 8, true}
		{"push es ", 0x06, 8, true}
		{"pop es ", 0x07, 8, true}

	};


	return 0;
}
