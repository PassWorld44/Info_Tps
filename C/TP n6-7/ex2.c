/*
TP6 - ex2
Emile BONDU
26/11/2021
pointeurs
*/

#include <stdio.h>

void convertirViaPointeurs(int* jours, int* heures, 
						  int* minutes, int* secondes, int tempsEnSec);

void convertirViaTableaux(int tab[4], int tempsEnSec);

int main()
{
	int nbSecondes = 0;
	int jours, heures, minutes, secondes;
	int tempsConverti[4];

	printf("Nombre de secondes a convertir : ");
	scanf( "%d", &nbSecondes);

	printf("\n\n");
	printf("PREMIERE SOLUTION : 4 POINTEURS\n");
	printf("-------------------------------\n");
	convertirViaPointeurs(&jours, &heures, &minutes, &secondes, nbSecondes);
	printf("nbre de jours : %d\n", jours);
	printf("nbre d'heures : %d\n", heures);
	printf("nbre de minutes : %d\n", minutes);
	printf("nbre de secondes : %d\n", secondes);

	printf("\n\n\n");
	jours = 0;
	heures = 0;
	minutes = 0;
	secondes = 0;
	//on reinitialise les valeurs pour verifier qu'on a pas 
	//	d'interferences avec les anciennes valeurs

	printf("SECONDE SOLUTION : TABLEAU\n");
	printf("-------------------------------\n");
	convertirViaTableaux(tempsConverti, nbSecondes);
	printf("nbre de jours : %d\n", tempsConverti[3]);
	printf("nbre d'heures : %d\n", tempsConverti[2]);
	printf("nbre de minutes : %d\n", tempsConverti[1]);
	printf("nbre de secondes : %d\n", tempsConverti[0]);
	return 0;
}

void convertirViaPointeurs(int* jours, int* heures, 
						  int* minutes, int* secondes, int tempsEnSec)
{
	*secondes = tempsEnSec % 60; 
	//le reste d'une division par 60 est le nb de secondes
	tempsEnSec /= 60; //on a donc le nombre de minutes

	*minutes = tempsEnSec % 60;
	tempsEnSec /= 60; // on a ici le nombre d'heures

	*heures = tempsEnSec % 24;
	tempsEnSec /= 24; // on a ici le nombre de jours

	*jours = tempsEnSec; 
}

void convertirViaTableaux(int tab[4], int tempsEnSec)
//la methode de convertion est la meme que pour convertirViaPointeurs
//valeurs du tableau :
// tab[0] : secondes
// tab[1] : minutes
// tab[2] : heures
// tab[3] : jours
{
	tab[0] = tempsEnSec % 60;
	tempsEnSec /= 60;

	tab[1] = tempsEnSec % 60;
	tempsEnSec /= 60;

	tab[2] = tempsEnSec % 24;
	tempsEnSec /= 24;

	tab[3] = tempsEnSec; 
}