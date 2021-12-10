/*
TP8-9
Emile BONDU
26/11/2021
matrices, alloc dynamique
correction : https://pastebin.com/gzY66B6T
TODO : faire les transposees de matrices
*/

#include <stdio.h>
#include <stdlib.h>

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
