#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
	int visitado;
	int distancia;
	int lista[100];
	int tamanho_lista;
} vertice;

vertice *preenche_grafo(int *n, int *a)
{
	int i, aux;
	vertice *v;
	scanf("%d %d", n, a);
	v = malloc(sizeof(vertice) * (*n));
	for (i = 0; i < *a; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].lista[v[x].tamanho_lista++] = y;
		v[y].lista[v[y].tamanho_lista++] = x;
	}
	return v;
}

void dfs(vertice * v, int i, int distancia){

	v[i].visitado = 1;
	v[i].distancia = distancia;

	for(int j = 0; j < v[i].tamanho_lista; j++){
		if(v[v[i].lista[j]].visitado == 0){
			dfs(v, v[i].lista[j], distancia+1);
		}
	}
}

int main()
{
	int n, a, i;
	vertice *v = preenche_grafo(&n, &a);

	dfs(v, 0, 0);

	for(i = 0; i < n; i++){
		printf("\n (%d) distancia: %d", i, v[i].distancia);
	}

	printf("\n");
	return 0;
}