#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void disass()
{
	// one byte opcode
	unsigned char opcodes = {}; 

}


int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage : didi <option(s)> <file>\n");
		return -1;
	}
	
	FILE* file = fopen(argv[2], "rb");
	if (file == NULL) {
		printf("[-] Unable to open the file\n");
		return -1;
	}

	fseek(file, 0, SEEK_END);
	long length_file = ftell(file);
	fseek(file, 0, SEEK_SET);

	unsigned char *buffer = malloc(length_file);

	fread(buffer, length_file, 1, file);

	for (int i = 0; i < length_file; i++) {
        printf("%02x ", buffer[i]);
    }

    printf("\n");

    fclose(file);
    free(buffer);


	return 0;
}


void help()
{
	printf(
		"Usage : didi <option(s)> <file>\n"
		"  -h : to show this message\n"
		"  -f : file to disassemble\n" 

		);
}