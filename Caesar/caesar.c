#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Checking if command line has 1 argument
    if (argc == 1 || argc > 2)
    {
        printf("Invalid argument");
        return 1;
    }
    //Converting argument to float then int
    float k = strtof(argv[1], NULL);
    int k1 = (int)k;
    int i, n;

    //String input
    string plainText = get_string("plaintext: ");
    //Printing caesar string
    printf("ciphertext: ");
    for (i = 0, n = strlen(plainText); i < n; i++)
    {
        k1 = k1 % 26;
        //If lowcase character
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            if (plainText[i] + k1 > 122)
            {
                int p = plainText[i] + k1 - 122;
                printf("%c", 96 + p);
            }
            else
            {
                printf("%c", plainText[i] + k1);
            }

        }
        //If uppercase character
        else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            if (plainText[i] + k1 > 90)
            {
                int p = plainText[i] + k1 - 90;
                printf("%c", 64 + p);
            }
            else
            {
                printf("%c", plainText[i] + k1);
            }
        }
        //If not alphabetic
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");

    return 0;
}