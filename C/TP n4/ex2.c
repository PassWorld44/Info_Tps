/*
TP4 - ex2
Emile BONDU
22/10/2021
enumerations
*/

#include <stdio.h>
#include <string.h>

enum JourDeLaSemaine
{
	lundi    = 0,
	mardi    = 1,
	mercredi = 2,
	jeudi    = 3,
	vendredi = 4,
	samedi   = 5,
	dimanche = 6
};

int main()
{
	enum JourDeLaSemaine j;
	float temperatures [7];
	int indiceTempMax = 0, indiceTempMin = 0;
	char joursStr[7][20] = 
	{
		"lundi",
		"mardi",
		"mercredi",
		"jeudi",
		"vendredi",
		"samedi",
		"dimanche"
	};

	//Input des temeratures
	for(int i = lundi; i <= dimanche; i++)
	{
		printf("Quelle est la temperature du %s ? ", joursStr[i]);
		fflush(stdin);
		scanf("%f", &temperatures[i]);
	}
	printf("\n");

	for(int i = lundi; i <= dimanche; i++)
	{
		if(temperatures[i] > temperatures[indiceTempMax])
		{
			indiceTempMax = i;
		}
		if(temperatures[i] < temperatures[indiceTempMin])
		{
			indiceTempMin = i;
		}
	}

	printf("La temperature maximale de la semaine : %.2f, le %s\n", 
						temperatures[indiceTempMax], joursStr[indiceTempMax]);
	printf("La temperature minimale de la semaine : %.2f, le %s\n", 
						temperatures[indiceTempMin], joursStr[indiceTempMin]);

	return 0;
}