#include <stdio.h>
#include <stdlib.h>

int fila[100];
int tamanho_fila = 0;

typedef struct vertice{
    int visitado;
    int distancia;
    int lista_adj[100];
    int tamanho_lista;
}Vertice;

void zera_fila()
{
    for(int i = 0; i < 100; i++) fila[i] = 0;
    tamanho_fila = 0;
}
void zera_visitados(Vertice * v, int qtd);
void push(int valor);
int pop();
void mostra();
void dfs(Vertice * v, int pos);
void bfs(Vertice * v, int pos);

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
    
    printf("\nDFS: ");
    dfs(v, 1);
    
    zera_visitados(v, n);
    
    printf("\nBFS: ");
    bfs(v, 1);
    
    printf("\n");
    return 0;
}

void zera_visitados(Vertice * v, int qtd)
{
    for(int i = 1; i <= qtd; i++){
        v[i].visitado = 0;
        v[i].distancia = 0;
    }
}

void bfs(Vertice * v, int pos)
{
    zera_fila();
    int i, current;
    
    push(pos);
    
    while(tamanho_fila > 0){
        
        current = pop();
        
        if(v[current].visitado == 0){
            
            v[current].visitado = 1;
            printf("%d ", current);
            
            for(i = 0; i < v[current].tamanho_lista; i++){
                push(v[current].lista_adj[i]);
            }
        }
    }
    
}

void dfs(Vertice * v, int pos)
{
    v[pos].visitado = 1;
    printf("%d ", pos);
    
    for(int i = 0; i < v[pos].tamanho_lista; i++){
        int elemento = v[pos].lista_adj[i];
        if(v[ elemento ].visitado == 0){
            dfs(v, elemento);
        }
    }
}

void push(int valor)
{
    fila[ tamanho_fila++ ] = valor;
}

int pop()
{
    if(tamanho_fila == 0) return 0;
    int ret = fila[0];
    
    for(int i = 0; i < tamanho_fila; i++){
        fila[i] = fila[i+1];
    }
    fila[tamanho_fila] = 0;
    tamanho_fila--;
    return ret;
}

void mostra()
{
    for(int i = 0; i < tamanho_fila;i++) printf("%d ", fila[i]);
}