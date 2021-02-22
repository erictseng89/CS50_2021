#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// This program will encode a string of text based on the substitution key inputted in the command line.
/* Specification:
Design and implement a program, substitution, that encrypts messages using a substitution cipher.

Implement your program in a file called substitution.c in a directory called substitution.
Your program must accept a single command-line argument, the key to use for the substitution.
The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
If your program is executed without any command-line arguments or with more than one command-line argument,
your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once),
your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext,
with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
*/

// Prototype functions
bool key_check(char array[]);
int locator(char c);

const string error = "Usage ./substitution key";

int main(int argc, string argv[])
{

    // First validate that the user has entered a correct command-line argument. If the user does not then print an error msg.
    if (argc != 2)
    {
        printf("%s\n", error);
        return 1;
    }
    // Then check if the key length is precisely 26 characters.
    else if (strlen(argv[1]) != 26)
    {
        printf("%s\n", error);
        return 1;
    }

    // Send to function key_check to do a proper validation.
    if (key_check(argv[1]) == false)
    {
        printf("%s\n", error);
        return 1;
    }

    // The key is validated, so now I need to generate the logic to decode any text given.
    // I need to store a value in an array that when added, will produce the substitution equaivalent.
    // Hence I will need an encoder which will see
    // Theres two ways I can do it. I can either do the math way, or do the save present case way.
    // If I do the math way, its straight forward, but the inital coding is difficult.
    // If I do the save present-case way, I will have to introduce more variables to keep track, but the coding will be easier.

    // First try the save present-case way.
    int key[26];
    for (int i = 0; i < 26; i++)
    {
        key[i] = locator(argv[1][i]);
    }

    // Now that the key is validated, I prompt the user for the string of text.
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    // Now I will check each letter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // x will denote the actual letter.
        int x = text[i];
        // Check if it is a letter.
        if (isalpha(x) == 0)
        {
            printf("%c", x);
        }
        else
        {
            // Save the case
            int uppercase = isupper(x);
            // I need to use locator to determine which letter current i is, then substitute it with the value inside the array,
            // then I need to add either 64 if uppercase or 96 if lowercase.
            int j = locator(x);
            // This will result in a number between 0 and 25.
            // I then use the key and produce the value of the given letter.
            int k = key[j];
            // Then I will need to return the value to the proper case and then print it.
            if (uppercase == 0) // means if uppercase is false.
            {
                printf("%c", k + 97);
            }
            else
            {
                printf("%c", k + 65);
            }
        }
    }
    printf("\n");
}


bool key_check(char array[])
{
    // This function will validate the key.
    // First will need to check that every character is a letter.
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(array[i]) == 0)
        {
            return false;
        }
    }
    // The key must contain each letter only once.
    // First make an array of size 26.
    // Upper case each letter so that it is easier to check.
    // If a letter is checked, add 1 to the value of the corresponding position in the array. [alpha[0] will be checking 'A']
    // If one of the values is increased to 2 it means that a letter is repeated, and the function will return false.

    // Create array
    int a[26];

    for (int i = 0; i < 26; i++)
    {
        a[i] = 0;
    }

    for (int i = 0; i < 26; i++)
    {
        // Use locator function to determine place.
        int j = locator(array[i]);
        a[j]++;
        // Check if the letter has appeared before.
        if (a[j] > 1)
        {
            return false;
        }
    }
    return true;
}

int locator(char c)
{
    // This function will be used to determine which numerical place is the letter is. At this point it has alread determined that it is an alphabet.
    // A will equal 0, Z will equal 25.
    int i = toupper(c) - 65;
    return i;
}