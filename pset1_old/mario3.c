#include <stdio.h>
#include <cs50.h>

//This program will create an image similar to the mario pyramid.

int main(void)
{
    printf("Height: ");
    int height = get_int();

    //The height must b non-negative and smaller than 23.
    bool valid = height > 0 && height <= 23;
    while(valid == false)
    {
        printf("Height: ");
        height = get_int();
    }

    for(int i = 0; i < height; i++)
    {
        for(int space0 = 1; space0 < height-i; space0++)
        {
            printf(" ");
        }

        for(int hash0 = 0; hash0 <= i; hash0++)
        {
            printf("#");
        }

        printf(" ");

        for(int hash1 = 0; hash1 <= i; hash1++)
        {
            printf("#");
        }
        for(int space1 = 1; space1 < height - i; space1++)
        {
            printf(" ");
        }

        printf("\n");
    }

}