#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *s = get_string("s: ");
	printf("s: %s\n", s);

	char *t = malloc(strlen(s) + 1);
	if (t == NULL)
	{
		return 1;
	}
	strcpy(t, s);

	printf("s: %s\n", s);
	printf("t: %s\n", t);
	
	free(t);
}