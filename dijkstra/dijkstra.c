#include "priority_queue.h"

#define INF 9999

typedef struct
{
	int visitado;
	int distancia;
	int lista_adj[100];
	int lista_pesos[100];
	int tamanho_lista;
} Vertice;

void dijkstra(Vertice * v, int root, int * vet, int num_v);
void preenche_dist(int * vet, int n);

int main()
{
	int num_vertices;

	scanf("%d", &num_vertices);

	Vertice * vertices = malloc(sizeof(Vertice)*(num_vertices+1));
	

	int x, y, peso;
	while(1)
	{
		scanf("%d %d %d", &x, &y, &peso);

		if(!x || !y || !peso) break;

		vertices[x].lista_adj[vertices[x].tamanho_lista] = y;
		vertices[x].lista_pesos[vertices[x].tamanho_lista++] = peso;

		vertices[y].lista_adj[vertices[y].tamanho_lista] = x;
		vertices[y].lista_pesos[vertices[y].tamanho_lista++] = peso;
	}

	int * vetor = malloc(sizeof(int)*(num_vertices+1));

	dijkstra(vertices, 1, vetor, num_vertices);

	for(int i = 1; i <= num_vertices; i++){
		printf("\n distancia %d: %d", i, vetor[i]);
	}

	printf("\n");
	return 0;
}

void dijkstra(Vertice * v, int root, int * vet, int num_v)
{
	Heap * heap = aloca_priority_queue();
	Dupla aux;
	int cur, dist, i, elemento;

	preenche_dist(vet, num_v);

	vet[root] = 0;

	push(heap, root, 0);

	while(!empty(heap)){

		aux = pop(heap);
		cur = aux.current;
		dist = aux.distancia;

		for(i = 0; i < v[cur].tamanho_lista; i++){
			elemento = v[cur].lista_adj[i];

			if(dist + v[cur].lista_pesos[i] < vet[elemento]){
				vet[elemento] = dist + v[cur].lista_pesos[i];
				push(heap, elemento, vet[elemento]);
			}
		}
	}
}

void preenche_dist(int * vet, int n)
{
	while(n > 0){
		vet[n--] = INF;
	}
}