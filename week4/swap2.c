#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
	int x = 1;
	int y = 2;
	printf("x is %d, y is %d\n", x, y);
	swap(&x, &y);
	printf("x is %d, y is %d\n", x, y);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	
	// This swap function doesn't work because the functions passed through is merely a copy, and was not returned to the main function.

}