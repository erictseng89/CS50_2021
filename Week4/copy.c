#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(void)
// {
//     char *s = get_string("s: ");

//     char *t = s;

//     t[0] = toupper(t[0]);

//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }

// // This will result in char *t copying s itself(whose content is a memory location)

int main(void)
{
    char *s = get_string("s: ");

    // malloc is memory allocation, it allocates memory (in bytes) to the variable. malloc returns the address of the first byte which was requested. In this instance, *t is the pointer value, and only requires the address of the first byte.
    // In this case, the amount of memory will be however many chars in the string s plus an addition 1 for the null value at the end.
    char *t = malloc(strlen(s) + 1);
    
    // NULL represents a null pointer, it represents an absence of a memory location. 
    if (t == NULL)
    {
        return 1;
    }   

    // There is also a function called strcpy which can be used to easily copy two strings. Requires string.h library.
    // strcpy(t, s); where the first variable is the target, the second is the source.

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
        // This is the same as *(t + i) = *(s + 1);
    }
    
    if (strlen(t) > 0) // Error checking to make sure t is greater than 0.
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    
    // It is imperative to return the memory after the program has ended if we used 'malloc'.
    free(t);
    
}
