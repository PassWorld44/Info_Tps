/*
Colle 1
Emile BONDU
8/11/2021
repartition de parite
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void testParite(int tableau[10], int pair[10], int impair[10], int* nPair, int* nImpair, int indiceTab);

void AffichageTab(int tableau[10], int taille);

int main()
{
	//initialisation
	int tableau[10];
	int pair[10];
	int impair[10];
	int mini = 0, maxi = 100;
	int indice = 0;
	int nPair = 0;
	int nImpair = 0;

	//affectation de valeurs aleatoires pour tableau
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
	{
		tableau[i] = ((rand() % (maxi - mini +1)) + mini);
	}

	//repartition des valeurs de partie dans 'pair' et 'impair'
	
	//============= Methode 1 : avec une boucle for =======================
	for(int i = 0; i < 10; i++)
	{
		testParite(tableau, pair, impair, &nPair, &nImpair, i);
	}
    
	//Methode 2 : avec une boucle while
	//on "simule" une boucle for
	indice = 0;
	nPair = 0;
	nImpair = 0;
	while(indice < 10)
	{
		testParite(tableau, pair, impair, &nPair, &nImpair, indice);

		indice++;
	}
	
	//====================== Methode 3: avec une boucle do/while ===========
	
	indice = 0;
	nPair = 0;
	nImpair = 0;
	do
	{
		testParite(tableau, pair, impair, &nPair, &nImpair, indice);

		indice++;
	} while(indice < 10);
	
	//====================affichage============================
	printf("Nombres Pairs :\n");
	AffichageTab(pair, nPair);

	printf("Nombres Impairs :\n");
	AffichageTab(impair, nImpair);
	
	printf("Tableau de depart :\n");
	AffichageTab(tableau, 10);

	return 0;
}

void testParite(int tableau[10], int pair[10], int impair[10], int* nPair, int* nImpair, int indiceTab)
{
    if(tableau[indiceTab] % 2 == 0) //le chiffre est pair
	{
		//on utilise la case d'indice i comme case libre
		pair[*nPair] = tableau[indiceTab];
		(*nPair)++;
	}
	else //le nombre est impair
	{
		impair[*nImpair] = tableau[indiceTab];
		(*nImpair)++;
	}
}

void AffichageTab(int tab[10], int taille)
{
    for(int i = 0;  i < taille ; i++)
	{
		printf("%d\t", tab[i]);
	}
	printf("\n");
} 

