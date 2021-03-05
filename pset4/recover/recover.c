#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 

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

	FILE *outptr = NULL;

	// Create buffer for reading and writing.
	uint8_t buffer[512];

	
	/* 
	Use sprintf to do naming problem. sprintf prints to a string.
	walkthrough 7:15
	 */


	int filecount = 0;


	int outfile = 0;


		
	// While fread doesn't return error or eof.
	while (fread(buffer, sizeof(uint8_t), 512, inptr))
	{
		//Check if current block has as jpeg starting header.
		if(checkjpeg(buffer))
		{
			
			
			outptr = fopen(outfile'.jpg', "w");




		}
	}


bool checkjpeg(uint8_t *a)
{
	// Use bitwise arithmatic. Walkthrough 5:40
	return false;
}
	










}