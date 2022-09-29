#include <stdio.h>
#include <stdlib.h>

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
    if(f->qtd == 0) return 0;

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
    for(; aux != NULL; aux = aux->prox)
        printf("\n %d", aux->valor);
}

int main(){

    fila * f = malloc(sizeof(fila));

    push(f, 1);
    push(f, 2);
    push(f, 3);
    push(f, 4);

    printf("\npop %d", pop(f));
    printf("\npop %d", pop(f));
    push(f, 10);
    mostra(f);

    printf("\n");
    return 0;
}