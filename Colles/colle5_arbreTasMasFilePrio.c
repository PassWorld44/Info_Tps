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
	void* elem; //element associé a cette clé, optionel
	int cle;
} NoeudTas ;

typedef struct strTas
{
	int longeur;
	NoeudTas* tab;
	//tab[0].cle stoque la taille utilisée
	//aucun element lui est associé
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

int taille_tas(Tas t)
//retourne la taille d'un tableau
//assert si le tas lié est cassé
{
	assert(t.tab != NULL && 
		"taille_tas : le tas donné n'a pas de tableau lié");

	return t.tab[0].cle;
}

void echanger(Tas t, int i1, int i2)
//échange deux elements d'un tas
{
	assert(t.tab != NULL && 
		"echanger : le tas donné n'a pas de tableau lié");
	
	int temp = t.tab[i1].cle;
	void* temp2 = t.tab[i1].elem;
	
	t.tab[i1].cle = t.tab[i2].cle;
	t.tab[i2].cle = temp;

	t.tab[i1].elem = t.tab[i2].elem;
	t.tab[i2].elem = temp2;
}


void affiche_tas(Tas t)
//affichage par ligne
//assert si le tas lié est cassé
{
	assert(t.tab != NULL && 
		"affiche_tas : le tas donné n'a pas de tableau lié");
	for(int i = 1; i <= taille_tas(t); i++)
	{
		printf("%d ", t.tab[i].cle);
	}
	printf("\n");
}

void affiche_tab_tas(Tas t)
//assert si le tas lié est cassé
//affiche le tableau lié
{
	assert(t.tab != NULL && 
		"affiche_tab_tas : le tas donné n'a pas de tableau lié");
	for(int i = 0; i <= t.longeur; i++)
	{
		printf("%d ", t.tab[i].cle);
	}
	printf("\n");
}

int* tas_get_tab_cle(Tas t)
//cree un tableau (alloue dynamiquement) avec les cles
//des differents indices
{
	assert(t.tab != NULL && 
		"tas_get_tab_cle : le tas donné n'a pas de tableau lié");

	int* tab = NULL;

	tab = (int*)malloc(t.longeur * sizeof(int));
	assert(t.tab != NULL &&
		"tas_get_tab_cle : echec d'allocation");

	for(int i = 1; i <= taille_tas(t); i++)
	{
		tab[i - 1] = t.tab[i].cle;
	}
	return tab;
}

void entasser_max(Tas t, int i)
//Permet de verifier localement la propirité tournoi pour un tas
//assert si le tas lié est cassé
//
//Complexité : O(ln(n))
{
	assert(t.tab != NULL && 
		"entasser_max : le tas donné n'a pas de tableau lié");
	
	int l = tas_iGauche(i);
	int d = tas_iDroit(i);
	int max, temp;

	if(l <= taille_tas(t) && t.tab[i].cle < t.tab[l].cle )
		max = l;
	else
		max = i;

	if(d <= taille_tas(t) && t.tab[max].cle < t.tab[d].cle)
		max = d;

	if( max != i )
	{
		echanger(t, i, max);

		entasser_max(t, max);
		//on continue du faire descendre dans le tas 
		//un eventuel element trop petit
	}
}

Tas construire_tas_max(int *t, int taille, int longeur)
//transforme un tableau reçu en entrée en tas max
//le tableau est celui des étiquettes
//si longeur est modifié, plus d'espace memoire sera alloue 
// (de la taille de max(taille, longeur))
//
//assert si le tas lié est cassé
//
//Complexité : O(n*ln(n))
{
	Tas tas;

	tas.longeur = max(taille, longeur);
	tas.tab = (NoeudTas*)malloc(
				sizeof(NoeudTas) * (tas.longeur + 1));
	assert(tas.tab != NULL && 
		"construire_tas_max : l'alloncation a echouee");

	tas.tab[0].cle = taille;
	for(int i = 1 ; i <= taille ; i++)
	{
		tas.tab[i].cle = t[i-1];
	}
	
	for(int i = taille_tas(tas) / 2 + 1 ; i > 0; i--)
	{
		entasser_max(tas, i);
	}

	return tas;
}

Tas detruire_tas_max(Tas t)
//assert si le tas lié est déja cassé
{
	assert(t.tab != NULL && 
		"detruire_tas_max : le tas donné n'a pas de tableau lié");
	for(int i = 1; i <= taille_tas(t) ; i++)
	{
		if(t.tab[i].elem != NULL)
			free(t.tab[i].elem);
	}
	free(t.tab);
}

int* tri_par_tas(int *tab, int taille)
//super tri en place
//tableau renvoye alloue dynamiquement
// O(n*ln(n))
{
	Tas t = construire_tas_max(tab, taille, taille);
	
	for(int i = taille; i > 1 ; i--)
	{
		echanger(t, 1, i);
		t.tab[0].cle--;
		//on reduit virtuellement la taille du tableau
		//pour entasser sans prendre en compte les elements déja triés

		entasser_max(t, 1);
	}
	t.tab[0].cle = t.longeur;
	
	return tas_get_tab_cle(t);
}


int main()
{
	int *tab = NULL;
	int taille = 10;
	Tas t;
	int *tab_trie = NULL;

	tab = (int*)malloc( (taille + 1) * sizeof(int*));
	assert(tab != NULL && "allocation echouee");
	for(int i = 0; i < taille; i++)
	{
		tab[i] = i;
	}

	t = construire_tas_max(tab, taille, taille);

	affiche_tas(t);
	tab_trie = tri_par_tas(tab, taille);

	for(int i = 0; i < taille; i++)
	{
		printf("%d ", tab_trie[i]);
	}
	printf("\n");

	detruire_tas_max(t);
	free(tab_trie);
	free(tab);
	
	return 0;
}