/*
TP1 - ex4
Emile BONDU
16/09/2021
recherche avec les types du c
*/

#include <stdio.h>
//#include <stdint.h>

int main()
{
	unsigned short int1 = 10, int2 = 32767;
	unsigned int int3 = 100, int4 = 69755;
	float float1 = 15., float2 = 6;
	unsigned short resultatShort;
	unsigned int resultatInt;
	float resultatFloat;

	printf("Etat initial des variables\n");
	printf("--------------------------\n");
	printf("Short int1 : %d de taille %d octets\n", int1, sizeof(int1));
	printf("Short int2 : %d de taille %d octets\n", int2, sizeof(int2));
	printf("Int int3 : %d de taille %d octets\n", int3, sizeof(int3));
	printf("Int int4 : %d de taille %d octets\n", int4, sizeof(int4));
	printf("Float float1 : %d de taille %d octets\n", float1, sizeof(float1));
	printf("Float float2 : %d de taille %d octets\n", float2, sizeof(float2));

	printf("\n\n");

	printf("resultat d'operations et de convertions\n");
	printf("---------------------------------------\n");

	resultatShort = int1 / int2;
	printf("Short <- int1 / int2, soit %d / %d = %d\n", int1, int2, resultatShort);

	resultatFloat = int1 / int2;
	printf("Float <- int1 / int2, soit %d / %d = %d\n", int1, int2, resultatFloat);

	resultatFloat = int1 / float(int2);
	printf("Float <- int1 / int2, soit %d / %d = %d\n", int1, int2, resultatFloat);

	printf("\n");

	resultatShort = int3 / float1;
	printf("Short <- int1 / int2, soit %d / %d = %d\n", int3, float1, resultatShort);

	resultatFloat = int3 / float1;
	printf("Float <- int1 / int2, soit %d / %d = %d\n", int3, float1, resultatFloat);

	printf("\n");
	resultatShort = short(int4);
	printf("Convertion de int4  = %d en short : %d\n", int4, resultatShort);

	printf("\n");
	resultatInt = int4 % int3;
	printf("Int <- int4 \% int3, soit %d \% %d = %d de taille %d octets\n", int4, int3, resultatInt);

	printf("\n\n");
	
	return 0;
}