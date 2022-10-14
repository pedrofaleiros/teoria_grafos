#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int visitado;
	int lista_adj[100];
	int tamanho_lista;
}Vertice;

typedef struct lista{
	struct elemento * inicio;
}lista;

typedef struct elemento{
	int x;
	int y;
	struct elemento * prox;
}elemento;

void inclui(lista * l, int x, int y)
{
	elemento * novo;
	novo = malloc(sizeof(elemento));
	novo->x = x;
	novo->y = y;
	novo->prox = NULL;

	if(l->inicio == NULL){
		l->inicio = novo;
	}else{
		elemento * aux;
		aux = l->inicio;

		while(aux->prox != NULL){
			aux = aux->prox;
		}

		aux->prox = novo;
	}
}

void mostra(lista * l)
{
	if(l->inicio == NULL){
		printf("\nNao tem pontes");
	}
	elemento * aux;
	aux = l->inicio;
	while(aux){
		printf("\n %d -> %d", aux->x, aux->y);
		aux = aux->prox;
	}
}

void dfs(Vertice * v, int pos, int pai, lista * lista_pontes);

int * in;
int * lower;
int cc = 0;

int min(int x, int y){
	if(x < y) 
		return x;
	return y;
}

int main(){

	int n, a, i, x, y;

	scanf("%d %d", &n, &a);

	in = malloc(sizeof(int)*(n+1));
	lower = malloc(sizeof(int)*(n+1));

	Vertice * vertices = malloc(sizeof(Vertice)*(n+1));

	for(i = 0; i < a; i++){
		scanf("%d %d", &x, &y);
		vertices[x].lista_adj[ vertices[x].tamanho_lista++ ] = y;
		vertices[y].lista_adj[ vertices[y].tamanho_lista++ ] = x;
	}

	lista * pontes = malloc(sizeof(lista));

	dfs(vertices, 1, 0, pontes);

	mostra(pontes);

	printf("\n");
	return 0;
}

void dfs(Vertice * v, int pos, int pai, lista * lista_pontes)
{
	in[pos] = cc;
	lower[pos] = cc;
	cc++;

	v[pos].visitado = 1;

	for(int i = 0; i < v[pos].tamanho_lista; i++){
		int filho = v[pos].lista_adj[i];

		if(v[filho].visitado == 0){
			dfs(v, filho, pos, lista_pontes);

			if(lower[filho] > in[pos]){
				//ponte
				inclui(lista_pontes, pos, filho);
				//printf("\nPonte: %d -> %d", pos, filho);
			}else{
				lower[pos] = min(lower[pos], lower[filho]);
			}
		}else{
			if(filho != pai){
				lower[pos] = min(lower[pos], in[filho]);
			}
		}
	}
}