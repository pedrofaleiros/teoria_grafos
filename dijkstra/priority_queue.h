#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
	int current;
	int distancia;
	struct registro *prox;
} Registro;

typedef struct
{
	int qtd;
	struct registro *topo;
} PriorityQueue;

typedef struct {
	int current;
	int distancia;
} Dupla;

Registro *aloca_registro(int cur, int dist);
PriorityQueue *aloca_priority_queue();
void push(PriorityQueue *l, int cur, int dist);
int empty(PriorityQueue *l);
void mostra(PriorityQueue * l);
Dupla nova_dupla(int cur, int dist);
Dupla pop(PriorityQueue * l);

Dupla pop(PriorityQueue * l)
{
	if(empty(l)){
		return nova_dupla(-1, -1);
	}

	Registro * aux = l->topo;

	int cur, dist;
	cur = aux->current;
	dist = aux->distancia;

	l->topo = aux->prox;
	l->qtd--;

	free(aux);

	return nova_dupla(cur, dist);
}

Dupla nova_dupla(int cur, int dist)
{
	Dupla nova;
	nova.current = cur;
	nova.distancia = dist;
	return nova;
}

void mostra(PriorityQueue * l)
{
	Registro * aux = l->topo;

	if(empty(l)){
		printf("\n PriorityQueue vazia");
	}

	while(aux){
		printf("\n> %d : %d", aux->distancia, aux->current);
		aux = aux->prox;
	}
}

void push(PriorityQueue *l, int cur, int dist)
{
	Registro *novo;
	novo = aloca_registro(cur, dist);

	if (!empty(l)){
		Registro *aux, *ant;

		aux = l->topo;
		ant = NULL;

		while (novo->distancia > aux->distancia && aux->prox != NULL){
			ant = aux;
			aux = aux->prox;
		}

		if (ant == NULL){
			if(aux->distancia < novo->distancia){
				aux->prox = novo;
			}else{
				novo->prox = aux;
				l->topo = novo;
			}
		}else{
			if(aux->distancia < novo->distancia){
				aux->prox = novo;
			}else{
				ant->prox = novo;
				novo->prox = aux;
			}
		}
	}else{
		l->topo = novo;
	}

	l->qtd++;
}

Registro *aloca_registro(int cur, int dist)
{
	Registro *novo;

	novo = malloc(sizeof(Registro));
	novo->current = cur;
	novo->distancia = dist;
	novo->prox = NULL;

	return novo;
}

PriorityQueue *aloca_priority_queue()
{
	PriorityQueue *nova;

	nova = malloc(sizeof(PriorityQueue));
	nova->qtd = 0;
	nova->topo = 0;

	return nova;
}

int empty(PriorityQueue *l)
{
	return l->qtd == 0;
}