#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for x
    int x = get_int("x: ");
    // Prompt for y
    int y = get_int("y: ");

    //Conditions for x in relation to y
    if(x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x < y)
    {
        printf("x is less than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }

}

