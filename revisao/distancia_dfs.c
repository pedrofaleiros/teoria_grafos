#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    int lista_adj[100];
    int tamanho_lista;
}Vertice;

void zera_visitados(Vertice * v, int qtd);
int dfs(Vertice * v, int pos, int distancia);

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
    
    printf("\nLista de Adjacencia");
    for(i = 1; i <= n; i++){
        printf("\n%d -> ", i);
        for(j = 0; j < v[i].tamanho_lista; j++){
            printf("%d ", v[i].lista_adj[j]);
        }
    }
    
    for(i = 1; i <= n; i++){
        if(v[i].visitado == 0){
            dfs(v, i, 0);
        }
    }

    printf("\n");
    for(i = 1; i <= n; i++){
        printf("\n%d -> %d", i, v[i].distancia);
    }

    int i_maior_dist = 1;

    for(i = 1; i <= n; i++){
        if(v[i].distancia > v[i_maior_dist].distancia){
            i_maior_dist = i;
        }
    }

    zera_visitados(v, n);

    dfs(v, i_maior_dist, 0);

    int mais_distante = i_maior_dist;

    for(i = 1; i <= n; i++){
        if(v[i].distancia > v[mais_distante].distancia){
            mais_distante = i;
        }
    }

    printf("\nMaior distancia: %d -> %d = %d", i_maior_dist, mais_distante, v[mais_distante].distancia);
    
    printf("\n");
    return 0;
}

int dfs(Vertice * v, int pos, int distancia)
{
    v[pos].visitado = 1;
    v[pos].distancia = distancia;

    for(int i = 0; i < v[pos].tamanho_lista; i++){
        int elemento = v[pos].lista_adj[i];
        if(v[ elemento ].visitado == 0){
            dfs(v, elemento, distancia+1);
        }
    }
}

void zera_visitados(Vertice * v, int qtd)
{
    for(int i = 1; i <= qtd; i++){
        v[i].visitado = 0;
        v[i].distancia = 0;
    }
}
