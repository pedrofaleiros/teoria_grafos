#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

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
	calcula_rota(vertices, n, origin);

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
	if(distancia > menor_distancia) return;

	int i, tam_lista, el_da_lista, this_dist;

	vis[this_elemento] = 1;
	rota[indice] = this_elemento;

	tam_lista = vertices[this_elemento].tamanho_lista;

	for(i = 0; i < tam_lista; i++){
		el_da_lista = vertices[this_elemento].lista_adj[i].valor;
		this_dist = vertices[this_elemento].lista_adj[i].peso;

		if(vis[el_da_lista] == 0){
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

/* 
Grafos de Exemplo
4
2 3 34
2 1 19
0 3 27
3 1 17
0 1 16
2 0 28
Menor distancia: 91
Rota: 0 3 1 2 0

5
0 1 19
0 2 28
0 3 27
0 4 13
1 2 17
1 3 29
1 4 28
2 3 18
2 4 30
3 4 20
Menor distancia: 87
Rota: 0 1 2 3 4 0 

6
0 1 19
0 2 28
0 3 27
0 4 13
1 2 17
1 3 29
1 4 28
2 3 18
2 4 30
3 4 20
0 5 33
1 5 43
2 5 36
3 5 19
4 5 20
Menor distancia: 106
Rota: 0 1 2 3 5 4 0 

7
0 1 19
0 2 28
0 3 27
0 4 13
1 2 17
1 3 29
1 4 28
2 3 18
2 4 30
3 4 20
0 5 33
1 5 43
2 5 36
3 5 19
4 5 20
0 6 40
1 6 21
2 6 22
3 6 40
4 6 48
5 6 58
Menor distancia: 132
Rota: 0 1 6 2 3 5 4 0 

5
0 1 24
0 2 30
0 3 34
0 4 55
1 2 32
1 3 46
1 4 52
2 3 18
2 4 25
3 4 31
Menor distancia: 146
Rota: 0 1 2 4 3 0 
*/