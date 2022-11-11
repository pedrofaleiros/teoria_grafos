#include "arvore_binaria.h"

#define LISTA_ADJ 0
#define LISTA_PESOS 1
#define INF 9999

typedef struct {
    int distancia;
    int lista_adj[2][100];
    int tamanho_lista;
} Vertice;

void addEdge(Vertice * v, int x, int y, int peso){
    int tam = v[x].tamanho_lista++;
    v[x].lista_adj[LISTA_ADJ][tam] = y;
    v[x].lista_adj[LISTA_PESOS][tam] = peso;
}

void mostra_grafo(Vertice * v, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("\n%d -> ", i);
        for(int j = 0; j < v[i].tamanho_lista; j++){
            printf("%d ", v[i].lista_adj[LISTA_ADJ][j]);
        }
    }
}

void preenche_dist(Vertice * v, int num_v){
    while(num_v > 0){
        v[num_v-1].distancia = INF;
        num_v--;
    }
}

int * dijkstra(Vertice * v, int root, int num_v){
    Node * queue = NULL;
    Retorno aux;
    int cur, dist, i, elemento;

    preenche_dist(v, num_v);
    v[root].distancia = 0;
    queue = incluir(queue, nova_dupla(root, 0));

    while(queue != NULL){
        aux = pop(queue);
        queue = aux.new_raiz;

        cur = aux.data.cur;
        dist = aux.data.dist;

        for(i = 0; i < v[cur].tamanho_lista; i++){
            elemento = v[cur].lista_adj[LISTA_ADJ][i];

            if(dist + v[cur].lista_adj[LISTA_PESOS][i] < v[elemento].distancia){
                v[elemento].distancia = dist + v[cur].lista_adj[LISTA_PESOS][i];
                queue = incluir(queue, nova_dupla(elemento, v[elemento].distancia));
            }
        }
    }

    for(i = 0; i < num_v; i++){
        printf("\ndistancia %d : %d", i, v[i].distancia);
    }

}

int main()
{
    int n, i, x, y, peso;
    Vertice * vertices;
    scanf("%d", &n);

    vertices = malloc(sizeof(Vertice)*(n));

    while(1){
        scanf("%d %d %d", &x, &y, &peso);

        if(x == -1) break;

        addEdge(vertices, x, y, peso);
        addEdge(vertices, y, x, peso);
    }

    mostra_grafo(vertices, n);
    dijkstra(vertices, 0, n);

    printf("\n");
    return 0;
}