#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int elementos[1000];
    int tamanho;
    int (*pop)(struct * pilha);
    void (*push)(struct * pilha, int valor);
    void (*mostra)(struct * pilha);

}pilha;

int pop(pilha * p)
{
    int ret;
    ret = p->elementos[ p->tamanho--];
    return ret;
}

void push(pilha * p, int valor)
{
    p->elementos[ p->tamanho ] = valor;
    p->tamanho++;
}

void mostra(pilha * p)
{
    for(int i = 0; i < p->tamanho; i++)
    {
        printf("\n %d", p->elementos[i]);
    }
}



int main(){

    pilha * p = aloca_pilha();


    return 0;
}