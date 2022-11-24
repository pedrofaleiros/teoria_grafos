#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#include "omp.h"

void calcula_rota(Vertice * vertices, int num_vertices, int origin);
void recursiva(Vertice * vertices, int num_v, int origin, int * visitados, int * rota, int indice, int distancia, int this_elemento);
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
    int indice, distancia, i, elemento;
	int visitados[num_vertices];
	int rota[num_vertices+1];
	
    rota_otima = malloc(sizeof(int)*(num_vertices+1));
	distancia = indice = 0;

	visitados[origin] = 1;
	rota[0] = origin;
	rota[num_vertices] = origin;

	for(i = 0; i < (vertices[origin].tamanho_lista); i++){
		elemento = vertices[origin].lista_adj[i].valor;
		distancia = vertices[origin].lista_adj[i].peso;
		
        recursiva(vertices, num_vertices, origin, visitados, rota, indice+1, distancia, elemento);
	}
}

void recursiva(Vertice * vertices, int num_v, int origin, int * visitados, int * rota, int indice, int distancia, int this_elemento)
{
	int i, tam_lista, el_da_lista, this_dist;

    if(distancia >= menor_distancia){
        return;
    }

	rota[indice] = this_elemento;

    if(indice == num_v-1){
		this_dist = distancia + distancia_ate_origin(vertices, num_v, this_elemento, origin);

		if(this_dist < menor_distancia){
			menor_distancia = this_dist;
			for(i = 0; i <= num_v; i++){
				rota_otima[i] = rota[i];
			}
		}
	}

	visitados[this_elemento] = 1;

	for(i = 0; i < vertices[this_elemento].tamanho_lista; i++){
		el_da_lista = vertices[this_elemento].lista_adj[i].valor;
		this_dist = vertices[this_elemento].lista_adj[i].peso;

		if(visitados[el_da_lista] == 0){
			recursiva(vertices, num_v, origin, visitados, rota, indice+1, distancia+this_dist, el_da_lista);
		}
	}
    
	visitados[this_elemento] = 0;
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