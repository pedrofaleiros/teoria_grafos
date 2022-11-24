#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[100];
    int lista_peso[100];
    int tamanho_lista;
} Vertice;

void addAresta(Vertice * v, int x, int y, int peso);
void mostra(Vertice * v, int n);

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

    mostra(vertices, n);

    printf("\n");
    return 0;
}

void dijkstra(Vertice * v, int n, int origem)
{
    
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