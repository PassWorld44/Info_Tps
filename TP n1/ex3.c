/*
TP1 - ex3
Emile BONDU
16/09/2021
depassement et debug
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
	uint8 int1 = 255;
	uint8 int2 = 259;
	uint8 int3;
	uint8 int3 = 0;
	uint8 int4;
	uint8 int 5 = 2;

	printf("Premier entier %d stocke sur %d octet\n", int1, sizeof(int1));
	printf("Deusieme entier %d stocke sur %d octet\n", int2, sizeof(int2));
	int4 = int1 + int2;
	printf("Somme de deux entiers : int1 + int2 = %d stocke sur %d octet\n", int4, sizeof(int4));
	
	printf("\n\n");
	return 0;
}