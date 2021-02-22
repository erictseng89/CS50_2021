#include <stdio.h>
#include <cs50.h>

//This program will make a double mario pyramid. The program will prompt for a positive integer between 1 and 8.

int get_height(void);
void printer(int l, int h);
void print_space(int l, int h);
void print_brick(int l);

//Global variable to allow the programmer to change the output of empty air and brick.
string air = " ";
string brick = "#";

int main(void)
{
    //Calls the function get_height to get the appropriate integer.
    int h = get_height();

    //Printing loop.
    for (int l = 0; l < h; l++)
    {
        printer(l, h);
    }
}


int get_height(void)
{
    // This function will make sure the user inputs an integer between 1 and 8.
    int t;
    do
    {
        t = get_int("Height: ");
    }
    while (t < 1 || t > 8);

    return t;
}


void printer(int l, int h)
{
    //This function prints the current level. It will call other functions to print the different parts.

    //First printing the spaces.
    print_space(l, h);

    //Printing the first half of the pyramid.
    print_brick(l);

    //Printing the spaces in between.
    printf("%s%s", air, air);

    //Printing the second half of the pyramid.
    print_brick(l);

    //Printing the space after the second half. This is not required in the problem set.

    /*
    print_space(l, h);

    printf("\n");
    */

    printf("\n");
}


void print_space(int l, int h)
{
    for (int s = 0; s < (h - l - 1); s++)
    {
        printf("%s", air);
    }
}


void print_brick(int l)
{
    //Printing a half of the pyramid.
    for (int a = 0; a <= l; a++)
    {
        printf("%s", brick);
    }
}