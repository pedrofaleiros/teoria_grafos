//contar componentes conectados
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
	int visitado;
	int lista[100];
	int tamanho_lista;
}vertice;

vertice * preenche_grafo(int * n, int * a);
void dfs(vertice * v, int pos)
{
	int i, aux;

	v[pos].visitado = 1;

	printf("%d ", pos);

	for(i = 0; i < v[pos].tamanho_lista; i++){ 
		aux = v[pos].lista[i];
		if(v[aux].visitado == 0){
			dfs(v, aux);
		}
	}
}

int main(){

	int n, a, i;
	vertice * v = preenche_grafo(&n, &a);

	int cont = 0;
	for(i = 0; i < n; i++){
		if(v[i].visitado == 0){
			dfs(v, i);
			cont++;
		}
	}

	printf("\nCont: %d\n", cont);

	return 0;
}

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