/*
TP2 - ex0
Emile BONDU
01/10/2021
manipulations de tableaux de tableaux
consideres comme des matrices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int matrice1 [2][3];
	int matrice2 [2][3];

	//initialisation des matrices (par des nombres aleatoires)

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrice1[i][j] = rand() % (100 + 1);
			matrice2[i][j] = rand() % (100 + 1);
		}
	}

    //affichage_de_matrice
    
    printf("matrice1 : \n");
	printf("-----------\n");
    for (int i = 0; i < 2; ++i)
	{
		printf("\t[");

		for (int j = 0; j < 3; ++j)
		{
			printf("%d\t", matrice1[i][j] );
		}
		printf("]\n");
	}
	printf("\n");
	
	//beurk on copie du code c'est moche
	//mais on connait pas encore les fonctions
	printf("matrice2 : \n");
	printf("-----------\n");
    for (int i = 0; i < 2; ++i)
	{
		printf("\t[");

		for (int j = 0; j < 3; ++j)
		{
			printf("%d\t", matrice2[i][j] );
		}
		printf("]\n");
	}
	printf("\n");
    
	return 0;
}