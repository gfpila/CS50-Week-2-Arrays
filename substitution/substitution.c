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
    int up = toupper (key[e]); //if key is z, so its 122, but it converts to Z so it's 90, so up = 90
    array[i] = up;  //now the first element of the array 65 = 90 it means A = Z
    }
    for (int i=97, d=0, e=0; d < 26; e++, i++, d++)
    {
    int low = tolower (key[e]); //so now i get z, converts to 122, its z = 122
    array[i] = low; //now i get arrer [97] = 122; so a=z
    }


    //Convert text to encrypted
    for (int i = 0; i < nc; i++)
    {
        if (isalpha (text[i]))
        {
        int b = text[i]; //get the ASCII value of the text, if text[i] = A then i get b = 65
        int c = array[b]; //put the ASCII value in the array that converts, now i put 65 to array, the element 65 is already converted so it gives me the encrypted ASCII
        ciphertext [i] = (char)c; //populate the converted one with the converted ascii, i put the first element of the text, as the encrypted ascii
        }
        else
        {
            ciphertext[i] = text [i]; //if it's not alphabetical, then i say the element is equal to the element of text no cryptography
        }
    }
    printf ("ciphertext: %s", ciphertext);
    for (int i = 0; i < nc; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}