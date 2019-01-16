#include "pch.h"
#include<stdio.h>
#include <ctype.h>
#include <iostream>

int main()
{
	char string[100];
	printf("Enter string: ");
	scanf_s("%[^'\n']s", string, sizeof(string));

	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";

	int i, j;
	int count = 0;
	for (i = 0; i < strlen(alphabet); i++) {
		for (j = 0; j < strlen(string); j++) {
			if (alphabet[i] == tolower(string[j])) {
				count++;
			}
		}
		if (count > 0) {
			printf("Letter %c - %d times \n", alphabet[i], count);
			count = 0;
		}
	}


	return 0;
}