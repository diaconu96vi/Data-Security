#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Checking command line has 1 argument
    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }
    //Checking if keyword is alphabetical
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Invalid input \n");
                return 1;
            }
        }
    }
    string k = argv[1];
    //Char array storing the alphabet
    char mapping[26];
    for (int i = 0; i < 26; i++)
    {
        mapping[i] = 'A' + i;
    }
    //Getting plaintext
    string plainText = get_string("plaintext: ");
    int position = 0;
    //Printing ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plainText), m = strlen(k); i < n; i++)
    {
        position = position % m;
        //If letter is uppercase
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            //Searches the keyword in alphabet(mapping) and encrypts
            for (int count = 0; count < 26; count++)
            {
                if (mapping[count] == toupper(k[position]))
                {

                    if (plainText[i] + count > 90)
                    {
                        int dif = plainText[i] + count - 90;
                        printf("%c", 64 + dif);
                    }
                    else
                    {
                        printf("%c", plainText[i] + count);
                    }

                }
            }
            position++;

        }
        //If letter is lowercase
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            for (int count = 0; count < 26; count++)
            {
                if (mapping[count] == toupper(k[position]))
                {

                    if (plainText[i] + count > 122)
                    {
                        int dif = plainText[i] + count - 122;
                        printf("%c", 96 + dif);
                    }
                    else
                    {
                        printf("%c", plainText[i] + count);
                    }

                }
            }
            position++;
        }
        //If not alphabetical
        else
        {
            printf("%c", plainText[i]);
        }

    }
    printf("\n");
    return 0;
}