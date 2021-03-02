#include <stdio.h>

/*
This is just a trivial program to print out the arguments that the user typed in.
argv is an array of pointers to characters.

 */


int main(int argc, char *argv[])
{
	while (*argv)
		printf("%s\n", *argv++);

		return 0;
}