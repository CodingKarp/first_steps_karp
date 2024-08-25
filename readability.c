#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
float avg_l(float letters, float words);
float avg_s(float sentences, float words);
int main(void)
{
    string text = get_string("Text: "); // promts text from user
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // counts the Coleman-Liau index.
    float index = 0.0588 * avg_l(letters, words) - 0.296 * avg_s(sentences, words) - 15.8;
    int grade = (int) round(index); // rounds the final grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int letters = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    words++;
    return words;
}

int count_sentences(string text)
{
    int sentence = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentence++;
        }
    }
    return sentence;
}

float avg_l(float letters, float words)
{
    float l = (letters / words) * 100;
    return l;
}

float avg_s(float sentences, float words)
{
    float s = (sentences / words) * 100;
    return s;
}
