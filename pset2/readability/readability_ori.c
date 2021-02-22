#include <cs50.h>
#include <ctype.h>
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

int main(void)
{
    // Prompt the user for the text.
    string text = get_string("Text: ");

    // I will need counters for letters, words and sentences. Should I use an array for that? Probably not as they will not be used together, but more than likely calculated differently.
    // First count the letters in the entire string. Remember that the end of string will be NUL or '\0'.
    int letter_c = l_counter(text);
    printf("Letters: %d\n", letter_c);

    // Next will count the number of words. A word is a string of chars that end with either a space, comma or a period. Checks each char of the string until it reaches one of them,
    // then count up. But there must be at least one letter in between all the stops.
    int word_c = w_counter(text);
    printf("Words: %d\n", word_c);

    // Last counter is for sentences. Based on the problem set criteria, anything that ends with '.', '?' or '!' are considered sentences.
    int sentence_c = s_counter(text0);
    printf("Sentences: %d\n", setence_c);



}

int l_counter(string t)
{
    // This function will count the number of letters (a~z & A~Z) in the string provided.
    int l = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        if (is_alpha(t[i]))
        {
            l++;
        }
    }
    return l;
}

int w_counter(string t)
{
    // This function will count the number of words in the string provided.
    // There must be at least one word. Default will be false.
    int w = 0;
    bool a_letter = false;

    // The stops are space, comma, period, question marks and exclamation points. So basically anything that is not alpha, as well as apstrophies(39), and hypens(45) gets counted as a word.
    for (int i = 0; t[i] != '\0'; i++)
    {
        //printf("Char = %c, word count %d\n", t[i], w);
        if (a_letter == false)
        {
            a_letter = is_alpha(t[i]);
        }
        else if(is_alpha(t[i]) == false && t[i] != 39 && t[i] != 45)
        {
            w++;
            a_letter = false;
        }
    }
    return w;
}

int s_counter(string t)
{
    // This function will count the number of sentences in the string provided.
    int s = 0;
    bool a_world = false;
}

int counter(string t)
{
    // This will be the final counter to count everything.

    int l = 0, w = 0, s = 0;
    bool a_letter = false;

    for (int i = 0; t[i] != '\0'; i++)
    {
        // Letter counter.
        if (is_alpha(t[i]))
        {
            l++;
        }

        //Word counter.
        //printf("Char = %c, word count %d\n", t[i], w);
        if (a_letter == false)
        {
            a_letter = is_alpha(t[i]);
        }
        else if(is_alpha(t[i]) == false && t[i] != 39 && t[i] != 45)
        {
            w++;
            a_letter = false;

            // Sentence counter
            if (t[i] == '.' || t[i] = '?' || t[i] = '!')
            {
                s++;
            }
        }



        if (a_letter == true)


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