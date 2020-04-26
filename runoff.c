#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define max no of voters at 100, and max no of candidates 9
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is the index of candidate who is  jth pref for voter i, ie rank of candidate for voter i. e.g. preference[0][1] means voter ranked the first candidate second
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

    // check for too many candidates (ie more than 9)
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    // Populate array of candidates (initialising their votes to 0, and elimination status at FALSE for now). remember i is count of voters.
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Check if invalid number of voters

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
        // Calculate votes given remaining candidates - look at all voters’ prefs and compute current vote totals, by looking at each voter’s top choice candidate who hasn’t yet been eliminated.
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
   // Look for candidate called [name]. If candidate found, update preferences so that they are the voter's rank preference, and return true

   for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            int j = rank;
            return true;
        }
    }

   ////if no candidate found, don't update any preferences, and return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    voter_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            candidates[i].votes++;
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // ** INCOMPLETE ** For each candidate, check if their  top ranked votes  > (voter_count / 2), and if so then they win
    for (int i = 0; i < candidate_count; i++)
    {
            if (j == 0);
            candidates[i].votes++;
            if (candidates[i].votes > (voter_count/2))
            {
                return true;
            }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // INCOMPLETE

    int min_vote_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            candidates[i].votes++;
            mint_vote_count = candidates[i].votes;
        }
    }
    return min_vote_count;

    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
