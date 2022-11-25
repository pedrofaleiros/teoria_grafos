#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int visitado;
    int lista_adj[100];
    int tamanho;
    int in;
    int lower;
} Vertice;

void mostra(Vertice * v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\n%d -> ", i+1);
        for(int j = 0; j < v[i].tamanho; j++)
        {
            printf("%d ", v[i].lista_adj[j]+1);
        }
    }
}

void bridges(Vertice * v, int elemento, int pai);
int min(int x, int y);

int cc = 0;

int main()
{
    int n, i, j, x, y;
    Vertice * vertices;

    scanf("%d", &n);

    vertices = malloc(sizeof(Vertice)*n);

    while(1){
        scanf("%d %d", &x, &y);

        if(x == 0)break;

        x--;
        y--;

        vertices[x].lista_adj[ vertices[x].tamanho++ ] = y;
        vertices[y].lista_adj[ vertices[y].tamanho++ ] = x;
    }

    // mostra(vertices, n);

    bridges(vertices, 0, -1);

    // printf("\n");
    return 0;
}

void bridges(Vertice * v, int elemento, int pai)
{
    int i, filho;

    v[elemento].visitado = 1;
    v[elemento].in    = cc;
    v[elemento].lower = cc;
    cc++;

    for(i = 0; i < v[elemento].tamanho; i++){
        filho = v[elemento].lista_adj[i];
        if(filho != pai){
            if(v[filho].visitado == 0){
                bridges(v, filho, elemento);
                v[elemento].lower = min(v[elemento].lower, v[filho].lower);
                if(v[filho].lower > v[elemento].in){
                    printf("A estrada de que conecta a cidade %d a %d não pode entrar em reforma\n", elemento+1, filho+1);
                }
            }else{
                v[elemento].lower = min(v[elemento].lower, v[filho].in);
            }
        }else{
            continue;
        }
    }
}

int min(int x, int y)
{
    return (x<y) ? x : y;
}