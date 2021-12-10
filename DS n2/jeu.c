#include "jeu.h"

struct carte* jeu_de_cartes()
{
	struct carte* jeu_cree;

	jeu_cree = malloc(32 * sizeof(struct carte));
	assert(jeu_cree != NULL);

	//on decide de creer ce jeu trie
	for(int i = Coeur; i <= Trefle ; i++)
	{
		for(int j = Sept; j <= As; j++)
		{
			jeu_cree[i * 8 + j].valeur = (enum valeur_e)j;
			jeu_cree[i * 8 + j].couleur = (enum couleur_e)i;
		}
	}

	return jeu_cree;
}

void affiche_jeu(int n_cartes, struct carte* jeu)
{
	for(int i = 0; i < n_cartes ; i++)
	{
		printf("%s de %s\n", chaines_valeur[jeu[i].valeur], chaines_couleur[jeu[i].couleur]);
	}
}

void melange_jeu(struct carte* jeu)
//on melange le jeu entier uniquement, donc de 32 cartes
{
	int maxi = 31;
	int mini = 0;
	struct carte temp;
	int carte1, carte2;

	for(int i = 0; i < 32; i++)
	{
		carte1 = (rand() % maxi - mini) + mini;
		carte2 = (rand() % maxi - mini) + mini;

		temp = jeu[carte1];
		jeu[carte1] = jeu[carte2];
		jeu[carte2] = temp;
	}
}

struct carte** donne(int joueurs, int cartes, struct carte* jeu)
{
	int cartes_a_donner = cartes - (cartes % joueurs);
	struct carte** liste_de_mains;

	liste_de_mains = (struct carte**)malloc(joueurs * sizeof(struct carte * ));
	assert(liste_de_mains != NULL);
	for(int i = 0; i < joueurs ; i++)
	{
		liste_de_mains[i] = (struct carte*)malloc((cartes_a_donner / joueurs) * sizeof(struct carte));
		assert(liste_de_mains[i] != NULL);
	}

	for(int i = 0; i < cartes_a_donner; i++)
	{
		liste_de_mains[i % joueurs][i / joueurs] = jeu[i];
	}
	return liste_de_mains;
}
//selon le nombre de joueurs, il est possible aue la main soit vide.