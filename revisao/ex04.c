#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
	int visitado;
	int distancia;
	int lista[100];
	int tamanho_lista;
}vertice;

void zera_visitados(vertice * v, int qtd)
{
	for(int i = 1; i <= qtd; i++){
		v[i].visitado == 0;
		v[i].distancia = 0;
	}
}

vertice * preenche_grafo(int * n, int * a){
	int i, aux;
	vertice * v;
	scanf("%d %d", n, a);
	v = malloc(sizeof(vertice)*(*n + 1));
	for(i = 0; i < *a + 1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].lista[v[x].tamanho_lista++] = y;
		v[y].lista[v[y].tamanho_lista++] = x;
	}
	return v;
}

void dfs(vertice * v, int i, int distancia)
{
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
	vertice * v = preenche_grafo(&n, &a);

	dfs(v, 1, 0);

	int maior = 1;
	for(i = 1; i <= n; i++){
		if(v[i].distancia > v[maior].distancia){
			maior = i;
		}
	}

	zera_visitados(v, n);

	dfs(v, maior, 0);

	int distante = 1;
	for(i = 1; i <= n; i++){
		if(v[i].distancia > v[distante].distancia){
			distante = i;
		}
	}

	printf("\n> maior distancia %d: %d -> %d\n", v[distante].distancia, maior, distante);

	return 0;
}