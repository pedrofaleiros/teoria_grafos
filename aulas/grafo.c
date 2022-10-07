#include <stdio.h>
#include <stdlib.h>

#define PPP

typedef struct lista{
	struct elemento * inicio;
}lista;

typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;

typedef struct vertice{
	int visitado;
	int distancia;
	struct lista * lista_adj;
}vertice;

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

void inclui_lista(lista * l, int valor){
	if(l == NULL) return;

    elemento *aux = NULL, *ant = NULL;
    elemento * novo;
    novo = elemento_alloc();
    novo->valor = valor;

    if(l->inicio != NULL){

		aux = l->inicio;
		while(aux){
			if(aux->valor == novo->valor) return;

			if(aux->prox == NULL){
				aux->prox = novo;
			}
			aux = aux->prox;
		}

        /* aux = l->inicio;
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
        } */
    }else{
        l->inicio = novo;
    }
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

	inclui_lista(v->lista_adj, valor);
}

void dfs(vertice * v, int i, int distancia){

	if(v[i].visitado == 1) return;

	//printf("%d ", i);
	v[i].visitado = 1;
	
	v[i].distancia = distancia;

	if(v[i].lista_adj == NULL) return;

	elemento * aux;

	aux = v[i].lista_adj->inicio;

	while(aux){
		if(v[aux->valor].visitado == 0){
			dfs(v, aux->valor, distancia+1);
		}
		aux = aux->prox;
	}


}


int main(){

	int n, a, i;
	vertice * v;

	scanf("%d %d", &n, &a);

	v = malloc(sizeof(vertice)* (n+1));

	for(i = 0; i < a; i++){
		int a, b;

		scanf("%d %d", &a, &b);

		inclui_aresta(&v[a], b);
		inclui_aresta(&v[b], a);
	}

	/* for(int i = 1; i <= n; i++){
		if(v[i].visitado == 0){
			printf("\n %d -> ", ++cont);
			dfs(v, i, 0);
		}
	} */

	//dfs(v, 4, 0);

	/* for(int i = 1; i <= n; i++){
		printf("\n %d -> %d", i, v[i].distancia);
	} */

	//printf("\n cont: %d\n", cont);

	if(a == (n-1)){

		int cont = 0;
		for(int i = 1; i<= n; i++){
			if(v[i].visitado == 0){
				dfs(v, i, 0);
				cont++;
			}
		}

		if(cont == 1){
			printf("\n ARVORE");
		}else{
			printf("\nNAO");
		}

	}else{
		printf("\nNAO");
	}


	return 0;
}