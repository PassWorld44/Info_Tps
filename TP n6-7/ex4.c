/*
TP6 - ex4
Emile BONDU
26/11/2021
matrices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplitMatrice (int* ptr);
void affichematrice (int* ptr);

int mini = 0, maxi = 100;
//c'est moche mais c'est demande

int main()
{
	
	int matrice[4][4];
	int* pointeur = &matrice;
	srand(time(NULL));
	
	remplitMatrice(pointeur);

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

void affichematrice (int* ptr)
{
	
}