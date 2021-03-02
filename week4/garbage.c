#include <stdio.h>

int main(void)
{
	int scores[3];
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", scores[i]);
	}
	// This will result in garbage values. This is teaching us to remember to initialize our variables.
}