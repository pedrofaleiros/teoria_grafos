#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int visitado;
	int lista_adj[100];
	int tamanho_lista;
}Vertice;

int dfs(Vertice * v, int pos, int pai){
	v[pos].visitado = 1;

	int hasBE = 0;
	for(int i = 0 ; i < v[pos].tamanho_lista; i++){
		int el = v[pos].lista_adj[i];

		if(v[el].visitado == 0){
			hasBE = dfs(v, el, pos);
		}else if(pai != el){
			hasBE = 1;
		}

	}
	return hasBE;
}

int main(){

	int n, a, i, x, y;

	scanf("%d %d", &n, &a);

	Vertice * vs = malloc(sizeof(Vertice)*(n+1));

	for(i = 0; i < a; i++){
		scanf("%d %d", &x, &y);
		vs[x].lista_adj[ vs[x].tamanho_lista++ ] = y;
		vs[y].lista_adj[ vs[y].tamanho_lista++ ] = x;
	}

	printf("\n hasBAckEdge: %d", dfs(vs, 1,0));

	printf("\n");
	return 0;
}