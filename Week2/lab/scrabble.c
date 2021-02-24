#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Prototype functions
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // printf("score1: %d, score2: %d\n", score1, score2);
    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // First create an int value to store the score. This is the value that will be returned after the calculations.
    int sum = 0;
    /*
    I need to look at every char, and compare to the array to see the value of each letter.
    The array is represented in all capital letters. I will need to use the function toupper().
    I will need to specify when the loop will end, so I need to use strlen() or the \0 null ending.
    I need to convert each character of the string to an integer that can be used to compare.
    The letter 'A' starts at 41.

    */

    for (int i = 0; word[i] != '\0'; i++)
    {
        int check = toupper(word[i]) - 65;
        // printf("i = %d, word[i] = %c or %d, check value is: %d,point check = %d\n", i, toupper(word[i]), toupper(word[i]), check, POINTS[check]);
        if (check >= 0 && check <= 25)
        {
            sum = sum + POINTS[check];
        }
    }
    return sum;
}
