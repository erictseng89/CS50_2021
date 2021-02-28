#include <stdio.h>
#include <cs50.h>

// & before a variable means "the memory location of", in printf it will be %p, indicating a pointer
// * before a variable means "go to the location of"

int main(void)
{
    int n = 50;
    int *p = &n;
    // This is a pointer variable, it has to equal a memory location of the same type of variable, which in this case is an integer. This stores "the memory address of n" in "*p"
    printf("%d.\n", *p);
}