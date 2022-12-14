#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "grafo_float.h"

#include "omp.h"

#define QUADRADO 2

typedef struct {
	float x;
	float y;
} Ponto;

Ponto novo_ponto(float x, float y)
{
	Ponto novo;
	novo.x = x;
	novo.y = y;
	return novo;
}

float calcula_distancia_pontos(Ponto p1, Ponto p2)
{
	float x1, y1, x2, y2;
	x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;

	float distancia;

	distancia = pow((x2 - x1), QUADRADO) + pow((y2-y1), QUADRADO);

	return sqrt(distancia);
}

float distancia_ate_origin(Vertice * v, int dest, int origin);
void calcula_distancia(Vertice * vertices, int origin, int * vis, int * rota, int indice, float distancia, int this_elemento);
void calcula_rota(Vertice * vertices, int origin);

int * rota_otima;
float menor_distancia = 9999;
int numero_v = 0;

int main()
{
	int i, j;
	float x, y, distancia;
	Ponto * pontos;
	Ponto p1, p2;
	Vertice * vertices = malloc(sizeof(Vertice)*numero_v);

	scanf("%d", &numero_v);

	pontos = malloc(sizeof(Ponto)*numero_v);
	for(i = 0; i < numero_v; i++){
		scanf("%f %f", &x, &y);

		pontos[i].x = x;
		pontos[i].y = y;
	}

	for(i = 0; i < numero_v-1; i++){
		p1 = pontos[i];
		for(j = i+1; j < numero_v; j++){
			p2 = pontos[j];

			distancia = calcula_distancia_pontos(p1, p2);

			addAresta(vertices, i, j, distancia);
			addAresta(vertices, j, i, distancia);
		}
	}

	int origin = 0;

	double t1 = omp_get_wtime();
	calcula_rota(vertices, origin);

	printf("Tempo: %lf\n", omp_get_wtime()-t1);
	printf("Quantidade de Lugares: %d\n", numero_v);
	printf("Menor distancia: %f\n", menor_distancia);
	printf("Rota: ");
	for(i = 0; i <= numero_v; i++){
		printf("%d ", rota_otima[i]+1);
	}

	printf("\n");
	return 0;
}

void calcula_rota(Vertice * vertices, int origin)
{
	int * visitados = malloc(sizeof(int)*numero_v);
	int * rota = malloc(sizeof(int)*(numero_v+1));
	rota_otima = malloc(sizeof(int)*(numero_v+1));
	int indice = 0, i, elemento;
	float distancia = 0;

	int tam_lista = vertices[origin].tamanho_lista;

	visitados[origin] = 1;
	rota[0] = origin;
	rota[numero_v] = origin;

	for(i = 0; i < tam_lista; i++){
		elemento = vertices[origin].lista_adj[i].valor;
		distancia = vertices[origin].lista_adj[i].peso;
		calcula_distancia(vertices, origin, visitados, rota, indice+1, distancia, elemento);
	}

	free(visitados);
	free(rota);
}

void calcula_distancia(Vertice * vertices, int origin, int * vis, int * rota, int indice, float distancia, int this_elemento)
{
	if(distancia > menor_distancia) return;

	int i, tam_lista, el_da_lista;
	float this_dist;

	vis[this_elemento] = 1;
	rota[indice] = this_elemento;

	tam_lista = vertices[this_elemento].tamanho_lista;

	for(i = 0; i < tam_lista; i++){
		el_da_lista = vertices[this_elemento].lista_adj[i].valor;
		this_dist = vertices[this_elemento].lista_adj[i].peso;

		if(vis[el_da_lista] == 0){
			calcula_distancia(vertices, origin, vis, rota, indice+1, distancia+this_dist, el_da_lista);
		}
	}

	if(indice == numero_v-1){
		this_dist = distancia + distancia_ate_origin(vertices, this_elemento, origin);

		if(this_dist < menor_distancia){
			menor_distancia = this_dist;
			for(i = 0; i <= numero_v; i++){
				rota_otima[i] = rota[i];
			}
		}
	}
	vis[this_elemento] = 0;
}

float distancia_ate_origin(Vertice * v, int dest, int origin)
{
	int i;
	for(i = 0; i < numero_v; i++){
		if(v[dest].lista_adj[i].valor == origin){
			return v[dest].lista_adj[i].peso;
		}
	}
}
