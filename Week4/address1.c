#include <cs50.h>
#include <stdio.h>


// A string is just a pointer to a location where the char* array is stored. This program will show the memory location of the values of the char* array.

// In C, string is a simplification of "char *".
int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
}
