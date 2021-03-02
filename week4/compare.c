#include <cs50.h>
#include <stdio.h>

// int main(void)
// {
//     int i = get_int("i: ");
//     int j = get_int("j: ");

//     if (i == j)
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
// }

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // if (s == t) will always be different because the value of *s and *t are memory locations.
    if (*s == *t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

}