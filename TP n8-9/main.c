/*
TP8-9
Emile BONDU
17/12/2021
listes chainees
*/

#include <stdio.h>
#include <stdlib.h>
#include "listeChainee.h"

int main()
{
	listeChainee* liste;

	liste = initialisation(42);
	afficher(liste);

	insere_noeud(liste, 1, cree_element(17));
	insere_noeud(liste, 2, cree_element(14));
	insere_noeud(liste, 1, cree_element(4));
	afficher(liste);

	suppr_noeud(liste, 2);
	afficher(liste);

	detruire_liste_chainee(liste);

	return 0;
}
