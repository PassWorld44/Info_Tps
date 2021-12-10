#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum couleur_e { Coeur, Carreau, Pique, Trefle };
enum valeur_e { Sept, Huit, Neuf, Dix, Valet, Dame, Roi, As };

struct carte
{
	enum couleur_e couleur;
	enum valeur_e valeur;
};

struct jeu
{
	int n_cartes;
	struct carte * cartes;
};

//permet un affichage standardise
char static *chaines_couleur[4] = {"Coeur", "Carreau", "Pique", "Trefle" };
char static *chaines_valeur[8] = { "7", "8", "9", "10", "Valet", "Dame", "Roi", "As" };

//fonctions
void affiche_jeu(int n_cartes, struct carte* jeu);
void melange_jeu(struct carte* jeu);
struct carte* jeu_de_cartes();
struct carte** donne(int joueurs, int cartes, struct carte* jeu);


#endif