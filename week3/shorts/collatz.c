#include <cs50.h>
#include <stdio.h>

// Prototype
int calc(int n);

int main(void)
{
    int n = get_int("Number: ");

    printf("Steps: %d\n", calc(n));
}


int calc(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + calc(n / 2);
    }
    else
    {
        return 1 + calc (3 * n + 1);
    }
}