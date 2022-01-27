/*
TP2 - ex3
Emile BONDU
23/09/2021
Sort basique a l'aide d'une structure de if/else
Ceci n'est clairement pas optimal pour du sort
*/

#include <stdio.h>

int main()
{
	int a1 = 0, a2 = 0, a3 = 0;
	int b1 = 0, b2 = 0, b3 = 0;

	printf("nombre 1 : ");
	scanf("%d", &a1);
	printf("nombre 2 : ");
	scanf("%d", &a2);
	printf("nombre 3 : ");
	scanf("%d", &a3);

	if(a1 < a2 && a1 < a3)
	{
		b1 = a1;
		if (a2 < a3)
		{
			b2 = a2;
			b3 = a3;
		}
		else
		{
			b3 = a2;
			b2 = a3;
		}
	}
	if( a2 < a3) //a1 n'est pas minorant
	{
		b1 = a2;
		if (a1 < a3)
		{
			b2 = a1;
			b3 = a3;
		}
		else
		{
			b3 = a1;
			b2 = a3;
		}
	}
	else // a3 est minorant
	{
		b1 = a3;
		if (a1 < a2)
		{
			b2 = a1;
			b3 = a2;
		}
		else
		{
			b3 = a1;
			b2 = a2;
		}
	}

	printf("Les nombres donnes dans l'ordre croissant : %d %d %d", b1, b2, b3);

	return 0;
}