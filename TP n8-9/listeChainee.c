#include "listeChainee.h"

noeud* cree_element(int valeur)
//crée un noeud avec la valeur demandée
//si la creation d'un noeud a echouee, 
//	le pointeur retourne sera NULL
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

noeud* copie_element(noeud *n)
//crée un noeud similaire au 1er, 
//		sans pointeur suivant
//peut retourner un NULL en cas d'echec
{
	noeud* noeud_cree = cree_element(n->info);

	return noeud_cree;
}

void detruire_liste_chainee(listeChainee* liste)
//detruit une liste chainee proprement
//ATTENTION : il faut utiliser cette fonction 
//	pour detruire une liste
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

int copie_liste(listeChainee liste, listeChainee *copie)
//retourne NULL si echec de creation de la liste
//retourne -1 si echec de copie des differents elements
// -> la liste peut y etre tronquée
{
	noeud* aux = liste.premier_element;
	noeud** next = NULL;

	copie = (listeChainee*)malloc(sizeof(listeChainee));

	if(copie != NULL)
	{
		next = &liste.premier_element;

		while(aux != NULL)
		{
			*next = copie_element(aux);

			if(*next == NULL)
			//echec de la creation totale
			{
				return -1;
			}

			next = &(*next)->suivant;
			aux = aux->suivant;
		}
	}

	return 0;
}

void afficher(listeChainee liste)
//affiche la liste (format python)
{
	noeud* aux = NULL;
	aux = liste.premier_element;
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

int longueur_liste(listeChainee lst)
//retourne le nombre d'elements dans cette liste
{
	noeud* aux = NULL;
	int taille = 0;
	aux = lst.premier_element;
	while(aux != NULL)
	{
		taille++;
		aux = aux->suivant;
	}

	return taille;
}

int recherche_valeur(listeChainee liste, int valeur)
//retourne la 1ere occurence de la valeur demandée
//retourne -1 si aucune occurence a été trouvée
{
	noeud* aux = liste.premier_element;
	int compteur = 0;

	while(aux != NULL)
	{
		if(aux->info == valeur)
		{
			return compteur;
		}
		compteur++;
		aux = aux->suivant;
	}

	//on a pas trouvé d'occurences
	return -1;
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