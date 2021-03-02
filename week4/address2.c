#include <stdio.h>


// char * can just replace string, thus allow us to not use the CS50 lib for string variable.

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    // We can use this method to see what the value at the location of the pointer of s.
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
