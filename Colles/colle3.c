# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void stringToLowerCases(char * tab, int size);

void main()
{

	char* code[] = {  //encodage des valeurs
		"AAAAA",  /* A */
		"AAAAB",  /* B */
		"AAABA",  /* C */
		"AAABB",  /* D */
		"AABAA",  /* E */
		"AABAB",  /* F */
		"AABBA",  /* G */
		"AABBB",  /* H */
		"ABAAA",  /* I */
		"ABAAA",  /* J */
		"ABAAB",  /* K */
		"ABABA",  /* L */
		"ABABB",  /* M */
		"ABBAA",  /* N */
		"ABBAB",  /* O */
		"ABBBA",  /* P */
		"ABBBB",  /* Q */
		"BAAAA",  /* R */
		"BAAAB",  /* S */
		"BAABA",  /* T */
		"BAABB",  /* U */
		"BAABB",  /* V */
		"BABAA",  /* W */
		"BABAB",  /* X */
		"BABBA",  /* Y */
		"BABBB",  /* Z */};

	char texte_a_coder [6]; //Pour reprendre l'exemple du sujet
	int tailleCode;
	char camouflage[26];

	//char *alpha_min[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	//char *alpha_maj[] = { 'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	char texte_int [26]; //Pour reprendre l'exemple du sujet
	char texte_final[26];

	char texte_int2 [26];
	char texte_decode[26];
	char tampon[6];

	tampon[5] = '\0';


	//--------------------------------------------------------------------------------------------------------
	// ACQUISITION INITIALE
	//--------------------------------------------------------------------------------------------------------
	printf(" Entrer le texte a coder (en minuscules): \t\t");
	scanf("%s" , texte_a_coder);
	//printf("\n");

	printf("Entrer le texte de camouflage (en minuscules): \t");
	scanf("%s" , camouflage);
	printf("\n");

	tailleCode = strlen(texte_a_coder);

	stringToLowerCases(texte_a_coder, tailleCode);
	stringToLowerCases(camouflage, tailleCode * 5);
	//plus de probleme avec d'eventuelles majuscules cassant le code
		
	//--------------------------------------------------------------------------------------------------------
	// CODAGE
	//--------------------------------------------------------------------------------------------------------

	for(int i = 0; i < tailleCode; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			texte_int[ 5*i + j ] = code[ texte_a_coder[i] - 'a' ][j];
		}
	}
	texte_int[tailleCode * 5] = '\0';

	//et on applique les changement sur le code de camouflage
	for(int i = 0; i < tailleCode * 5; i++)
	{
		if(texte_int[i] == 'A')
		//on met en majucule
		{
			texte_final[i] = camouflage[i] - 'a' + 'A';
		}
		else
		//on laisse en minuscules
		{
			texte_final[i] = camouflage[i];
		}
	}
	texte_final[tailleCode * 5] = '\0';

	//--------------------------------------------------------------------------------------------------------
	// GENERATION DE L'AFFICHAGE DE L'ENCODAGE
	//--------------------------------------------------------------------------------------------------------

	printf("CODAGE :\n");
	printf("--------\n");
	printf("\n");
	printf("Texte intermediaire : %s\n", texte_int);
	printf("Texte decode :        %s\n", texte_final);
	printf("\n");
	//printf("%d", tailleCode);

	//--------------------------------------------------------------------------------------------------------
	// DECODAGE
	//--------------------------------------------------------------------------------------------------------

	for(int i = 0; i < tailleCode * 5; i++)
	{
		if(texte_final[i] >= 'A' && texte_final[i] <= 'Z')
		//c'est une majuscule
		{
			texte_int2[i] = 'A';
		}
		else if(texte_final[i] >= 'a' && texte_final[i] <= 'z')
		//c'est une minuscule
		{
			texte_int2[i] = 'B';
		}
	}
	texte_int2[tailleCode * 5] = '\0';

	for(int i = 0; i < tailleCode; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			tampon[j] = texte_int2[ 5*i + j ];
		}

		//il reste plus qu'a trouver la lettre initiale
		for(int j = 0; j < 26; j++)
		{
			if(!strcmp(tampon, code[j]))
			{
				texte_decode[i] = j + 'a';
			}
		}
	}

	//--------------------------------------------------------------------------------------------------------
	// GENERATION DE L'AFFICHAGE DU DECODAGE
	//--------------------------------------------------------------------------------------------------------

	printf("DECODAGE :\n");
	printf("--------\n");
	printf("\n");
	printf("Texte intermediaire : %s\n", texte_int2);
	printf("Texte decode :        %s\n", texte_decode);
	printf("\n");

}

//--------------------------------------------------------------------------------------------------------
// FONCTIONS
//--------------------------------------------------------------------------------------------------------

void stringToLowerCases(char * tab, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(tab[i] >= 'A' && tab[i] <= 'Z')
		//c'est une majuscule, on passe en minuscules
		{
			tab[i] = tab[i] - 'A' + 'a';
		}
	}
}

