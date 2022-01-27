/*
TP8-9
Emile BONDU
17/12/2021
listes chainees
code de test des differentes fonctions
*/

#include <stdio.h>
#include <stdlib.h>
#include "listeChainee.h"

int main()
{
	listeChainee *liste, *liste2;

	liste = initialisation(42);
	afficher(*liste);

	insere_noeud(liste, 1, cree_element(17));
	insere_noeud(liste, 2, cree_element(14));
	insere_noeud(liste, 1, cree_element(4));
	afficher(*liste);

	suppr_noeud(liste, 2);
	afficher(*liste);
	printf("taille : %d\n", longueur_liste(*liste));
	printf("indice du 14 : %d\n", 
			recherche_valeur(*liste, 14));
	printf("indice du 18 : %d\n", 
			recherche_valeur(*liste, 18));

	liste2 = (listeChainee*)malloc(sizeof(listeChainee));

	copie_liste(*liste, liste2);
	afficher(*liste2);

	detruire_liste_chainee(liste);
	detruire_liste_chainee(liste2);

	return 0;
}
