#include <stdio.h>
#include <stdlib.h>

// Below is the before, indicate memory problems.
// int main(void)
// {
// 	char *s = malloc(3);
// 	s[0] = 'H';
// 	s[1] = 'I';
// 	s[2] = '!';
// 	s[3] = '\0'; // According to valgrind, this is an invalid write.
	

// 	printf("%s\n", s);	// valgrind: this is an invalid read.

// 	// valgrind indicates :
// 	// HEAP SUMMARY: 3 bytes in 1 block in use at exit
// 	// LEAK SUMMARY: definitely lost: 3 bytes in 1 block
// }

// After addressing memory allocation mistakes.
int main(void)
{
	char *s = malloc(4);
	s[0] = 'H';
	s[1] = 'I';
	s[2] = '!';
	s[3] = '\0';
	

	printf("%s\n", s);	
	free(s);
}