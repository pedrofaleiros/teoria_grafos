#include "min_heap.h"

typedef struct
{
	int visitado;
	int distancia;
	int lista_adj[100];
	int lista_pesos[100];
	int tamanho_lista;
} Vertice;

int main()
{
	int num_vertices;

	scanf("%d", &num_vertices);

	Vertice * vertices = malloc(sizeof(Vertice)*(num_vertices+1));

	int x, y, peso;
	while(1)
	{
		scanf("%d %d %d", &x, &y, &peso);
		printf("\n x: %d - y: %d - peso: %d\n", x, y, peso);

		if(!x || !y || !peso) break;

		vertices[x].lista_adj[vertices[x].tamanho_lista] = y;
		vertices[x].lista_pesos[vertices[x].tamanho_lista++] = peso;

		vertices[y].lista_adj[vertices[y].tamanho_lista] = x;
		vertices[y].lista_pesos[vertices[y].tamanho_lista++] = peso;
	}

	for(int i = 1; i <= num_vertices; i++){
		printf("\nvertice %d -> ", i);
		for(int j = 0; j < vertices[i].tamanho_lista; j++){
			printf("(%d, p: %d) - ", vertices[i].lista_adj[j], vertices[i].lista_pesos[j]);
		}
	}

	printf("\n");
	return 0;
}