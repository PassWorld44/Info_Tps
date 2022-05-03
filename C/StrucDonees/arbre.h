/*
Emile BONDU
04/04/2022
Arbre binaire de recherche
*/

#ifndef ARBRE_RECHERCHE
#define ARBRE_RECHERCHE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Noeud
{
	int cle;
	struct Noeud *gauche, *droit;
	struct Noeud *parent;
} noeud;

typedef struct Arbre
{
	noeud* racine;
}arbre;

noeud* creer_noeud(int valeur);
//retourne un noeud dont la cle sera egale a la valeur passe en param
//retourne NULL si l'alloc a echouee
void detruire_noeud(noeud* n);

arbre* creer_arbre();
//retourne un arbre initialise avec une racine NULL
//retourne NULL si l'alloc a echoue
void detruire_arbre(arbre *abr);

void inserer_noeud(arbre *abr, noeud *nouveau);
//on insere le noeud nouveau comme feuille dans abr
noeud* rechercher_cle(arbre *abr, int valeur);
//precondition : abr != NULL
//retourne NULL si la valeur n'est pas dans l'arbre
noeud* rechercher_cle_rec(noeud *abr, int valeur);
//precondition : abr != NULL

int hauteur_arbre(noeud *elt);
int taille_arbre(noeud *elt);

void affiche_arbre_prefixe(noeud* elt);
void affiche_arbre_infixe(noeud* elt);
void affiche_arbre_postfixe(noeud* elt);

void tests_unitaire_arbre();

#endif