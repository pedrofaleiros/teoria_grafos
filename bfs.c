#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int tamanho;
    struct elemento * inicio;
    struct elemento * final;
}fila;

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct vertice{
    int visitado;
	int distancia;
    struct lista * adj;
}vertice;

typedef struct lista
{
    int qtd;
    struct elemento *inicio;
} lista;

void inclui_elemento(lista * l, int v);
void push(vertice * v, int valor);
void dfs(vertice * v, int i);

void enqueue(fila * f, int num);
int pop(fila * f);
int is_empty(fila * f);
int size(fila * f);
int front(fila * f);

lista *aloca_lista();
fila * aloca_fila();
elemento * aloca_elemento();

void inclui_aresta(vertice * v, int valor){

	if(v->adj == NULL)
		v->adj = aloca_lista();

	inclui_elemento(v->adj, valor);
}

void bfs(vertice * v, int i);

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

	bfs(ver, 1);

	for(i = 1; i <= n; i++){
		printf("\n %d: distancia = %d", i, ver[i].distancia);
	}

	printf("\n");
	return 0;
}

void bfs(vertice * v, int i){

    fila * f = aloca_fila();

    elemento * aux;

    int current;

    enqueue(f, i);

    while(!is_empty(f)){
        current = pop(f);

        if(v[current].visitado == 0){
            v[current].visitado = 1;

            aux = v[current].adj->inicio;
            while(aux != NULL){
                enqueue(f, aux->valor);

                if(v[aux->valor].distancia == 0 && aux->valor != i){
                    v[aux->valor].distancia = v[current].distancia + 1;
                }
                aux = aux->prox;
            }
        }

    }

}

void enqueue(fila * f, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(is_empty(f)){
        f->inicio = novo;
        f->final = novo;
    }else{
        f->final->prox = novo;
        f->final = novo;
    }

    f->tamanho++;
}

int pop(fila * f)
{
    if(is_empty(f))
        return -1;
    else{
        int num;
        elemento * aux;

        aux = f->inicio;
        num = aux->valor;

        f->inicio = f->inicio->prox;

        if(f->inicio == NULL)
            f->final = NULL;

        free(aux);
        return num;
    }
}

int is_empty(fila * f)
{
    if(f->inicio == NULL)
        return 1;
    else
        return 0;
}

int size(fila * f)
{
    return f->tamanho;
}

int front(fila * f)
{
    if(!is_empty(f)) 
        return f->inicio->valor;
    else
        return -1;
}

fila * aloca_fila()
{
    fila * nova;
    nova = calloc(1, sizeof(fila));
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}

void push(vertice * v, int valor){
    if(v->adj == NULL){
        v->adj = aloca_lista();
    }
    inclui_elemento(v->adj, valor);
}

void inclui_elemento(lista * l, int v){

    if(l == NULL) return;

    elemento *aux = NULL, *ant = NULL;
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = v;

    if(l->inicio != NULL){

        aux = l->inicio;
        int inserido = 0;

        while(aux != NULL && !inserido){

            if(aux->valor == novo->valor) return;

            if(novo->valor > aux->valor){
                ant = aux;
                aux = aux->prox;
            }else{
                if(ant != NULL){
                    ant->prox = novo;
                }else{
                    l->inicio = novo;
                }
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

    l->qtd++;
}

lista *aloca_lista()
{
    lista *nova;
    nova = calloc(1, sizeof(lista));
    return nova;
}