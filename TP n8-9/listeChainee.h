#ifndef LISTE_CHAINEE
#define LISTE_CHAINEE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct str_noeud
{
	int info;
	struct str_noeud *suivant;
} noeud;

typedef struct liste_simplement_chainee
{
	noeud *premier_element;
}listeChainee;

noeud* cree_element(int valeur);
void detruire_element(noeud* n);
void detruire_liste_chainee(listeChainee* liste);
listeChainee* initialisation(int valeur);
void afficher(listeChainee* liste);
noeud* acceder_element(int indice);

#endif