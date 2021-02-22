#include <stdio.h>
#include <cs50.h>

int get_positive(void);

int main(void)
{
    // I want to prompt the user to input a positive integer and return the number. I will use a seperate function to make sure the user a positive integer
    int i = get_positive();
    printf ("%i\n", i);
}

int get_positive(void)
{
    int n;
    do
    {
        n = get_int("Please input a positive integer: ");
    }
    while (n < 1);

    return n;
}