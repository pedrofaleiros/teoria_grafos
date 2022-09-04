#include <stdio.h>
#include <stdlib.h>

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
	int mulher;
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

	int n, i;
	vertice * v;

	scanf("%d", &n);

	v = malloc(sizeof(vertice)* (n+1));

	for(i = 0; i < n-1; i++){
		int a, b;

		scanf("%d %d", &a, &b);

		inclui_aresta(&v[a], b);
		inclui_aresta(&v[b], a);
	}

	dfs(v, 1, 0);

	int qtd_mul;

	scanf("%d", &qtd_mul);

	lista * mulheres = lista_alloc();

	for(i = 0; i < qtd_mul; i++){
		int x;
		scanf("%d", &x);
		v[x].mulher = 1;
	}

	int menor = n;
	for(i = 2; i <= n; i++){
		if(v[i].mulher){
			if(v[i].distancia < menor){
				menor = v[i].distancia;
			}
		}
	}
	
	for(i = n; i >= 2; i--){
		if(v[i].mulher && v[i].distancia == menor){
			inclui_lista(mulheres, i);
		}
	}

	printf("%d", mulheres->inicio->valor);

	return 0;
}