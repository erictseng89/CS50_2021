// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
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
#define N 26

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }

    // Read strings from file one at a time. Words are seperated by 0x0A. int l is to track how many letters in this word and to use in placing char c.
    char temp[LENGTH + 1];

    // Below is an attempt if not using fscanf.
    /* int l = 0;
    char c; */

    // Doing this with fscanf. Walkthrough 7:30.
    while (fscanf(dict, "%s", temp))
    {
        // Create a new node, check for NULL.
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy the word into the new node.
        strcpy(n->word, temp);

        // Find which hash of the hash table the word is at.
        int place = hash(n->word);

        // Inserting the node at the identified hash.
        n->next = table[place]->next;
        table[place]->next = &n;
    }
   
    // Below is an attempt if not using fscanf.
    /* while (fread(c, sizeof(uint8_t), 1, dict))
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
    if (feof(dict))
    {
        return true;
    }
    
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
