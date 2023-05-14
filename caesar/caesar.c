#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check if key has 2 Arguments
    if (argc != 2)
    {
        printf ("Usage: ./substitution key\n");
        exit (1);
    }
    //Defining a string that countains the argument
    string key = argv[1];
    int k = 26;
    //Making sure is Alphabetic
    for (int i = 0, argn = strlen(key); i < argn; i++)
	{
        if(isalpha (key[i]))
		{
            k = k-1;
        }
        else
        {
            printf ("Usage: ./substitution key\n");
            exit (1);
        }
    }
    //Making sure has 26 characters
    if (k != 0)
    {
        printf ("Key must contain 26 characters.\n");
        exit (1);
    }
    //Dealing with duplicates
    int duplicates = 0;
    for(int i = 0, a = strlen(key); i < a; i++)
    {
        for(int j = i + 1; j < a; j++)
        {
            if (tolower (key[i]) == tolower (key[j]))
            {
                duplicates ++;
            }
        }
        if (duplicates != 0)
        {
            printf("Repeated characters in key");
            exit(1);
        }
    }

    string text = get_string ("Plain text: ");
    //Get an original ASCII array and transform it value's to the key's value
    int array [122];
    int nc = strlen(text) + 1;
    char ciphertext [nc]; //declare a string that will be the converted one
    for(int i=65, d=0, e=0; d < 26; e++, i++, d++)
    {
    int up = toupper (key[e]);
    array[i] = up;
    }
    for (int i=97, d=0, e=0; d < 26; e++, i++, d++)
    {
    int low = tolower (key[e]);
    array[i] = low;
    }


    //Convert text to encrypted
    for (int i = 0; i < nc; i++)
    {
        if (isalpha (text[i]))
        {
        int b = text[i];
        int c = array[b];
        ciphertext [i] = (char)c;
        }
        else
        {
            ciphertext[i] = text [i];
        }
    }
    printf ("ciphertext: %s", ciphertext);
}