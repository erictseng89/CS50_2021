#include <cs50.h>
#include <stdio.h>

void build(int l);

int main(void)
{	
	// Doesn't work....
	int levels;
	do
	{
		levels = get_int("How many levels: ");
	}
	while(levels < 100);
	
	build(levels);
}

void build(int l)
{
	if (l < 1)
	{
		return;
	}
	
	build(l - 1);

	for(int i = 0; i < l; i++)
	{
		printf("#");
	}
	printf("\n");
	return;
}