/*
DS 2
Emile BONDU
09/12/2021
reecriture de mon code
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "jeu.h"

int main()
{
	struct carte* jeu_complet;
	struct carte** mains_joueurs;

	int joueurs = 5; //pas un multiple de 32 pour verifier
	//qu'on ne distribue bien que 30 cartes

	srand(time(NULL));

	jeu_complet = jeu_de_cartes();
	assert(jeu_complet != NULL);

	printf("Jeu non melange :\n");
	printf("-----------------\n");
	affiche_jeu(32, jeu_complet);
	printf("\n");

	melange_jeu(jeu_complet);

	printf("Jeu melange :\n");
	printf("-------------\n");
	affiche_jeu(31, jeu_complet);
	//teste la limite de l'affichage
	printf("\n");

	mains_joueurs = donne(joueurs, 31, jeu_complet);

	for(int i = 0; i < joueurs ; i++)
	{
		printf("Main du %de joueur :\n", i + 1);
		printf("--------------------\n");
		affiche_jeu(6, mains_joueurs[i]);
		//les jeux ne font que 6 cartes
		printf("\n");
	}
	//on peut ainsi verifier que la distibution est acceptable

	free(jeu_complet);
	for(int i = 0; i < joueurs; i++)
	{
		free(mains_joueurs[i]);
	}
	free(mains_joueurs);

	return 0;
}