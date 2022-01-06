#include "listeChainee.h"

noeud* cree_element(int valeur)
//si la creation d'un noeud a echouee, le pointeur retourne sera NULL
{
	noeud* noeud_cree = NULL;

	noeud_cree = (noeud *)malloc(sizeof(noeud));

	if(noeud_cree != NULL)
	{
		noeud_cree->info = valeur;
		noeud_cree->suivant = NULL;
	}

	return noeud_cree;
}

void detruire_element(noeud* n)
//Attention : cette fonction detruit aussi les noeuds 
//	avec lequels elle est liée
{
	if(n->suivant)
	{
		detruire_element(n->suivant);
	}
	free(n);
}

void detruire_liste_chainee(listeChainee* liste)
{
	detruire_element(liste->premier_element);
	free(liste);
}

listeChainee* initialisation(int valeur)
//peut renvoyer NULL si l'alloc dynamique a echoue,
//valeur a verifier a l'arrivee
{
	listeChainee* liste = NULL;
	liste = (listeChainee*)malloc(sizeof(listeChainee));

	if(liste != NULL)
	{
		liste->premier_element = cree_element(valeur);
		assert(liste->premier_element != NULL);
	}

	return liste;
}

void afficher(listeChainee* liste)
{
	noeud* aux = NULL;
	aux = liste->premier_element;
	printf("[");
	while(aux != NULL)
	{
		if(aux->suivant == NULL)
		{	
			printf("%d", aux->info);
		}
		else
		{
			printf("%d, ", aux->info);
		}
		aux = aux->suivant;
	}
	printf("]\n");
}

noeud* acceder_element(listeChainee* liste, int indice)
//si l'indice n'est pas accessible, on retournera NULL
{
	noeud* aux = liste->premier_element;

	for(int i = 0; i < indice; i++)
	{
		if(aux->suivant == NULL)
		{
			//on a pas trouve l'element pointe
			return NULL;
		}
		aux = aux->suivant;
	}
	return aux;
}

int insere_noeud(listeChainee* liste, int indice, noeud* elem)
//val de retour : -1 si l'insertion a echouee
//				  0 si l'insertion a ete effectuee avec succes
{
	noeud* it = acceder_element(liste, indice - 1);

	if(it == NULL)
	{
		return -1;
	}
	
	elem->suivant = it->suivant;
	it->suivant = elem;

	return 0;
}

int suppr_noeud(listeChainee* liste, int indice)
//val de retour : -1 si l'insertion a echouee
//				  0 si l'insertion a ete effectuee avec succes
{
	noeud** precedent;
	noeud* elem;

	//il faut aussi changer le pointeur qui va vers
	//l'element a supprimer
	if(indice - 1 >= 0)
	{
		precedent = &acceder_element(liste, indice-1)->suivant;
	}
	else
	{
		precedent = &(liste->premier_element);
	}

	elem = *precedent;

	if(elem == NULL)
	{
		return -1;
	}

	*precedent = elem->suivant;

	free(elem);

	return 0;
}