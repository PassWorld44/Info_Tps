/*
TP6 - ex4
Emile BONDU
26/11/2021
matrices, alloc dynamique
correction : https://pastebin.com/gzY66B6T
TODO : faire les transposees de matrices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplitMatriceAlea (int** matrice, int nb_lignes, int nb_colonnes);
void afficheMatrice (int** matrice, int nb_lignes, int nb_colonnes);
void matriceSerpent (int** matrice, int taille_cote);

int** transpose(int** matrice, int nb_lignes, int nb_colonnes); //TODO

int mini = 0, maxi = 100;
//c'est moche mais c'est demande, rip les var globales

int main()
{
	int** matrice;
	int nb_lignes, nb_colonnes;

	srand(time(NULL));
	
	printf("Quel nombre de collones ?\n");
	scanf("%d", &nb_colonnes);
	printf("Quel nombre de lignes ?\n");
	scanf("%d", &nb_lignes);

	matrice = malloc(nb_colonnes * sizeof(int*));
	for(int i = 0; i < nb_colonnes; i++)
	{
		matrice[i] = malloc(nb_lignes * sizeof(int));
	}

	if ( nb_colonnes = nb_lignes )
	{
		matriceSerpent(matrice, nb_colonnes);
	}
	else
	{
		remplitMatriceAlea(matrice, nb_lignes, nb_colonnes);
	}

	printf("\n");
	afficheMatrice(matrice, nb_lignes, nb_colonnes);

	//on transpose la matrice
	int** transposee = transpose(matrice, nb_lignes, nb_colonnes);

	printf("\n");
	afficheMatrice(transposee, nb_colonnes, nb_lignes);

	//on libere bien les variables allouees dynamiquement
	for(int i = 0; i < nb_colonnes; i++)
	{
		free(matrice[i]);
	}
	free(matrice);

	for(int i = 0 ; i < nb_lignes; i++)
	{
		free(transposee[i]);
	}
	free(transposee);

	return 0;
}

void remplitMatriceAlea (int** matrice, int nb_lignes, int nb_colonnes)
{
	for(int i = 0; i < nb_lignes; i++)
	{
		for(int j = 0; j < nb_colonnes; j++)
		{
			matrice[i][j] = (rand() % (maxi - mini + 1) + mini);
		}
	}
}

void afficheMatrice (int** matrice, int nb_lignes, int nb_colonnes)
{
	for(int i = 0; i < nb_lignes; i++)
	{
		for(int j = 0; j < nb_colonnes; j++)
		{
			printf("%-10d", matrice[i][j] );
		}
		printf("\n");
	}
}

void matriceSerpent (int** matrice, int taille_cote)
// prend une matrice caree
{
	for(int i = 0; i < taille_cote; i++)
	{
		for(int j = 0; j < taille_cote; j++)
		{
			if(i % 2 == 0)
			{
				matrice[i][j] = i * taille_cote + j + 1;
			}
			else
			{
				matrice[i][j] = (i + 1) * taille_cote - j;
			}
		}
	}
}

int** transpose(int** matrice_d, int nb_lignes, int nb_colonnes)
// valeur de retour : allouee dynamiquement, necessite de free
// tableau de tableau de dimentions inversee par rapport a celles donees
{
	int** transposee;

	//on doit la malloc car invertion des dimentions
	transposee = (int**)malloc(nb_lignes * sizeof(int*));
	for(int i = 0; i < nb_colonnes; i++)
	{
		transposee[i] = malloc(nb_colonnes * sizeof(int));
	}

	//affectation des valeurs de l'ancienne matrice
	for(int i = 0; i < nb_lignes; i++)
	{
		for(int j = 0; j < nb_colonnes ; j++)
		{
			transposee[i][j] = matrice_d[j][i];
		}
	}

	return transposee;
}