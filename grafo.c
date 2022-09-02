#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
	int ponderado;
	int num_v;
	int grau_max;
	int ** arestas;
	float ** pesos;
	int * grau;
}Grafo;

Grafo * aloca_grafo(int num_v, int g_max, int pond){
	Grafo * novo = malloc(sizeof(Grafo));

	int i;
	
	novo->num_v = num_v;
	novo->grau_max = g_max;
	novo->ponderado = (pond != 0) ? 1:0;

	novo->grau = calloc(num_v, sizeof(int));

	novo->arestas = (int**)malloc(num_v*sizeof(int*));

	for(i = 0; i < num_v; i++){
		novo->arestas[i] = malloc(g_max*sizeof(int));
	}

	if(novo->ponderado){
		novo->pesos = (float**)malloc(num_v*sizeof(float*));

		for(i = 0; i < num_v; i++){
			novo->pesos[i] = malloc(g_max*sizeof(float));
		}
	}

	return novo;
}

void libera_grafo(Grafo * gr){
	if(gr != NULL){
		int i;
		for(i = 0; i < gr->num_v; i++){
			free(gr->arestas[i]);
		}
		free(gr->arestas);

		if(gr->ponderado){
			for(i = 0; i < gr->num_v; i++){
				free(gr->pesos[i]);
			}
			free(gr->pesos);
		}

		free(gr->grau);
		free(gr);
	}
}

int insere_aresta(Grafo * gr, int origem, int dest, int dig, float peso){
	if(gr == NULL) return 0;

	if(origem < 0 || origem >= gr->num_v) return 0;

	if(dest < 0 || dest >= gr->num_v) return 0;

	gr->arestas[origem][gr->grau[origem]] = dest;
	if(gr->ponderado){
		gr->pesos[origem][gr->grau[origem]] = peso;
	}

	gr->grau[origem]++;

	if(dig == 0) insere_aresta(gr, dest, origem, 1, peso);

	return 1;
}

void _busca(Grafo * gr, int inicio, int * vis, int cont){
	
	int i;
	vis[inicio] = cont;
	for(i = 0; i < gr->grau[inicio]; i++){
		if(!vis[gr->arestas[inicio][i]]){
			_busca(gr, gr->arestas[inicio][i], vis, cont+1);
		}
	}
}

void busca(Grafo * gr, int inicio, int * vis){

	int i, cont = 1;
	for(i = 0; i<gr->num_v; i++){
		vis[i] = 0;
	}

	_busca(gr, inicio, vis, cont);
}

int main(){
	Grafo * gr = aloca_grafo(5, 5, 0);

	insere_aresta(gr, 0, 1, 1, 0);
	insere_aresta(gr, 1, 3, 1, 0);
	insere_aresta(gr, 1, 2, 1, 0);
	insere_aresta(gr, 2, 4, 1, 0);
	insere_aresta(gr, 3, 0, 1, 0);
	insere_aresta(gr, 3, 4, 1, 0);
	insere_aresta(gr, 4, 1, 1, 0);

	int visitados[5];

	busca(gr, 0, visitados);


	return 0;
}