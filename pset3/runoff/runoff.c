#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    /*
    int voter: the ith voter
    rank: the placement in which the ith voter ranked the following candidate
    string name: The name of the candidate

    1. Check voter is in database.
    2. If in database, record the vote in preferences.
    */
   for (int i = 0; i < candidate_count; i++)
   {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
   }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    /*
    1. Parse through preferences.
    2. For each name = preferences[i][j] value, use strcmp(name, candidates[k].name) == 0, and check value of .eliminated
    3. If .eliminated == false, then that candidates .votes++.
    4. If .eliminated == true, then go down preferences[i][j+1] and do the same.
    5. Repeat while i is < voter_count
    */

    // Parse through each voter.
    for (int i = 0; i < voter_count; i++)
    {
        // Go through rankings. j is the rank.
        for (int j = 0; j < candidate_count; j++)
        {
            // For each rank, see if candidate has been eliminated yet.
            if (!(candidates[preferences[i][j]].eliminated))
            {
                // If has not been elimated, then add a vote, then exit out of this for-loop.
                candidates[preferences[i][j]].votes++;
                j = candidate_count;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    /*
    1. Calculate the amount of vote required to determine winner.
    2. Check if the any candidates has the required amount of votes.
    3. If any candidate has the appropriate number of votes, then print true, else false.
    */

    // Determine required amount of votes
    int r;
    if (voter_count % 2 == 1)
    {
        r = ((voter_count - 1) / 2 );
    }
    else
    {
        r = voter_count / 2;
    }
    printf("r = %d\n", r);
    // Check if any of the candidates has enough votes.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > r)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    /*
    Return an interger, where the integer is the minimum number in votes that any remaining candidate has.
    1. Create a variable to store the lowest number.
    2. Parse through candidates[i].votes looking for lowest number.
    3. return number.
    */

    int low = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if(candidates[i].votes < low)
            {
                low = candidates[i].votes;
            }
        }
    }
    return low;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    /*
    This function checks the candidates[i].votes and checks if everyone has the same number.
    1. Record the first non-eliminated candidate's vote.
    2. Check every candidate, if theres a difference, then return false.
    3. If checked until the last one (candidiate_count -1), and the function is still running, then return true.
    */

    int tie_check = 0;

    // Record first non-eliminated candidate's vote.
    for (int i = 0; i < candidate_count; i++)
    {
        if (!(candidates[i].eliminated))
        {
            tie_check = candidates[i].votes;
            break;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != tie_check)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    /*
    1. Parse through each candidate, if their .votes = min, then change eliminated to true.
    */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
