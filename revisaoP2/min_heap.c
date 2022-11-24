#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current;
    int distancia;
} Elemento;

typedef struct {
    Elemento vetor[100];
    int tamanho;
} MinHeap;

Elemento novo(int cur, int dist)
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
    if(empty(mh)) return novo(-1, -1);

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

void mostra(MinHeap * mh)
{
    printf("\n: ");
    for(int i = 0; i < mh->tamanho; i++){
        printf("%d ", mh->vetor[i].distancia);
    }
}

int main()
{
    MinHeap * heap = malloc(sizeof(MinHeap));

    push(heap, novo(1, 4));
    push(heap, novo(1, 3));
    push(heap, novo(1, 5));
    push(heap, novo(1, 2));
    push(heap, novo(1, 6));

    mostra(heap);

    printf("\n pop: %d", pop(heap).distancia);
    printf("\n pop: %d", pop(heap).distancia);
    printf("\n pop: %d", pop(heap).distancia);
    printf("\n pop: %d", pop(heap).distancia);
    printf("\n pop: %d", pop(heap).distancia);
    printf("\n pop: %d", pop(heap).distancia);

    push(heap, novo(1, 3));
    push(heap, novo(1, 1));

    mostra(heap);

    printf("\n");
    return 0;
}