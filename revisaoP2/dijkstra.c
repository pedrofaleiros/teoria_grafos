#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[100];
    int lista_peso[100];
    int tamanho_lista;
    int distancia;
} Vertice;

typedef struct {
    int current;
    int distancia;
} Elemento;

typedef struct {
    Elemento vetor[100];
    int tamanho;
} MinHeap;

Elemento novo_elemento(int cur, int dist)
{
    Elemento novo;

    novo.current = cur;
    novo.distancia = dist;

    return novo;
}

int empty(MinHeap * mh)
{
    return mh->tamanho == 0;
}

void push(MinHeap * mh, Elemento el)
{
    mh->vetor[mh->tamanho++] = el;
}

Elemento pop(MinHeap * mh)
{
    if(empty(mh)) return novo_elemento(-1, -1);

    int indice_menor = 0;

    for(int i = 1; i < mh->tamanho; i++){
        if(mh->vetor[i].distancia < mh->vetor[indice_menor].distancia){
            indice_menor = i;
        }
    }

    Elemento ret;
    ret.distancia = mh->vetor[indice_menor].distancia;
    ret.current = mh->vetor[indice_menor].current;

    for(int i = indice_menor; i < (mh->tamanho) - 1; i++){
        mh->vetor[i] = mh->vetor[i+1];
    }

    mh->tamanho -= 1;

    return ret;
}

void addAresta(Vertice * v, int x, int y, int peso);
void mostra(Vertice * v, int n);
void preenche_distancias(Vertice * v, int n);
void dijkstra(Vertice * v, int n, int origem);

int main()
{
    int n, i, x, y, peso;

    scanf("%d", &n);
    Vertice * vertices = malloc(sizeof(Vertice)*(n));

    while(1){
        scanf("%d;%d;%d", &x, &y, &peso);

        if(x == -1) break;

        addAresta(vertices, x, y, peso);
    }

    dijkstra(vertices, n, 0);

    for(i = 0; i < n; i++){
        printf("\n%d distancia: %d", i, vertices[i].distancia);
    }

    printf("\n");
    return 0;
}

void preenche_distancias(Vertice * v, int n)
{
    for(int i = 0; i < n; i++)
        v[i].distancia = 9999;
}

void dijkstra(Vertice * v, int n, int origem)
{
    MinHeap * heap = malloc(sizeof(MinHeap));
    Elemento aux;
    int cur, dist, i, elemento;

    preenche_distancias(v, n);

    v[origem].distancia = 0;

    push(heap, novo_elemento(origem, 0));

    while(! empty(heap) ){
        aux = pop(heap);

        cur = aux.current;
        dist = aux.distancia;

        for(i = 0; i < v[cur].tamanho_lista; i++){
            elemento = v[cur].lista_adj[i];

            if(dist + v[cur].lista_peso[i] < v[elemento].distancia){
                v[elemento].distancia = dist + v[cur].lista_peso[i];
                push(heap, novo_elemento(elemento, v[cur].lista_peso[i]));
            }
        }
    }
}

void mostra(Vertice * v, int n)
{
    for(int i = 0; i < n; i++){
        printf("\n %d -> ", i);
        for(int j = 0; j < v[i].tamanho_lista; j++){
            printf("%d ", v[i].lista_adj[j]);
        }
    }
}

void addAresta(Vertice * v, int x, int y, int peso)
{
    int tam;

    tam = v[x].tamanho_lista;
    v[x].lista_adj[tam] = y;
    v[x].lista_peso[tam] = peso;

    tam = v[y].tamanho_lista;
    v[y].lista_adj[tam] = x;
    v[y].lista_peso[tam] = peso;

    v[x].tamanho_lista += 1;
    v[y].tamanho_lista += 1;
}