/*
TP3 - ex4
Emile BONDU
07/10/2021
palindromes
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char mot[100]);

int main()
{
	char mot [100];
	char entree;

	do
	{

		printf("Entrer un mot :\n");
		scanf("%s", &mot);

		printf("\tmot de longeur : %ld\n", strlen(mot));
		printf("\n");

		if(isPalindrome(mot))
		{
			printf("\tLe mot %s est un palindrome\n", mot);
		}
		else
		{
			printf("\tLe mot %s n'est pas un palindrome\n", mot);
		}

		printf("\nSouhaitez-vous faire un autre test ? <0 pour oui>\n");
		fflush(stdin);
		scanf("%s", &entree);
	}
	while(entree == '0');
	
	return 0;
}

bool isPalindrome(char mot[100])
{
	int size = strlen(mot);
	for(int i = 0; i < 100 && mot[i] != '\0'; i++)
	{
		//printf("%c %c\n", mot[i], mot [size - i - 1]);
		if(mot[i] != mot [size - i - 1])
		{
			return false;
		}
	}

	return true;
}