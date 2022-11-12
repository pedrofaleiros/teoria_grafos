#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int menor_distancia = 9999;
int * rota_otima;

int main()
{
	int n, x, y, peso, i, j, elemento, lim;

	scanf("%d", &n);

	Vertice * vertices = malloc(sizeof(Vertice)*(n));

	lim = soma_fat(n-1);

	for(i = 0; i < lim; i++){
		scanf("%d %d %d", &x, &y, &peso);

		addAresta(vertices, x, y, peso);
		addAresta(vertices, y, x, peso);
	}

	for(i = 0; i < n; i++){
		printf("\n%d -> ",i);
		for(int j = 0; j < vertices[i].tamanho_lista; j++){
			printf("%d ", vertices[i].lista_adj[j].valor);
		}
	}

	printf("\n");
	return 0;
}
