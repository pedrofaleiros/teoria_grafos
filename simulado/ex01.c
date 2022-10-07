#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    int lista_adj[100];
    int tamanho_lista;
}Vertice;

void dfs(Vertice * v, int pos, int distancia)
{
    v[pos].visitado = 1;
    v[pos].distancia = distancia;

    for(int i = 0; i < v[pos].tamanho_lista; i++){
        int elemento = v[pos].lista_adj[i];
        if(v[elemento].visitado == 0){
            dfs(v, elemento, distancia+1);
        }
    }
}

void zera(Vertice * v, int qtd)
{
    while(qtd >= 0){
        v[qtd].visitado = 0;
        v[qtd].distancia = 0;
        qtd--;
    }
}

int main()
{
    int q, v, i, x, y;
    scanf("%d", &q);
    scanf("%d", &v);

    Vertice * vertices = malloc(sizeof(Vertice)*(q+1));

    for(i = 0; i < v; i++){
        scanf("%d %d", &x, &y);

        vertices[x].lista_adj[ vertices[x].tamanho_lista++ ] = y;
        vertices[y].lista_adj[ vertices[y].tamanho_lista++ ] = x;
    }

    int c;

    scanf("%d", &c);

    for(i = 0; i < c; i++){
        scanf("%d %d", &x, &y);

        zera(vertices, q);

        dfs(vertices, x, 0);

        printf("\n%d", vertices[y].distancia);
    }

    return 0;
}