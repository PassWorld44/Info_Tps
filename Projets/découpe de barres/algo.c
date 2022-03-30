/*
découpe de barres
Emile BONDU
24/03/2022
les algos en c
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

//découpe naïve :

int coupe_naive_prix(int n, int *tabPrix, int taille)
{
	assert(n <= taille && "taille du tableau non correcte");
	
	int maxi = tabPrix[n - 1];
	
	if ( n == 1)
		return tabPrix[0];
	if ( n==0)
		return 0;
	for (int i = 0 ; i < n - 1 ; i++)
	{
		
		maxi = max(maxi, coupe_naive_prix(i + 1, tabPrix, taille) 
				+ coupe_naive_prix(n - 1 - i, tabPrix, taille));
	}
	return maxi;
}

int coupe_prix(int n, int *tabPrix, int taille)
//précondition : n <= taille
//Amelioration possibles : 
//- on pourrait éventuellement stoquer ce tableau qqpart au 
//		lieu de tout recalculer a chaque fois
{
	int *r = (int*)malloc(sizeof(int) * n);
	int rn;
	assert(r != NULL && "probleme d'allocation");

	for(int i = 0; i < n ; i++)
	{
		rn = tabPrix[i];
		for(int j = 0; j < i; j++)
		{
			
			rn = max(rn, r[j] + r[i - 1 - j]);
			//on recupère toutes les combinaisons possibles
		}
		r[i] = rn;
	}

	rn = r[n - 1];
	free(r);
	
	return rn;
}

// =============================== AVEC LES COUPES ========================

//on adapte tout donc on refait des fonctions pratiques replaçant celles "usuelles" 
typedef struct info
{
	int prix;
	int *tabCoupe; //A initialiser a chaque fois, permet d'avoir un prix libre
} coupe;

coupe init_coupe(int taille)
{
	int *r = (int*)malloc(sizeof(int) * taille);
	assert(r != NULL && "probleme d'allocation");

	coupe c;
	c.prix = 0;
	c.tabCoupe = r;
	for(int i = 0; i < taille ; i++)
	{
		c.tabCoupe[i] = 0;
	}

	return c;
}

void detruit_coupe(coupe *c)
//on peut passer en copie, seul le pointeur a liberer est important
{
	if(c->tabCoupe != NULL)
	{
		free(c->tabCoupe);
		c->tabCoupe = NULL;
		c->prix = -1; //permet d'identifier les erreurs
	}
	else
		printf("erreur : deux frees, %d\n", c->prix);
}

void affiche_coupe(coupe c, int taille)
{
	printf("%d : ", c.prix);
	if(c.tabCoupe == NULL)
	{
		printf("Erreur : tableau déja vidé\n");
	}
	else
	{
		printf("[");
		for(int i = 0; i < taille; i++)
		{
			printf("%d, ", c.tabCoupe[i]);
		}
		printf("]\n");
	}
}

coupe max_coupe(coupe *c1, coupe *c2)
//on détruit ici le minimum qui ne sera plus utulisé
{
	if (c1->prix > c2->prix)
		detruit_coupe(c2);
		return *c1;
	detruit_coupe(c1);
	return *c2;
}

coupe copie_coupe(coupe c1, int taille)
//il faut copier le tableau a l'interieur pour éviter du 
//	partage de mémoire
{
	coupe c2 = init_coupe(taille);

	assert(c1.tabCoupe != NULL && "on tente de copier un tableau déja vide");
	c2.prix = c1.prix;
	for(int i = 0; i < taille ; i++)
	{
		c2.tabCoupe[i] = c1.tabCoupe[i];
	}

	return c2;
}

coupe add_coupe(coupe c1, coupe c2, int taille)
{
	coupe c3 = init_coupe(taille);

	c3.prix = c2.prix + c1.prix;
	for(int i = 0; i < taille; i++)
	{
		c3.tabCoupe[i] = c1.tabCoupe[i] + c2.tabCoupe[i];
	}

	return c3;
}

coupe coupe_naive_infos(int n, int *tabPrix, int taille)
//ne semble pas marcher pour n >= 4 ?
{
	assert(n <= taille && "taille du tableau non correcte");
	
	coupe maxi =  init_coupe(taille);
	coupe c1, c2, somme;

	//printf("\t%d\n ", n);
	
	if ( n == 1)
	{
		maxi.prix = tabPrix[0];
		maxi.tabCoupe[0] = 1;
		return maxi;
	}
	if( n == 0)
		return maxi; //il est initialisé a 0
	maxi.prix = tabPrix[n - 1];
	maxi.tabCoupe[n - 1] = 1;
	
	for (int i = 0 ; i < n - 1 ; i++)
	{
		c1 = coupe_naive_infos(i + 1, tabPrix, taille);
		c2 = coupe_naive_infos(n - 1 - i, tabPrix, taille);
		somme = add_coupe(c1, c2, taille);
		
		maxi = copie_coupe( max_coupe(&maxi,  &somme), taille );
		//affiche_coupe(maxi, taille);
		
		detruit_coupe(&c1);
		detruit_coupe(&c2);
	}
	//affiche_coupe(maxi, taille);
	
	return maxi;
}

coupe coupe_infos(int n, int *tabPrix, int taille)
//précondition : n <= taille
//Amelioration possibles : 
//- on pourrait éventuellement stoquer ce tableau qqpart au 
//		lieu de tout recalculer a chaque fois
{
	coupe *r = (coupe*)malloc(sizeof(coupe) * n);
	coupe rn, somme;
	assert(r != NULL && "probleme d'allocation");

	rn = init_coupe(taille);

	for(int i = 0; i < n ; i++)
	{
		rn = init_coupe(taille);
		rn.tabCoupe[i] = 1;
		rn.prix = tabPrix[i];

		for(int j = 0; j < i; j++)
		{
			somme = add_coupe(r[j], r[i - 1 - j], taille);
			
			rn = copie_coupe( max_coupe(&rn, &somme), taille );
			//on recupère toutes les combinaisons possibles
		}
		r[i] = copie_coupe(rn, taille);
		detruit_coupe(&rn);
	}
	
	rn = copie_coupe(r[n - 1], taille);

	for(int i = 0; i < n; i++)
	{
		detruit_coupe(&r[i]);
	}
	free(r);

	return rn;
}

int main ()
{
	int tableau[] ={1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	coupe c1, c2;

	for(int i = 1; i <= 10 ; i++)
	{
		c1 = coupe_naive_infos(i, tableau, 10);
		c2 = coupe_infos(i, tableau, 10);
		
		printf("%d\n",  coupe_prix(i, tableau, 10));
		printf("%d\n",  coupe_naive_prix(i, tableau, 10));
		affiche_coupe(c1, 10);
		affiche_coupe(c2, 10);

		detruit_coupe(&c1);
		detruit_coupe(&c2);
	}
	
	return 0;
}