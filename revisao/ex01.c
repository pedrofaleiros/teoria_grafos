//mostra lista de adj
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
	int visitado;
	int lista[100];
	int tamanho_lista;
}vertice;

vertice * preenche_grafo(int * n, int * a){
	int i, aux;
	vertice * v;
	scanf("%d %d", n, a);
	v = malloc(sizeof(vertice)*(*n));
	for(i = 0; i < *a; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].lista[v[x].tamanho_lista++] = y;
		v[y].lista[v[y].tamanho_lista++] = x;
	}
	return v;
}

int main()
{
	int n, a, i;
	vertice * v = preenche_grafo(&n, &a);

	for(i = 0; i < n; i++){
		printf("\n %d -> ", i);
		for(int j = 0; j < v[i].tamanho_lista; j++){
			printf("%d ", v[i].lista[j]);
		}
	}

	printf("\n");
	return 0;
}