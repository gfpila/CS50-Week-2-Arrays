#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countletters (string text);
int letters = 0;

int countwords (string text);
int words = 1;

int countsentences (string text);
int sentences = 0;

int main(void)
{

    // Get letters
    string text = get_string("Text: ");
    letters = countletters (text);
    words = countwords (text);
    sentences = countsentences (text);
    int L = (float)letters/words * 100;
    int S = (float)sentences/words *100;
    int grade = (0.0588 * L - 0.296 * S - 15.8);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }


}

//Function that count letters.
int countletters (string text)
{
    for(int i = 0, l = strlen(text); i<l; i++)
    {
         if (isalpha (text[i]))
        {
            letters ++;
        }

    }
    return letters;
}

//Function that count words.
int countwords (string text)
{
    for(int i = 0, l = strlen(text); i<l; i++)
    {
         if (isspace (text[i]))
        {
            words ++;
        }

    }
    return words;
}

//Function that count sentences.
int countsentences (string text)
{
    for(int i = 0, l = strlen(text); i<l; i++)
    {
         if (text[i]== '!' || text[i]== '.' || text[i]== '?')
        {
            sentences ++;
        }

    }
    return sentences;
}