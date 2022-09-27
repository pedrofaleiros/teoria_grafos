#include <stdio.h>
#include <stdlib.h>

void mostra(int * n){
    printf("\nf: %d", *n);
    *n += 1;
}

int main(){

    int cont = 1;

    mostra(&cont);

    printf("\nfora: %d\n", cont);


    return 0;
}