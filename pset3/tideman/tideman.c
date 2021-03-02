#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Winner loser boolean for lock_pairs and print_winner function.
bool source[MAX];
bool loser[MAX];

// Create an array to record all the differences.
int pair_diff[MAX * (MAX - 1) / 2];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void sort_rec(int n, int s);
int diff(pair c);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        /* below is debug printf
        for (int k = 0; k < voter_count; k++)
        {
            printf("#%d voter's preference: ", k);
            for (int l = 0; l < candidate_count; l++)
            {
                printf("%d ", preferences[k][l]);
            }
            printf(".\n");
        }

        */

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // This function looks at one voter's preferences.
    // This function will be given the name of the candidate (var.string name).
    // It will be given the voter's rank for this candidate (var.int rank).
    // It will then update the var.array-int ranks[].
    // Use strcmp to make sure the name of the candidate is correct.

    // Search for candidate name.
    for (int i = 0; i < candidate_count; i++)
    {
        // If name is found, then update ranks.
        if (strcmp(name, candidates[i]) == 0)
        {
            /* Below printf is for debugging */
            // printf("strcmp result: %s and candidate #%d who is %s returned 0.\n", name, i + 1, candidates[i]);

            ranks[rank] = i;
            return true;
        }
    }

    // If name is not found, return false.
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // This function is called once for each voter, after the array int ranks[] has been tallied.
    // This function will update the array.preferences[i][j].
    // ranks[0] will be preferred over every other candidate.
    // 1. preferences[ranks[0]][j] will add by one for each j.
    // ?Create a bool array with candidates to identify whether they have been tallied yet.
    // Something like tallied[candidate_count]. We will go through each preferences[rank[]][j]
    // If tallied[j] is true, then skip this vote, otherwise add by one.

    // tallied will record whether the ith where i is the same as preferences.
    bool tallied[candidate_count];
    for (int k = 0; k < candidate_count; k++)
    {
        tallied[k] = false;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        // printf("ranks[%d] value is %d.\n", i, ranks[i]);

        for (int j = 0; j < candidate_count; j++)
        {
            // printf("tallied[%d] value is %d. Where 1 is true, and 0 if false.\n", j, tallied[j]);
            if (ranks[i] != j)
            {

                if (!tallied[j])
                {
                    preferences[ranks[i]][j]++;
                    // printf("Current preference[%d][%d] is: %d.\n", ranks[i], j, preferences[ranks[i]][j]);
                }
            }

        }
        tallied[ranks[i]] = true;
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // Need to use pair_count to record which pair[k] to update.
    // For each preferences[i][j] pair, see if preferences[i][j] is greater than preferences[j][i].
    // If so, then add the values in the array.pairs[k].
    //

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // printf("Checking preferences[%d][%d] to see if there is a pair.\n", i, j);
            if (preferences[i][j] > preferences[j][i])
            {
                // printf("The above preference is a pair. %d > %d.\n", preferences[i][j], preferences[j][i]);
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // printf("pairs[%d]'s winner and losers are: #%d and #%d.\n", pair_count, i, j);
                pair_count++;
                // printf("pair count is current at: %d.\n", pair_count);

            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // Create a sorting function using recursion.
    // Note that each pair actually represents a number. So think of a recursive number sorter.
    // Use the int pair_count. Sort left half of pair_count, then sort right half.
    // After sort, then arrange them. compare two values, the higher goes next into pairs variable.
    // Do I need to create a copy of pairs?

    sort_rec(pair_count, 0);
    return;
}

int diff(pair c)
{
    int i = c.winner;
    int j = c.loser;
    return (preferences[i][j] - preferences[j][i]);
}

void sort_rec(int n, int s)
{
    // This is the main recursion function. var.int n = how many numbers to sort, var.int s = starting index in the array.

    // If n < 2, meaning theres only 1 or 0 numbers to sort, then return.
    if (n < 2)
    {
        return;
    }

    // Working out the new variables needed for left and right merge sort.
    int leftn, rightn, lefts, rights = 0; // variables for left half and right half.

    if (n % 2 == 1) // If odd.
    {
        leftn = (n + 1) / 2;
        rightn = (n - 1 ) / 2;
        lefts = s;
        rights = s + (n + 1) / 2;
    }
    else // If even.
    {
        leftn = n / 2;
        rightn = n / 2;
        lefts = s;
        rights = s + (n / 2);
    }

    // Merge sort left half and right half.
    sort_rec(leftn, lefts);
    sort_rec(rightn, rights);

    // current left count and right count.
    int leftc = 0;
    int rightc = 0;
    pair temp[n]; // temporary array to store the sorted array.


    for (int i = 0; i < n ; i++)
    {
        // These are probably not necessary.
        pair leftv = pairs[lefts + leftc];
        pair rightv = pairs[rights + rightc];

        // If there are no more numbers in the left half of the array, then populate new array using right half.
        if (leftc >= leftn)
        {
            temp[i] =  rightv;
            rightc++;
        }
        // If there are no more numbers in the right half of the array, the popular new array using left half.
        else if (rightc >= rightn)
        {
            temp[i] = leftv;
            leftc++;
        }
        // If left value is greater than right.
        else if (diff(leftv) > diff(rightv))
        {
            temp[i] = leftv;
            leftc++;
        }
        // If right value is greater than left.
        else if (diff(rightv) > diff(leftv))
        {
            temp[i] = rightv;
            rightc++;
        }
        else if (diff(leftv) == diff(rightv))
        {
            temp[i] = leftv;
            leftc++;
        }
        else
        {
            // printf("Sorting error.\n");
            // return;
        }
    }
    // Updating original array with sorted array.
    for (int i = 0; i < n; i++)
    {
        pairs[s + i] = temp[i];
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO

    // To prevent a cycle, we will use the following system:
    // If a candidate has already a been loser in a previous pair, then the candidate can no longer point to a current source.
    // Thus there needs to be an two boolean arrays to see record who is a source and who has been a loser.

    // First source will be the winner in the first pair.

    //initializing the two boolean arrays.
    for (int i = 0; i <candidate_count; i++)
    {
        source[i] = false;
        loser[i] = false;
    }


    // Then go through each pair.
    for (int i = 0; i < pair_count; i++)
    {
        // Create a temporary var.pair to ease coding readability. c for current.
        pair c = pairs[i];

        if (loser[c.winner])
        {
            // If the winner in current pair has been a loser before.
            if (source[c.loser])
            {
                // If a loser has a win over a source, then do nothing.
                ;
            }
            else
            {
                // Or else just record the locked pair.
                locked[c.winner][c.loser] = true;
                loser[c.loser] = true;
            }
        }
        else if (!loser[c.winner])
        {
            // If a winner has never lost before, then they become a source. If their opponent was once a source, then they are no longer a source.
            locked[c.winner][c.loser] = true;
            source[c.winner] = true;
            loser[c.loser] = true;
            if (source[c.loser])
            {
                source[c.loser] = false;
            }
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    // Parse through locked array. locked[i][j]
    // See for which candidate, where when they are the j, the result is all false.
    for (int i = 0; i < candidate_count; i++)
    {
        if (source[i])
        {
            printf("%s", candidates[source[i]]);
        }
    }
    return;
}



