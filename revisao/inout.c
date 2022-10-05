#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[100];
    int tamanho_lista;
}Vertice;

int in[100];
int out[100];
int cont = 0;

void dfs(Vertice * v, int pos);

int main(){

    Vertice * v;
    int i, j, n, a;
    scanf("%d %d", &n, &a);

    v = malloc(sizeof(Vertice) * (n+1));
    
    for(i = 0; i < a; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        
        v[x].lista_adj[ v[x].tamanho_lista++ ] = y;
        v[y].lista_adj[ v[y].tamanho_lista++ ] = x;
    }
    
    printf("\nLista de Adjacencia");
    for(i = 1; i <= n; i++){
        printf("\n%d -> ", i);
        for(j = 0; j < v[i].tamanho_lista; j++){
            printf("%d ", v[i].lista_adj[j]);
        }
    }

    dfs(v, 1);

    printf("\nIN: ");
    for(i = 1; i<= n; i++){
        printf("%d ", in[i]);
    }

    printf("\nOUT: ");
    for(i = 1; i<= n; i++){
        printf("%d ", out[i]);
    }

    int filho, pai;
    printf("\n: ");
    scanf("%d %d", &filho, &pai);

    if(in[filho] > in[pai] && out[filho] < out[pai]){
        printf("\nSIM, %d é filho de %d", filho, pai);
    }else{
        printf("\n%d nao é filho de %d", filho, pai);
    }

    printf("\n");
    return 0;
}

void dfs(Vertice * v, int pos)
{
    in[pos] = cont++;
    v[pos].visitado = 1;

    for(int i = 0; i < v[pos].tamanho_lista; i++){
        int elemento = v[pos].lista_adj[i];
        if(v[ elemento ].visitado == 0){
            dfs(v, elemento);
        }
    }
    out[pos] = cont++;
}