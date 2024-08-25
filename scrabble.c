#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_score(string word);
int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // sets points for each letter
int main(void)
{
    string word1 = get_string("Player 1: "); // promts user for word
    string word2 = get_string("Player 2: "); // promts user for word
    int score1 = count_score(word1);
    int score2 = count_score(word2);

    if (score1 > score2)
    {
        printf("player 1 wins \n");
    }
    else if (score1 < score2)
    {
        printf("player 2 wins \n");
    }
    else
    {
        printf("tie \n");
    }

    return 0;
}

int count_score(string word) // counts score
{
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (isupper(word[i]))
        {
            score = score + POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 'a'];
        }
    }
    return score;
}
