/*
TP2 - ex4
Emile BONDU
23/09/2021
jeu du plus ou du moins (ca doit bien etre mon 8e mais bon)
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{	
	bool continuer = true;
	int nbMystere = 0;

	printf("Quel sera le nombre secret ?\n");
	scanf("%d", &nbMystere);

	while(continuer)
	{
		int nbAsked = 0;
		printf("Quel nombre essayer ? \n");
		scanf("%d", &nbAsked)

		if(nbAsked > nbMystere)
		{
			printf("Faut chercher plus bas ! \n");
		}
		if(nbAsked > nbMystere)
		{
			printf("Faut chercher plus haut ! \n");
		}
		if(nbMystere == nbAsked)
		{
			printf("Trouve ! \n");
			continuer = false;
		}
	}

	return 0;
}