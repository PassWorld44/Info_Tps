/*
TP1 - ex2
Emile BONDU
09/09/2021
recherche avec les types du c
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
	printf("Pour les int8_t :\n");
	uint8_t  unsigned_int_8 = 8;
	printf("		uint8_t : valeur de %u \tstocke sur %lu octets\n", unsigned_int_8, sizeof(unsigned_int_8));
	int8_t  int_8 = -8;
	printf("		int8_t : valeur de %d \tstocke sur %lu octets\n", int_8, sizeof(int_8));
	//le stockage sur un octet permet de stocker 256 possibilitees.

	printf("Pour les uint32 :\n");
	uint32_t  unsigned_int_16 = 32;
	printf("		uint32_t : valeur de %u \tstocke sur %lu octets\n", unsigned_int_16, sizeof(unsigned_int_16));
	int32_t  int_16 = -32;
	printf("		int32_t : valeur de %d \tstocke sur %lu octets\n", int_16, sizeof(int_16));
	//le stockage sur deux octet permet de stocker 65536 possibilitees.

	printf("Pour les uint64 :\n");
	uint64_t  unsigned_int_64 = 64;
	printf("		uint64_t : valeur de %lu \tstocke sur %lu octets\n", unsigned_int_64, sizeof(unsigned_int_64));
	int64_t  int_64 = -64;
	printf("		int64_t : valeur de %ld \tstocke sur %lu octets\n", int_64, sizeof(int_64));
	//le stockage sur trois octet permet de stocker 4294967296 possibilitees.

	return 0;
}