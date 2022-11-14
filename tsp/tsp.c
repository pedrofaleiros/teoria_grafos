#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#include "omp.h"

void calcula_rota(Vertice * vertices, int num_vertices, int origin);
void calcula_distancia(Vertice * vertices, int num_v, int origin, int * vis, int * rota, int indice, int distancia, int this_elemento);
int distancia_ate_origin(Vertice * v, int num_v, int dest, int origin);

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

	/* for(i = 0; i < n; i ++){
		printf("\n %d -> ", i);
		for(j = 0; j < vertices[i].tamanho_lista; j++){
			printf("(%d, peso: %d) ", vertices[i].lista_adj[j].valor, vertices[i].lista_adj[j].peso);
		}
	} */

	int origin = 0;

	double t1 = omp_get_wtime();
	calcula_rota(vertices, n, origin);

	printf("\n Tempo: %lf", omp_get_wtime()-t1);

	printf("\n Menor distancia: %d", menor_distancia);
	printf("\n Rota: ");
	for(i = 0; i <= n; i++){
		printf("%d ", rota_otima[i]);
	}

	printf("\n");
	return 0;
}

void calcula_rota(Vertice * vertices, int num_vertices, int origin)
{
	int * visitados = malloc(sizeof(int)*num_vertices);
	int * rota = malloc(sizeof(int)*(num_vertices+1));
	rota_otima = malloc(sizeof(int)*(num_vertices+1));
	int indice = 0, distancia = 0, i, elemento;

	int tam_lista = vertices[origin].tamanho_lista;

	visitados[origin] = 1;
	rota[0] = origin;
	rota[num_vertices] = origin;

	for(i = 0; i < tam_lista; i++){
		elemento = vertices[origin].lista_adj[i].valor;
		distancia = vertices[origin].lista_adj[i].peso;
		calcula_distancia(vertices, num_vertices, origin, visitados, rota, indice+1, distancia, elemento);
	}
}

void calcula_distancia(Vertice * vertices, int num_v, int origin, int * vis, int * rota, int indice, int distancia, int this_elemento)
{
	int i, tam_lista, el_da_lista, this_dist;

	vis[this_elemento] = 1;
	rota[indice] = this_elemento;

	tam_lista = vertices[this_elemento].tamanho_lista;

	for(i = 0; i < tam_lista; i++){
		el_da_lista = vertices[this_elemento].lista_adj[i].valor;
		this_dist = vertices[this_elemento].lista_adj[i].peso;

		if(vis[el_da_lista] == 0){
			if(distancia+this_dist > menor_distancia){
				vis[this_elemento] = 0;
				return;
			}
			calcula_distancia(vertices, num_v, origin, vis, rota, indice+1, distancia+this_dist, el_da_lista);
		}
	}

	if(indice == num_v-1){
		this_dist = distancia + distancia_ate_origin(vertices, num_v, this_elemento, origin);

		if(this_dist < menor_distancia){
			menor_distancia = this_dist;
			for(i = 0; i <= num_v; i++){
				rota_otima[i] = rota[i];
			}
		}
	}
	vis[this_elemento] = 0;
}

int distancia_ate_origin(Vertice * v, int num_v, int dest, int origin)
{
	int i;
	for(i = 0; i < num_v; i++){
		if(v[dest].lista_adj[i].valor == origin){
			return v[dest].lista_adj[i].peso;
		}
	}
}