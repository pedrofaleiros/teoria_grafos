#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    int lista_adj[100];
    int tamanho_lista;
}Vertice;

int fila[100];
int tamanho_fila = 0;

void zera_fila(){
    for(int i = 0; i < 100; i++)
        fila[i] = 0;
    tamanho_fila = 0;
}

void push(int valor)
{
    fila[ tamanho_fila++ ] = valor;
}

int pop()
{
    if(tamanho_fila == 0)
        return 0;

    int ret = fila[0];

    for(int i = 0; i < tamanho_fila; i++){
        fila[i] = fila[i+1];
    }

    fila[tamanho_fila--] = 0;
    return ret;
}

void bfs(Vertice * v, int raiz)
{
    int cur, i;

    zera_fila();

    push(raiz);

    while(tamanho_fila > 0){
        cur = pop();

        if(v[cur].visitado == 0){
            v[cur].visitado = 1;
            printf("%d ", cur);

            for(i = 0; i < v[cur].tamanho_lista; i++){
                int elemento = v[cur].lista_adj[i];
                if(v[elemento].visitado == 0 ){
                    if(v[cur].distancia + 1 < v[elemento].distancia || v[elemento].distancia == 0){
                        v[elemento].distancia = v[cur].distancia + 1;
                    }
                }            
                push(elemento);
            }
        }
    }

}

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

    printf("\nBfs: ");
    bfs(v, 1);

    printf("\nDistancias");
    for(i = 1; i <= n; i++){
        printf("\n%d -> %d", i, v[i].distancia);
    }

    printf("\n");
    return 0;
}
