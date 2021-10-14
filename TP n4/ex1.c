/*
TP4 - ex1
Emile BONDU
14/10/2021
Scores des Jo d'escalade
*/

#include <stdio.h>
#include <string.h>

typedef struct athlete
{
	//infos grimpeurs
	char nom         [20];
	char premon      [20];
	char nationalite [5];

	//infos performance, une par epreuve
	int bloc;
	int vitesse;
	int difficulte;

	int total;
 	
} grimpeur;

//affichage des gimpeurs
void affichage(grimpeur liste[5]);

//tri dans l'ordre croissant
void tri(grimpeur liste[5]);

int main()
{
	//initialisation des grimpeurs
	grimpeur escalade [5] = 
	{
	  {"Narasaki", "Tomoa",     "jap",   3, 2, 6},
	  {"Mawen",    "Mickael",   "fr",    2, 3, 7},
	  {"Colename", "Nathaniel", "usa",   1, 6, 5},
      {"Schubert", "Jakob",     "aut",   5, 7, 1},
	  {"Lopez",    "Alberto",   "esp",   7, 1, 4} };

	//initialisation des totaux
	for(int i = 0; i < 5; i++)
	{
		//le score correspond aux scores multiplies entre eux
		escalade[i].total = escalade[i].bloc * escalade[i].vitesse * escalade[i].difficulte;
	}
	
    affichage(escalade);

	return 0;
}

void affichage(grimpeur liste[5])
{
	printf("SCORES ESCALADE\n");
	printf("---------------\n");
	printf("\n");

	//affichage d'un des gimpeurs dans un tableau
	printf("%-20s%-20sNat \tBloc \tVit \tDif \tTotal\n", "Nom", "Premon");
	for(int i = 0; i < 5; i++)
	{
		printf("%-20s", liste[i].nom);
		printf("%-20s", liste[i].premon);
		printf("%s\t", liste[i].nationalite);
		printf("%d\t", liste[i].bloc);
		printf("%d\t", liste[i].vitesse);
		printf("%d\t", liste[i].difficulte);
		printf("%d\n", liste[i].total);
	}
}

void tri(grimpeur liste[5])
{
	for(int i = 0; i < 5; i++)
	{
		grimpeur aux = liste[i];
		j = i;
		//tric selon le total des points
		while(j > 0 && liste[j - 1].vitesse > aux.vitesse)
		{
			liste[j] = liste[j - 1];
			j--;
		}
		liste[j] = aux;
	}
}