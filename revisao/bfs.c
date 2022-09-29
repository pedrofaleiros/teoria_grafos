#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    int lista_adj[100];
    int tamanho_lista;
}vertice;

void mostra_grafo(vertice * v, int n);
typedef struct e{
    int valor;
    struct e * prox;
}e;

typedef struct fila{
    int qtd;
    struct e * inicio;
    struct e * final;
}fila;

void push(fila *f, int valor)
{
    e * novo = malloc(sizeof(e));
    novo->valor = valor;

    if(f->inicio == NULL){
        f->inicio = novo;
        f->final = novo;
    }else{
        e * aux = f->inicio;

        while(aux->prox != NULL)
            aux = aux->prox;
        
        aux->prox = novo;
        f->final = novo;
    }

    f->qtd++;
}

int pop(fila * f)
{
    if(f->qtd == 0) return -1;

    int ret;
    if(f->qtd == 1){
        ret = f->inicio->valor;

        f->inicio = NULL;
        f->final = NULL;
    }else{
        e * aux = f->inicio;

        ret = aux->valor;

        f->inicio = aux->prox;

        free(aux);
    }
    f->qtd--;
    return ret;
}

void mostra(fila * f)
{
    e * aux = f->inicio;
    while(aux!=NULL){
        printf("\n %d", aux->valor);
        aux = aux->prox;
    }
}

void bfs(vertice * v, int pos)
{
    fila * f = malloc(sizeof(fila));
    int cur, i;

    push(f, pos);

    while(f->qtd > 0){
        cur = pop(f);
        if(v[cur].visitado == 0){
            printf("%d ", cur);
            v[cur].visitado = 1;
            for(i = 0; i < v[cur].tamanho_lista; i++)
                push(f, v[cur].lista_adj[i]);
        }
    }
}


void bfs_distancia(vertice * v, int pos)
{
    fila * f = malloc(sizeof(fila));
    int cur, i, filho;

    push(f, pos);

    while(f->qtd > 0){
        cur = pop(f);
        v[cur].visitado = 1;

        for(i = 0; i < v[cur].tamanho_lista; i++){
            filho = v[cur].lista_adj[i];
            if(v[filho].visitado == 0){
                if(v[filho].distancia == 0 || v[filho].distancia > v[cur].distancia+1)
                    v[filho].distancia = v[cur].distancia+1;
                push(f, filho);
            }
        }
    }
}

int main(){

    int n, i, x, y;
    vertice * vertices;

    scanf("%d", &n);

    vertices = malloc(sizeof(vertice)*(n+1));

    while(1){
        scanf("%d %d", &x, &y);

        if(x == 0 || y == 0) break;

        vertices[x].lista_adj[ vertices[x].tamanho_lista++ ] = y;
        vertices[y].lista_adj[ vertices[y].tamanho_lista++ ] = x;
    }


    printf("\nbfs: ");
    bfs_distancia(vertices, 1);

    mostra_grafo(vertices, n);

    printf("\n");
    return 0;
}

void mostra_grafo(vertice * v, int n)
{
    for(int i = 1; i <= n; i++){
        printf("\n%d -> %d", i, v[i].distancia);
        /* for(int j = 0; j < v[i].tamanho_lista; j++){
            printf("%d ", v[i].lista_adj[j]);
        } */
    }
}