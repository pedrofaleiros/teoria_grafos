#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado;
    int distancia;
    int cor;
    int lista_adj[100];
    int tamanho_lista;
}vertice;

int dfs_distancia(vertice * v, int i, int distancia);
int dfs_bipartido(vertice * v, int i, int cor);
int dfs_inout(vertice * v, int i, int * in, int * out, int * count);
int dfs_backedge(vertice * v, int i, int pai);

int main(){

    int n, a, x, y, i;

    scanf("%d", &n);

    vertice * v = malloc(sizeof(vertice)*(n+1));

    //for(i = 0; i < a; i++){
    while(1){
        scanf("%d %d", &x, &y);

        if(x == 0 || y == 0) break;
        v[x].lista_adj[ v[x].tamanho_lista++ ] = y;
        v[y].lista_adj[ v[y].tamanho_lista++ ] = x;
    }

    printf("\n%d", dfs_backedge(v, 1, 0));

    //IN OUT
    /* int count = 1, in[n+1], out[n+1];
    int el, pai;
    scanf("%d %d", &el, &pai);
    if(in[el] > in[pai] && out[el] < out[pai]){
        printf("\n%d é filho de %d", el, pai);
    }else{
        printf("\n%d NAO é filho de %d", el, pai);
    } */

    printf("\n");
    return 0;
}

int dfs_inout(vertice * v, int i, int * in, int * out, int * count)
{
    in[i] = *count;
    *count += 1;

    v[i].visitado = 1;

    for(int j = 0; j < v[i].tamanho_lista; j++){
        int elemento = v[i].lista_adj[j];
        if(v[ elemento ].visitado == 0){
            dfs_inout(v, elemento, in, out, count);
        }
    }


    out[i] = *count;
    *count += 1;
}

int dfs_bipartido(vertice * v, int i, int cor)
{

    v[i].visitado = 1;
    v[i].cor = cor;

    int bipartido = 1;

    for(int j = 0; j < v[i].tamanho_lista; j++){

        int elemento = v[i].lista_adj[j];
        if(v[ elemento ].visitado == 0){
            bipartido = dfs_bipartido(v, elemento, !cor);
        }else{
            if(v[ elemento ].cor == cor){
                bipartido = 0;
            }
        }
    }
    return bipartido;
}

int dfs_distancia(vertice * v, int i, int distancia)
{
    v[i].visitado = 1;
    v[i].distancia = distancia;

    for(int j = 0; j < v[i].tamanho_lista; j++){

        int elemento = v[i].lista_adj[j];
        if(v[ elemento ].visitado == 0){
            dfs_distancia(v, elemento, distancia+1);
        }
    }
}

int dfs_backedge(vertice * v, int i, int pai)
{
    v[i].visitado = 1;

    int hasBE = 0;

    for(int j = 0; j < v[i].tamanho_lista; j++){
        int elemento = v[i].lista_adj[j];

        if(v[ elemento ].visitado == 0){
            hasBE = dfs_backedge(v, elemento, i);
        }else{
            if(pai != elemento){
                hasBE = 1;
            }
        }
    }

    return hasBE;
}
