#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/*
The program analyzes the text given by the user and assesses the reading level based on the Colema-Liau formula.
index = 0.0588 * L - 0.296 * S - 15.8
The output will be the grade level the text's readability is.

Try to create seperate functions for letters, words and sentences.
*/

// Prototype
int l_counter(string t);
bool is_alpha(char c);
int w_counter(string t);
int s_counter(string t);
int grader(int l, int w, int s);

int main(void)
{
    // Prompt the user for the text.
    string t = get_string("Text: ");

    // I will need counters for letters, words and sentences. Should I use an array for that? Probably not as they will not be used together, but more than likely calculated differently.
    // First count the letters in the entire string. Remember that the end of string will be NUL or '\0'.

    // Next will count the number of words. A word is a string of chars that end with either a space, comma or a period. Checks each char of the string until it reaches one of them,
    // then count up. But there must be at least one letter in between all the stops.

    // Last counter is for sentences. Based on the problem set criteria, anything that ends with '.', '?' or '!' are considered sentences.

    int l = 0, w = 0, s = 0;
    bool a_letter = false;

    for (int i = 0; t[i] != '\0'; i++)
    {
        // Letter counter.
        if (is_alpha(t[i]))
        {
            l++;
        }

        // Word counter. There must be at least one word. Default value [a_letter] will be false.

        // The stops are space, comma, period, question marks and exclamation points. So basically anything that is not alpha, as well as apstrophies(39), and hypens(45) gets counted as a word.
        // printf("Char = %c, word count %d\n", t[i], w);
        if (a_letter == false)
        {
            a_letter = is_alpha(t[i]);
        }
        else if(is_alpha(t[i]) == false && t[i] != 39 && t[i] != 45)
        {
            w++;
            a_letter = false;

            // Sentence counter. Then if the char is an ending. The sentence counter will add by one.
            if (t[i] == '.' || t[i] == '?' || t[i] == '!')
            {
                s++;
            }
        }
    }

    /*
    printf("Letters: %d\n", l);
    printf("Words: %d\n", w);
    printf("Sentences: %d\n", s);
    */

    // Now to grade the string text. Send the letter, word, sentence values to the grader function to determine the grade.

    int index = grader(l,w,s);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index <=16)
    {
        printf("Grade %d\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }


}

bool is_alpha(char c)
{
    // This function will check the char value if it is a letter. First upper-case letters, then lower-case.
    if ( c >= 65 && c <= 90)
    {
        return true;
    }
    else if ( c >= 97 && c <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int grader(int l, int w, int s)
{
    /*
    This function will grade base on the values given of letters, words and setences.
    index = 0.0588 * L - 0.296 * S - 15.8
    Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    */

    float a = 0.0588, b = 0.296, c = 15.8;

    // First will need to calculate L and S values.
    // If there are longer words, L tends to be larger, and the text is deemed more difficult.
    float L = 100.0 * l / w;

    // If there are more sentences, S tends to be larger, and the text is deemed easier.
    float S = 100.0 * s / w;

    /*
    printf("letters: %d, words: %d, sentences: %d\n", l, w, s);
    printf("The float L: %f, S: %f\n", L, S);
    */

    // The index calculation.
    int index = round((a * L) - (b * S) - c);

    return index;
}