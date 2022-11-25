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

void mostra(MinHeap * mh)
{
    printf("\n heap: ");
    if(empty(mh)) printf("---");
    for(int i = 0; i < mh->tamanho; i++){
        printf("%d ", mh->vetor[i].distancia);
    }
}

int main()
{
    MinHeap * heap = malloc(sizeof(MinHeap));
    char c[2];
    int x = 1, dist;

    while(x == 1){
        printf("\n> ");
        scanf("%s", c);

        switch (c[0])
        {
        case 'a':
            printf("\npush: ");
            scanf("%d", &dist);

            push(heap, novo_elemento(0, dist));
            break;
        case 'r':
            printf("\npop: %d", pop(heap).distancia);
            break;
        case 'm':
            mostra(heap);
            break;
        case 'z':
            x = 0;
            break;
        default:
            break;
        }
    }

    printf("\n");
    return 0;
}