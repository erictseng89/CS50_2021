#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BLOCK_SIZE 512

//This file will read a raw file that contained jpegs that were deleted. It will read one BLOCK_SIZE at a time. The first 3 bytes of a JPEGs are 0xff 0xd8 0xff. The 4th byte will either 0xe1 ~ 0xef. In other words, the first 4 bits are 1110. 
/*
Open raw file
Open output file
Read raw file
	Confirm header is correct
		Start copying files block by block

*/

// Prototypes
bool checkjpeg(uint8_t *a);

int main(int argc, char *argv[])
{
	// If input is invalid, remind correct usage
	if (argc != 2)
	{
		printf("Usage: ./recover 'file name'\n");
		return 1;
	}

	// If file cannot be read, remind user
	FILE *inptr =fopen(argv[1], "r");
	if (inptr == NULL)
	{
		printf("Cannot open %s\n", argv[1]);
		return 1;
	}

	// Define output file pointer
	FILE *outptr = NULL;

	// Create buffer for reading and writing.
	uint8_t buffer[512];
	
	/* 
	Use sprintf to do naming problem. sprintf prints to a string.
	int sprintf(char *str, const char *format, ...);

	sprintf is a function that prints to string using arguments similar to the print function.
	 */

	char *filename[8];
	int filecount = 0;
	
	sprintf(&filename, "%03d.jpg", filecount);
		
	// While fread doesn't return error or eof.
	while (fread(buffer, sizeof(uint8_t), 512, inptr))
	{
		//Check if current block has as jpeg starting header.
		if(checkjpeg(buffer))
		{
			// Check if outptr has anything currently open
			if (outptr != NULL)
			{
				fclose(outptr);
				filecount++;
			}
			FILE *temp = fopen(filename, "w");
			*outptr = *temp;
			fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, outptr);
		}
		else
		{
			fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, outptr);
		}
	}
	fclose(inptr);
	fclose(outptr);
}


bool checkjpeg(uint8_t *a)
{
	/*
	 Use bitwise arithmatic for 4th byte. Walkthrough 5:40
	The bitwise & operator in this function (a[3] & 0xf0), means to look at and ignore 0xf bits, which is 4 bits (since f = 1111), and change the rest of the bit to 0. Then I will then use this to check for the 4th byte of a jpeg file. */
	if(a[0] == 0xff && a[1] == 0xd8 && a[2] == 0xff && (a[3] & 0xf0) == 0xe0)
	{
		return true;
	}
	return false;
}
