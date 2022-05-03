/*
Colle 2
Emile BONDU
04/04/2022
Arbre binaire de recherche
*/

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

noeud* creer_noeud(int valeur)
//retourne un noeud dont la cle sera egale a la valeur passe en param
//retourne NULL si l'alloc a echouee
{
	noeud* ptr = (noeud*)malloc(sizeof(noeud));

	if( ptr != NULL )
	{
		ptr->cle = valeur;
		ptr->parent = NULL;
		ptr->gauche = NULL;
		ptr->droit = NULL;
	}

	return ptr;
}

void detruire_noeud(noeud* n)
{
	if(n->gauche !=  NULL)
		detruire_noeud(n->gauche);
	if(n->droit != NULL)
		detruire_noeud(n->droit);
	free(n);
}

arbre* creer_arbre()
//retourne un arbre initialise avec une racine NULL
//retourne NULL si l'alloc a echoue
{
	arbre* ptr = (arbre*)malloc(sizeof(arbre));

	if( ptr != NULL )
		ptr->racine = NULL;

	return ptr;
}

void detruire_arbre(arbre *abr)
{
	if(abr->racine != NULL)
		detruire_noeud(abr->racine);
	free(abr);
}

void inserer_noeud(arbre *abr, noeud *nouveau)
//on insere le noeud nouveau comme feuille dans abr
{
	noeud* tmp = abr->racine;
	bool continuer = true;

	assert(nouveau != NULL && "erreur 0 : le neud donne n'existe pas (NULL)");
	
	if(tmp == NULL)
	//nouveau est la nouvelle racine
	{
		abr->racine = nouveau;
	}
	else
	{
		while(continuer)
		{
			if(nouveau->cle < tmp->cle)
			{
				if(tmp->gauche == NULL)
				{
					tmp->gauche = nouveau;
					continuer = false;
				}
				else
					tmp = tmp->gauche;
			}
			else
			{
				if(tmp->droit == NULL)
				{
					tmp->droit = nouveau;
					continuer = false;
				}
				else
					tmp = tmp->droit;
			}
		}
	}
}

noeud* rechercher_cle(arbre *abr, int valeur)
//precondition : abr != NULL
//retourne NULL si la valeur n'est pas dans l'arbre
{
	assert(abr != NULL && "erreur 1 : l'arbre donné n'existe pas (NULL)");
	
	noeud* temp = abr->racine;

	while(temp != NULL && temp->cle != valeur)
	{
		if(temp->cle < valeur)
			temp = temp->gauche;
		if(temp->cle > valeur)
			temp = temp->droit;
	}

	return temp;
}

noeud* rechercher_cle_rec(noeud *abr, int valeur)
//precondition : abr != NULL
{
	assert(abr != NULL && "erreur 2 : l'arbre donné n'existe pas (NULL)");

	if(abr == NULL || abr->cle == valeur)
		return abr;
	if(abr->cle < valeur)
		return rechercher_cle_rec(abr->gauche, valeur);
	if(abr->cle > valeur)
		return rechercher_cle_rec(abr->droit, valeur);
}

int hauteur_arbre(noeud *elt)
{
	int tailleG, tailleD;
	
	if(elt == NULL)
		return 0;
	//on calcule la hauteur maximale des sous-arbres gauche et droit
	tailleG = hauteur_arbre(elt->gauche) + 1;
	tailleD = hauteur_arbre(elt->droit) + 1;

	if(tailleG < tailleD)
		return tailleD;
	else
		return tailleG;
}

int taille_arbre(noeud *elt)
{
	if(elt == NULL)
		return 0;
	return taille_arbre(elt->gauche) + taille_arbre(elt->droit) + 1;
}

void affiche_arbre_prefixe(noeud* elt)
{
	if(elt != NULL)
	{
		printf("%d ", elt->cle);
		affiche_arbre_prefixe(elt->gauche);
		affiche_arbre_prefixe(elt->droit);
	}
}

void affiche_arbre_infixe(noeud* elt)
{
	if(elt != NULL)
	{
		affiche_arbre_infixe(elt->gauche);
		printf("%d ", elt->cle);
		affiche_arbre_infixe(elt->droit);
	}
}

void affiche_arbre_postfixe(noeud* elt)
{
	if(elt != NULL)
	{
		affiche_arbre_postfixe(elt->gauche);
		affiche_arbre_postfixe(elt->droit);
		printf("%d ", elt->cle);
	}
}

int main()
{
	arbre *r = creer_arbre();

	inserer_noeud(r, creer_noeud(5));
	inserer_noeud(r, creer_noeud(1));
	inserer_noeud(r, creer_noeud(7));
	inserer_noeud(r, creer_noeud(5));

	affiche_arbre_prefixe(r->racine);
	printf("\n");
	affiche_arbre_infixe(r->racine);
	printf("\n");
	affiche_arbre_postfixe(r->racine);
	printf("\n");

	detruire_arbre(r);
	
	return 0;
}