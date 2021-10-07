/*
TP3 - ex4
Emile BONDU
07/10/2021
palindromes
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char mot [100];
	char entree[100];

	printf("Entrer un mot :\n");
	for(int i = 0; i < 100 ; i++)
	{
	    fflush(stdin);
		scanf("%c", &mot[i]);
	}
	printf("\tmot de longeur : %ld", strlen(mot));

	return 0;
}