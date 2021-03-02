#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// can open files by READ, WRITE, or APPEND.
	// Use "a" to append.
	FILE *file = fopen("phonebook.csv", "a");
	// .csv is a comma seperated value file
	if (file == NULL)
	{
		// If there is an error when opening the file.
		return 1;
	}

	char *name = get_string("Name: ");
	char *number = get_string("Number: ");
	
	fprintf(file, "%s, %s\n", name, number);
	
	fclose(file);

}