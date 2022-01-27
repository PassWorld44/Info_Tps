/*
TP2 - ex0
Emile BONDU
23/09/2021
*/

#include <stdio.h>

int main()
{
	int age = 0;

	printf("Bonjour, quel age qvez vous ?\n");
	scanf("%d", &age);
	printf("Vous avez %d ans\n", age);
	printf("En octal, vous avez %o ans\n", age);
	printf("En exadecimal, vous avez %x ans\n", age);
	printf("\n");
	printf("Vous en paraissez %d...\n", age - 5);

	return 0;
}