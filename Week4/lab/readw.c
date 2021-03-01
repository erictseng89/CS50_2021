#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define H_SIZE 4
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
	// Ensure correct usage
	if (argc != 2)
	{
		printf("Usage: ./readw WAVE_FILE");
		return 1;
	}

	// Open wave file. Check if file opens properly.
	FILE *source = fopen(argv[1], "r");
	if (source == NULL)
	{
		printf("Could not open %s.\n", argv[1]);
		return 1;
	}

	// Create a string to record header.
	char *header = malloc(H_SIZE + 1);
	if (header == NULL)
	{
		printf("Could not assign memory to header.\n");
		return 1;
	}
	header[H_SIZE] = '\0';// BYTE *buffer;


	for (int i = 0; i < H_SIZE; i++)
	{
		fread(&header[i], sizeof(BYTE), 1, source);
	}
	printf("Header is: %s\n", header);

	fclose(source);
	free(header);
}