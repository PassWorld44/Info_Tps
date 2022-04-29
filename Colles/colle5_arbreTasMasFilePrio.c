/*
Colle 5
Emile BONDU
04/04/2022
Arbres, tas et file de priorité
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

typedef struct strNoeudTas
{
	void* elem; //element associé a cette clé
	int cle;
} NoeudTas ;

typedef struct strTas
{
	int longeur;
	NoeudTas* tab;
	//tab[0].cle stoque la taille utulisée
} Tas;

int tas_getParent(int i)
//retourne l'indice du parent
{
	return i/2;
}

int tas_iDroit(int i)
//retourne l'indice du fils droit
//peut retourner un indice en dehors du tas
{
	return 2 * i + 1;
}

int tas_iGauche(int i)
//retourne l'indice du fils gauche
//peut retourner un indice en dehors du tas
{
	return 2 * i;
}

int tas_taille(Tas t)
//retourne la taille d'un tableau
//assert si le tas lié est cassé
{
	assert(t.tab != NULL && 
		"tas_taille : le tas donné n'a pas de tableau lié");

	return t.tab[0].cle;
}

void entasserMax(Tas t, int i)
//Permet de verifier localement la propirité tournoi pour un tas
//assert si le tas lié est cassé
{
	assert(t.tab != NULL && 
		"entasserMax : le tas donné n'a pas de tableau lié");
	
	int l = tas_iGauche(i);
	int d = tas_iDroit(i);
	int max, temp;

	if(l <= tas_taille(t) && t.tab[i].cle < t.tab[l].cle )
		max = l;
	else
		max = i;

	if(d <= tas_taille(t) && t.tab[max].cle < t.tab[d].cle)
		max = d;

	if( max != i )
	{
		//on échange t.tab[i] et t.tab[max]
		temp = t.tab[i].cle;
		t.tab[i].cle = t.tab[max].cle;
		t.tab[max].cle = temp;

		entasserMax(t, max);
		//on continue du faire descendre dans le tas 
		//un eventuel element trop petit
	}
}

Tas construireTasMax(int *t, int taille, int longeur)
//transforme un tableau reçu en entrée en tas max
//le tableau est celui des étiquettes
//si longeur est modifié, plus d'espace memoire sera alloue 
// (de la taille de max(taille, longeur))
//
//assert si le tas lié est cassé
{
	Tas tas;

	tas.longeur = max(taille, longeur);
	tas.tab = (NoeudTas*)malloc(
				sizeof(NoeudTas) * (tas.longeur + 1));
	assert(tas.tab != NULL && 
		"construireTasMax : l'alloncation a echouee");

	tas.tab[0].cle = taille;
	for(int i = 1 ; i <= taille ; i++)
	{
		tas.tab[i].cle = t[i-1];
	}
	
	for(int i = tas_taille(tas) / 2 + 1 ; i > 0; i--)
	{
		entasserMax(tas, i);
	}

	return tas;
}

Tas detruireTasMax(Tas t)
//assert si le tas lié est déja cassé
{
	assert(t.tab != NULL && 
		"detruireTasMax : le tas donné n'a pas de tableau lié");
	for(int i = 1; i <= tas_taille(t) ; i++)
	{
		if(t.tab[i].elem != NULL)
			free(t.tab[i].elem);
	}
	free(t.tab);
}

void afficheTas(Tas t)
//affichage par ligne
//assert si le tas lié est cassé
{
	assert(t.tab != NULL && 
		"afficheTas : le tas donné n'a pas de tableau lié");
	for(int i = 1; i <= tas_taille(t); i++)
	{
		printf("%d ", t.tab[i].cle);
	}
	printf("\n");
}

void afficheTabTas(Tas t)
//assert si le tas lié est cassé
//affiche le tableau lié
{
	assert(t.tab != NULL && 
		"afficheTas : le tas donné n'a pas de tableau lié");
	for(int i = 0; i <= t.longeur; i++)
	{
		printf("%d ", t.tab[i].cle);
	}
	printf("\n");
}

int main()
{
	int *tab = NULL;
	int taille = 10;
	Tas t;

	tab = (int*)malloc( (taille + 1) * sizeof(int*));
	assert(tab != NULL && "allocation echouee");
	for(int i = 0; i < taille; i++)
	{
		tab[i] = i;
	}

	t = construireTasMax(tab, taille, taille);

	afficheTas(t);

	detruireTasMax(t);
	
	return 0;
}