#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
//This problem will validate x credit card number xnd determine whether they xre AMEX, VISA, MASTERCARD or INVALID.

string check_main(long long n);
bool validate_length(long long n);
void check_sum(long long n);
string validate_header(int x, int y, int digit_count);
bool chk_amex(int x, int y);
bool chk_visa(int x);
bool chk_mc(int x, int y);

/*
AMEX has a length of 15 digits. 3.4*10^15 up to 3.5*10^15, s well as 3.7*10^15 up to 3.7*10^15.
VISA has length of either 13 or 16 digits. It starts with 4.
MASTERCARD has a length of 16 digits. It starts with 51,52,53,54,55.
*/

string a = "AMEX";
string b = "VISA";
string c = "MASTERCARD";
string d = "INVALID";

int main(void)
{
    //First prompt user for number.
    long long n = get_long_long("Number: ");
    //printf("The number is: %lld\n", n);

    //Do a general check for length of numbers.
    if (validate_length(n) == false)
    {
        printf("%s\n", d);
    }
    else
    {
        check_sum(n);
    }
}


bool validate_length(long long n)
{
    // This function will first determine too small or too large numbers and return invalid.

    long long small = 4000000000000;
    long long large = 5600000000000000 - 1;

    if (n < small || n > large)
    {
        //printf("The number is either too small or too large\n");
        return false;
    }
    else
    {
        //printf("The number is the correct length.\n");
        return true;
    }
}

void check_sum(long long n)
{
    //This is check sum to calculate the credit card number by using modulo 10 on the last digit, then subtracting the number and dividing by 10.
    int sum = 0;
    bool add = true;
    int x = 0;
    int y = 0;
    int digit_count = 0;

    do
    {
        if (add == true)
        {
            int i = n % 10;
            sum = sum + i;
            //printf("Addition: Added %d, current sum is: %d.\n", i, sum);
            y = x;
            x = i;
            n = (n - i) / 10;
            add = false;
        }
        else
        {
            int i = n % 10;
            int j = 2 * i;

            if (j > 9)
            {
                j = (j % 10) + 1;
            }

            sum = sum + j;
            //printf("Multiplication: Added %d, current sum is: %d.\n", i, sum);
            y = x;
            x = i;
            n = (n - i) / 10;
            add = true;
        }

        digit_count++;
    }
    while (n > 0);

    //printf("The sum is: %d.\nThe count is: %d.\nThe first digit is: %d.\nThe second digit is: %d.\n", sum, digit_count, x, y);

    if (sum % 10 != 0)
    {
        printf("%s\n", d);
    }
    else
    {
        printf("%s\n", validate_header(x, y, digit_count));
    }
}


string validate_header(int x, int y, int digit_count)
{
    //This function is to determine the credit card type.

    if (digit_count < 14 && chk_visa(x) == true)
    {
        return b;
    }
    else if (digit_count == 15 && chk_amex(x, y) == true)
    {
        return a;
    }
    else if (digit_count == 16)
    {
        if (chk_visa(x) == true)
        {
            return b;
        }
        else if (chk_mc(x, y) == true)
        {
            return c;
        }
        else
        {
            return d;
        }
    }
    else
    {
        return d;
    }
}

bool chk_amex(int x, int y)
{
    //This is a boolean function check to see if the initial header matches card type.
    if (x == 3)
    {
        if (y == 4 || y == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


bool chk_visa(int x)
{
//This is a boolean function check to see if the initial header matches card type.
    if (x == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool chk_mc(int x, int y)
{
//This is a boolean function check to see if the initial header matches card type.
    if (x == 5)
    {
        if (1 <= y && y <= 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

