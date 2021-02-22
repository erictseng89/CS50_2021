#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask the user for a width to the number of question mark bricks. The result will be printed.
    int w = get_int("Width: ");

    for(int i = 0; i < w; i++)
    {
        printf("[?]");
    }

    printf("\n");

}