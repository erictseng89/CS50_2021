#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// uint8_t is actually a integer data type for unsigned integer with 8 bits. We use this as we can specify that we only want 8bits. Need stdint.h library to access this variable.
// typedef simply allows the programmer to add an alias to a variable. 
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	// Ensure proper usage
	if (argc != 3)
	{
		printf("Usage: ./cpy SOURCE DESTINATION");
		return 1;
	}

	// Open input file
	// This line of code attempts to open "argv[i]" in read mode. fopen returns a memory address positioned at the beginning of the file.
	FILE *source = fopen(argv[1], "r");
	if (source == NULL)
	{
		printf("Could not open %s.\n", argv[1]);
		return 1;
	}

	// Creates output file
	FILE *destination = fopen(argv[2], "w");
	if (destination == NULL)
	{
		printf("Could not create %s.\n", argv[2]);
		return 1;
	}

	// Create a BYTE variable(which is just an unsigned integer with 8bits) called buffer.
	// fread will copy the contents of "source" of size "sizeof(BYTE)" times 1 into the pointer location of buffer.
	// fread will return a value of depending on how much it has read. fread will return 0 if it encounters an error or it reaches end of file.
	// So we use a while loop using fread as a boolean function, as long as it doesn't return false(which is 0). then continue to loop.
	BYTE buffer;
	while (fread(&buffer, sizeof(BYTE), 1, source))
	{
		// fwrite will dereference and copy whatever is at &buffer of sizeof(BYTE) times 1, into destination.
		fwrite(&buffer, sizeof(BYTE), 1, destination);
	}
	// Close files
	fclose(source);
	fclose(destination);
	return 0;
}