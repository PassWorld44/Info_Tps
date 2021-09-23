/*
TP2 - ex2
Emile BONDU
23/09/2021
somme d'une serie harmonique
*/

#include <stdio.h>

int main()
{
	int n = 0;
	printf("nombre de thermes a calculer : ");
	scanf("%d", &n);

	double sum = 0;

	for(int i = 1; i < n+1 ; i++)
	{
		sum += 1/ (double)i;
	}

	printf("%f", sum);

	return 0;
}