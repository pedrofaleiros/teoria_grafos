#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int tamanho_lista;
    int * lista_adj;
    int in;
    int lower;
} Vertice;

Vertice * aloca_vertices(int n)
{
    Vertice * novo = malloc(sizeof(Vertice)*(n+1));

    for(int i = 0; i <= n; i++)
    {
        novo[i].lista_adj = malloc(sizeof(int)*n);
        novo[i].tamanho_lista = 0;
        novo[i].visitado      = 0;
        novo[i].lower         = 0;
        novo[i].in            = 0;
    }

    return novo;
}

void add_aresta(Vertice * v, int x, int y)
{
    v[x].lista_adj[ v[x].tamanho_lista++ ] = y;
}

void mostra(Vertice * v, int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("\n%d -> ", i);
        for(int j = 0; j < v[i].tamanho_lista; j++)
        {
            printf("%d ", v[i].lista_adj[j]);
        }
    }
}

int cc = 0;

void dfs_bridges(Vertice * v, int n, int pai);
int min(int x, int y);

int main()
{
    int n, i, x, y;

    scanf("%d", &n);
    Vertice * vertices = aloca_vertices(n);

    while(1)
    {
        scanf("%d %d", &x, &y);

        if(x == 0 || y == 0) break;

        add_aresta(vertices, x, y);
        add_aresta(vertices, y, x);
    }

    dfs_bridges(vertices, 1, 0);

    printf("\n  in: ");
    for(i = 1; i <= n; i++){
        printf("%d ", vertices[i].in);
    }

    printf("\n out: ");
    for(i = 1; i <= n; i++){
        printf("%d ", vertices[i].lower);
    }

    printf("\n");
    return 0;
}

int min(int x, int y)
{
    return x < y ? x: y;
}

void dfs_bridges(Vertice * v, int n, int pai)
{
    v[n].visitado = 1;
    v[n].in = cc;
    v[n].lower = cc;
    cc++;

    for(int i = 0; i < v[n].tamanho_lista; i++){
        int filho = v[n].lista_adj[i];

        if(filho != pai){

            if(v[filho].visitado == 0){
                dfs_bridges(v, filho, n);

                if(v[filho].lower > v[n].in){
                    printf("\nPonte: %d -> %d", n, filho);
                }

                if(v[n].lower > v[filho].lower)
                    v[n].lower = v[filho].lower;
            }else{

                if(v[n].lower > v[filho].in)
                    v[n].lower = v[filho].in;
            }
        }
    }
}