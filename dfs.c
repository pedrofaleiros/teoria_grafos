#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    struct lista * adj;
}vertice;

typedef struct elemento
{
    int valor;
    struct elemento *prox;
} elemento;

typedef struct lista
{
    int qtd;
    struct elemento *inicio;
} lista;

lista *aloca_lista();
elemento *aloca_elemento();
void inclui_elemento(lista * l, int v);
void push(vertice * v, int valor);
void dfs(vertice * v, int i);

int main()
{
    int n, e;

    scanf("%d %d", &n, &e);

    vertice * vertices;

    vertices = malloc(sizeof(vertice)*n);

    for(int i = 0; i < n; i++){
        vertices[i].visitado = 0;
    }

    for(int i = 0; i < e; i++){
        int u, v;
        scanf("%d %d", &u, &v);

        push(&vertices[u-1], v);
        push(&vertices[v-1], u);
    }

    int cont = 0;

    for(int i = 0; i < n; i++){
        if(vertices[i].visitado == 0){
            dfs(vertices, i);
            cont++;
        }
    }

    printf("%d", cont);

    return 0;
}

void dfs(vertice * v, int i){
    elemento * aux;
    v[i].visitado = 1;

    if(v[i].adj == NULL){
        return;
    }

    aux = v[i].adj->inicio;

    while(aux){
        if(v[aux->valor-1].visitado == 0){
            dfs(v, aux->valor-1);
        }
        aux = aux->prox;
    }

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

elemento *aloca_elemento()
{
    elemento *novo;
    novo = malloc(sizeof(elemento));
    return novo;
}

lista *aloca_lista()
{
    lista *nova;
    nova = calloc(1, sizeof(lista));
    return nova;
}