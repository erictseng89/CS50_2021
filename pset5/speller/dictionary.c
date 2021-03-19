// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// Was originally:
// const unsigned int N = 1;
// Changed to:
#define N 676

// Hash table
node *table[N];

// Keeps track of dictionary size
int track_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // strcasecmp compares two strings in a case-insensitive manner.
    // The first node to look at will be the node at table[place]->next.

    // Create a cursor node to use to check each node.
    node *cursor;

    // Hash the word.
    int place = hash(word);

    // Point cursor at the first node.
    cursor = table[place];

    // Loop for looking through the linked list.
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // 26 * 26 = 676 For the first 2 letters. This will mean that 26 will be 'B' and
    // First read the first 2 letters, will use tolower function. 'a' is 97 and 'z' is 122.
    int hash = 0;
    if (strlen(word) > 1)
    {
        int i = tolower(word[0]) - 97;
        int j = tolower(word[1]) - 97;
        hash = (i * 26) + j;
    }
    else if (strlen(word) == 1)
    {
        hash = tolower(word[0]) - 97;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *dicptr = fopen(dictionary, "r");
    if (dicptr == NULL)
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }

    // Read strings from file one at a time. Words are seperated by 0x0A. int l is to track how many letters in this word and to use in placing char c.
    char temp[LENGTH + 1];

    // Below is an attempt if not using fscanf.
    /* int l = 0;
    char c; */

    // Initialise table?
    /* for (int i = 0; i < 676; i++)
    {
        table[0] = malloc(sizeof(node));
    } */

    // Doing this with fscanf. Walkthrough 7:30.
    while (fscanf(dicptr, "%s", temp) != EOF)
    {
        // Create a new node, check for NULL.
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dicptr);
            return false;
        }

        // Copy the word into the new node.
        strcpy(n->word, temp);

        n->next = NULL;

        // Find which hash of the hash table the word is at.
        int place = hash(n->word);

        if (place > 25)
        {
            ;
        }
        // Inserting the node at the identified hash.
        n->next = table[place];
        table[place] = n;

        // Adding one to track size
        track_size++;
    }

    // Below is an attempt if not using fscanf.
    /* while (fread(c, sizeof(uint8_t), 1, dicptr))
    {
        // Once the buffer becomes 0x0A, it means the word is complete. Will then need to add a \0 (NUL) to end the string. The program will then  create a new node, hash the word and place it in a new node, and then reset the letter counter.
        if (c == 0x0A)
        {
            // Complete the string
            temp[l] = '\0';

            // Create a new node, check for NULL
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }

            // Copy the word into the new node.
            strcpy(n->word, temp);

            // Find which hash of the hash table the word is at.
            int place  = hash(n->word);

            // Inserting the node at the identified hash.
            n->next = table[place]->next;
            table[place]->next = &n;

            // Resetting the letter counter.
            l = 0;
        }
        temp[l] = c;
    } */

    // Checking end of file.
    if (feof(dicptr))
    {
        fclose(dicptr);
        return true;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return track_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Create two variables to keep track of linked list.
    node *cursor;
    node *temp;
    /* if (cursor == NULL || temp == NULL)
    {
        return 1;
    }
 */
    // Loop for entire array
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        temp = table[i];

        // Start checking through the linked list if it exists, and exiting this loop if it has reached the end.

        while (cursor != NULL)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        if (i == N - 1)
        {
            return true;
        }

    }
    return false;
}
