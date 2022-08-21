#include <stdio.h>
#include <stdlib.h>

int main() {

	int * vet;

	vet = malloc(sizeof(int)*3);

	vet[0] = 1;
	vet[1] = 2;
	vet[2] = 3;


	vet = realloc(vet, sizeof(int) + sizeof(vet));

	vet[3] = 4;

	for(int i = 0; i < 4; i++){
		printf("%d ", vet[i]);
	}



	return 0;
}