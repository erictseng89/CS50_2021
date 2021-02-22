#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program will encode a string of text using a key, both of which is provided by the user.
// The key is inputted as a number on the command line, the string of text will be prompted.


// Prototype functions
bool is_digit(char c);
bool is_lower(char c);
bool is_upper(char c);

const string error = "Usage: ./caesar key";

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("%s\n", error);
        return 1;
    }
    else
    {
        // Validate key.
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            char c = argv[1][i];
            if (is_digit(c) == false)
            {
                printf("%s\n", error);
                return 1;
            }
        }

        // Prompt user for the plaintext.
        string text = get_string("plaintext: ");

        // Make sure the key will be between 0 ~ 26
        int key = atoi(argv[1]);
        key = key % 26;
        // printf("Key: %d\n", key);

        // Printing ciphertext.
        printf("ciphertext: ");


        // The program will need to check is the character is a letter or not, it will only encode letters.
        for (int i = 0, n = strlen(text); i < n; i++)
        {
           int c = text[i];
           if (is_lower(c))
           {
               c = c + key;
               if (c > 122)
               {
                   c = c - 26;
               }
               printf("%c", c);
            }
            else if (is_upper(c))
            {
                c = c + key;
                if (c > 90)
                {
                    c = c - 26;
                }
                printf("%c", c);
            }
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

bool is_digit(char c)
{
    if (c < 48 || c > 57)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool is_lower(char c)
{
    // This function will check the char value if it is a lower-case letter
    if ( c >= 97 && c <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_upper(char c)
{
    // This function will check the char value if it is an upper-case letter.
    if ( c >= 65 && c <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}