/*
TP5 - ex1
Emile BONDU
22/10/2021
fonctions basiques
*/

#include <stdio.h>

float CelsiusToFarenheit(float temp);
float FarenheitToCelsius(float temp);

int main()
{
	char entree = '\0';
	
	printf("Quelle convertion souhaitez-vous ?\n");
	printf("\t1 - Convertion Celsius vers Farenheit");
	printf("\t2 - Convertion Farenheit vers Celsius");
	


	return 0;
}

float CelsiusToFarenheit(float temp)
{
	return 9 * temp / 5 + 32;
}

float FarenheitToCelsius(float temp)
{
	return (temp - 32) * 5/9;
}
