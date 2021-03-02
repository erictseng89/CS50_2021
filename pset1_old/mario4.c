
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int floor = get_int("This program will create a Mario Pyramid, the number of levels based on your input.\nThe number of levels: ");

	while (floor < 0 || floor > 23)
	{
	    floor = get_int("Invalid Number. Please input a number between 0 and 23: \n");
	}

	int floors2 = floor;

	printf("\n");

	while (floors2 != 0)
	{
		for (int space = 0; space <= floors2; space++)
		{
			printf("  ");
		}

	   	for (int blocks = 0; blocks <= (floor - floors2); blocks++)
	    {
	        printf("[]");
        }

	    printf(" ");

	   	for (int blocks = 0; blocks <= (floor - floors2); blocks++)
	    {
	        printf("[]");
        }

		for (int space = 0; space <= floors2; space++)
		{
	        printf("  ");
		}

	    printf("\n");

		floors2--;
	}
}