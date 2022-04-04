/*
Colle 2
Emile BONDU
26/11/2021
tableau de structures
*/

#include <stdio.h>
#include <string.h>

typedef struct pers
{
	char nom[20];
	char prenom[20];
	int age;

}joueuse;

joueuse creation_joueuse();
void affichage_joueuses(joueuse tab[20], int size);
void affectation_joueuses(joueuse tab[20]);

int main()
{
	//initialisation
	joueuse listeJoueuse[15];
	int n = 7;

	//creation du tableau
	/*
	Code enleve suite a un bug d'entree
	for(int i = 0; i < n; i++)
	{
		listeJoueuse[i] = creation_joueuse();
	}
	*/ 
	affectation_joueuses(listeJoueuse);

	
	affichage_joueuses(listeJoueuse, n);

	//changement de joueur en millieu de match
	//recherche dans le tableau necessaire
	for(int i = 0; i < n; i++)
	{
		if(strcmp(listeJoueuse[i].nom,    "Leynaud") && 
		   strcmp(listeJoueuse[i].prenom, "Clementine")  )
		{
			joueuse rp = {"Darleux", "Amandine", 32};
			listeJoueuse[i] = rp;
		}
	}

	printf("\n");
	printf("composition de l'equipe apres le changement : \n");
	printf("\n");
	affichage_joueuses(listeJoueuse, n);

	return 0;
}

joueuse creation_joueuse()
//bug d'entree, si demande plusieurs fois passe le 2e nom et tout les ages apres le 1er
{
	joueuse j;
	
	//Entree utulisateur pour l'initialisation des champs
	printf("Entrer les nom, prenom et age de la joueuse : \n");
	gets(j.nom);
	gets(j.prenom);
	fflush(stdin);
	scanf("%d", &j.age);
	fflush(stdin);

	return j;
}

void affichage_joueuses(joueuse tab[20], int size)
//on affiche la liste des joueuses de hand en une seule fois
{
	printf("Equipe de hand feminine, JO 2021 : \n");
	for(int i = 0; i < size; i++)
	{
		printf("%-20s  %-20s  %d ans\n", tab[i].nom, tab[i].prenom, tab[i].age);
	}
}

void affectation_joueuses(joueuse tab[20])
{
	joueuse j0 = {"Lassource", "Coralie" , 29 };
	joueuse j1 = {"Pineau"   , "Allison" , 32 };
	joueuse j2 = {"NzeMinko" , "Estelle" , 30 };
	joueuse j3 = {"Foppa"    , "Estelle" , 20 };
	joueuse j4 = {"Fillipes" , "Laura"   , 26 };
	joueuse j5 = {"Leynaud"  , "Amandine", 35 };
	joueuse j6 = {"Zaadi"    , "Grace"   , 28 };
	tab[0] = j0;
	tab[1] = j1;
	tab[2] = j2;
	tab[3] = j3;
	tab[4] = j4;
	tab[5] = j5;
	tab[6] = j6;
}