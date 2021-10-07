/*
TP3 - ex2
Emile BONDU
01/10/2021
manipulations de tableaux de tableaux
consideres comme des matrices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Yeees on connait enfin les fonctions, plaisir
void afficher(int mat[2][3]);
void afficher_mat6(int mat[6]);
void lineariser(int matInit[2][3], int matOutput[6]);
void addThermeATherme(int mat1[2][3], int mat2[2][3], int matOutput[2][3]);
void multThermeATherme(int mat1[2][3], int mat2[2][3], int matOutput[2][3]);

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
    afficher(matrice1);
	
	printf("matrice2 : \n");
	printf("-----------\n");
    afficher(matrice2);

	//linearisation

	int matrice3 [6];
	lineariser(matrice1, matrice3);
	
    printf("matrice3 : \n");
	printf("-----------\n");
    afficher_mat6(matrice3);

    int matAdd [2][3];
    addThermeATherme(matrice1, matrice2, matAdd);
	printf("matAdd : \n");
	printf("-----------\n");
    afficher(matAdd);

    int matMult [2][3];
    multThermeATherme(matrice1, matrice2, matMult);
	printf("matMult : \n");
	printf("-----------\n");
    afficher(matMult);

	return 0;
}

void afficher(int mat[2][3])
{
	for (int i = 0; i < 2; ++i)
	{
		printf("\t[");

		for (int j = 0; j < 3; ++j)
		{
			printf("%d\t", mat[i][j] );
		}
		printf("]\n");
	}
	printf("\n");
}

void afficher_mat6(int mat[6])
{
	printf("\t[");
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\t", mat[i] );
	}
	printf("]\n");
}

void lineariser(int matInit[2][3], int matOutput[6])
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matOutput[i * 3 + j] = matInit[i][j];
		}
	}
}

void addThermeATherme(int mat1[2][3], int mat2[2][3], int matOutput[2][3])
{
	for (int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 3; j++)
		{
			matOutput[i][j] = mat1[i][j] + mat2[i][j];
		}	
	}
}

void multThermeATherme(int mat1[2][3], int mat2[2][3], int matOutput[2][3])
{
	for (int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 3; j++)
		{
			matOutput[i][j] = mat1[i][j] * mat2[i][j];
		}	
	}
}
