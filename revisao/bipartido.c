#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int cor;
    int lista_adj[100];
    int tamanho_lista;
}Vertice;

void zera_visitados(Vertice * v, int qtd);
int dfs(Vertice * v, int pos, int cor);

int main() {

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
    
    for(i = 1; i <= n; i++){
        printf("\n%d -> ", i);
        for(j = 0; j < v[i].tamanho_lista; j++){
            printf("%d ", v[i].lista_adj[j]);
        }
    }
    
    int bipartido = 1;
    for(i = 1; i <= n; i++){
        if(v[i].visitado == 0){
            if(!dfs(v, i, 0)){
                bipartido = 0;
            }
        }
    }
    
    printf("\nBipartido: %d", bipartido);
    
    printf("\n");
    return 0;
}

int dfs(Vertice * v, int pos, int cor)
{
    v[pos].visitado = 1;
    v[pos].cor = cor;
    //printf("%d ", pos);
    
    int bipartido = 1;
    for(int i = 0; i < v[pos].tamanho_lista; i++){
        int elemento = v[pos].lista_adj[i];
        if(v[ elemento ].visitado == 0){
            bipartido = dfs(v, elemento, !cor);
        }

        if(v[pos].cor == v[elemento].cor){
            bipartido = 0;
        }
    }

    return bipartido;
}

void zera_visitados(Vertice * v, int qtd)
{
    for(int i = 1; i <= qtd; i++){
        v[i].visitado = 0;
        v[i].cor = 0;
    }
}
