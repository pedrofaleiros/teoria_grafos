#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef int bool;

typedef struct vertice{
	int visitado;
	struct lista * lista_adj;
}vertice;

typedef struct lista{
	int qtd;
	struct elemento * inicio;
}lista;

typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;

elemento * elemento_alloc(){
	elemento * novo = malloc(sizeof(elemento));
	novo->prox = NULL;
	novo->valor = 0;
	return novo;
}
lista * lista_alloc(){
	lista * nova = malloc(sizeof(lista));
	nova->inicio == NULL;
	return nova;
}

void inclui_elemento(lista * l, int valor){
	if(l == NULL) return;

    elemento *aux = NULL, *ant = NULL;
    elemento * novo;
    novo = elemento_alloc();
    novo->valor = valor;

    if(l->inicio != NULL){
        aux = l->inicio;
        int inserido = 0;
        while(aux != NULL && !inserido){
            if(aux->valor == novo->valor) return;
            if(novo->valor > aux->valor){
                ant = aux;
                aux = aux->prox;
            }else{
                if(ant != NULL)
                    ant->prox = novo;
                else
                    l->inicio = novo;
                novo->prox = aux;
                inserido = 1;
            }
        }
        if(!inserido){
            ant->prox = novo;
        }
    }else{
        l->inicio = novo;
    }

	l->qtd += 1;
}

void mostra(lista * l){
	elemento * aux;
	aux = l->inicio;

	while(aux){
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
}

void inclui_aresta(vertice * v, int valor){

	if(v->lista_adj == NULL)
		v->lista_adj = lista_alloc();

	inclui_elemento(v->lista_adj, valor);
}

void zera_visitados(vertice * v, int qtd){
	for(int i = 0; i <= qtd; i++){
		v[i].visitado = 0;
	}
}

bool dfs_back_edge(vertice * v, int i, int pai);

int main(){

	int n, a, i;
	vertice * ver;

	scanf("%d %d", &n, &a);

	ver = malloc(sizeof(vertice)* (n+1));

	for(i = 0; i < a; i++){
		int a, b;

		scanf("%d %d", &a, &b);

		inclui_aresta(&ver[a], b);
		inclui_aresta(&ver[b], a);
	}


	dfs_back_edge(ver, 1, 0) == true ?
		printf("\n BACK EDGE") :
		printf("\n Nao");

	printf("\n");
	return 0;
}

bool dfs_back_edge(vertice * v, int i, int pai){

	v[i].visitado = 1;

	bool hasBE = false;

	if(v[i].lista_adj->inicio != NULL){
		elemento * aux;

		aux = v[i].lista_adj->inicio;

		while(aux != NULL){
			if(v[aux->valor].visitado == 0){
				hasBE = dfs_back_edge(v, aux->valor, i);
			}else if(pai != aux->valor){
				return true;
			}
			aux = aux->prox;
		}
	}

	return hasBE;
}