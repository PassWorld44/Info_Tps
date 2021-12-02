/*
TP6 - ex4
Emile BONDU
26/11/2021
matrices
NON FINI
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplitMatrice (int* ptr);
void afficheMatrice (int* ptr);

int mini = 0, maxi = 100;
//c'est moche mais c'est demande

int main()
{
	
	int matrice[4][4];
	int* pointeur = &matrice;
	srand(time(NULL));
	
	remplitMatrice(pointeur);

	printf("Matrice Initiale (pointeur)\n");
	printf("---------------------------\n");
	afficheMatrice(pointeur);
	printf("\n");

	return 0;
}

void remplitMatrice (int* ptr)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			*(ptr + 4*i + j) = (rand() % (maxi - mini + 1) + mini);
		}
	}
}

void afficheMatrice (int* ptr)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%-10d", *(ptr + 4*i + j) );
		}
		printf("\n");
	}
}