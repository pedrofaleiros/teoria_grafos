#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cur;
    int dist;
} Dupla;

typedef struct node {
    Dupla valores;
    struct node * esq;
    struct node * dir;
} Node;

typedef struct {
    Dupla data;
    Node * new_raiz;
} Retorno;

int empty(Node * raiz){
    return raiz == NULL;
}

Node * incluir(Node * node, Dupla d)
{
    if(node == NULL){
        Node * novo;
        novo = malloc(sizeof(Node));
        novo->valores = d;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }else{
        if(d.dist > node->valores.dist){
            node->dir = incluir(node->dir, d);
        }else{
            node->esq = incluir(node->esq, d);
        }
    }
    return node;
}

Dupla nova_dupla(int cur, int dist){
    Dupla nova;
    nova.cur = cur;
    nova.dist = dist;
    return nova;
}

void mostra(Node * node)
{
    if(node != NULL){
        printf("%d:%d\n", node->valores.cur, node->valores.dist);
        mostra(node->esq);
        mostra(node->dir);
    }
}

Retorno pop(Node * node)
{
    Retorno ret;
    ret.data = nova_dupla(-1, -1);
    ret.new_raiz = NULL;
    
    if(node == NULL) return ret;
    
    Node * aux = node;
    Node * ant = NULL;
    while(aux->esq != NULL){
        ant = aux;
        aux = aux->esq;
    }

    ret.data = aux->valores;
    if(ant == NULL){
        ret.new_raiz = aux->dir;
    }else{
        ant->esq = aux->dir;
        //a.new_raiz = ant;
        ret.new_raiz = node;
    }

    return ret;
}

/* int main()
{
    Node * raiz = NULL;
    Retorno a;
    
    raiz = incluir(raiz, nova_dupla(1, 1));
    raiz = incluir(raiz, nova_dupla(1, 2));
    raiz = incluir(raiz, nova_dupla(1, 3));
    raiz = incluir(raiz, nova_dupla(1, 4));
    raiz = incluir(raiz, nova_dupla(1, 5));

    mostra(raiz);

    raiz = pop(raiz).new_raiz;

    printf("\n");

    mostra(raiz);

    return 0;
} */