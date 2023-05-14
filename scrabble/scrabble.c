#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Array that will take the ASCII number
int array[122];

int totalpoints = 0;

int compute_score(string word);

int main(void)
{
    // Loop to assign each ASCII number to a number of points
    for(int i=65, d=0, e=0; d < 26; e++, i++, d++)
    {
    array[i] = points[e];
    }
    for (int i=97, d=0, e=0; d < 26; e++, i++, d++)
    {
    array[i] = points[e];
    }


    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    totalpoints = 0;
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Its a tie!");
    }

}

int compute_score(string word)
{
    for (int i=0, n = strlen(word); i<n; i++)
    {
        int b = word[i];
        int c = array[b];
        totalpoints = totalpoints + c;
    }
    return totalpoints;
}