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
void detruire_element(noeud *n);
noeud* copie_element(noeud *n);

void detruire_liste_chainee(listeChainee* liste);
listeChainee* initialisation(int valeur);
int copie_liste(listeChainee lst, listeChainee *copie);

void afficher(listeChainee liste);
int longueur_liste(listeChainee lst);
int recherche_valeur(listeChainee liste, int valeur);

noeud* acceder_element(listeChainee* liste, int indice);
int insere_noeud(listeChainee* liste, int indice, noeud* element);
int suppr_noeud(listeChainee* liste, int indice);

#endif