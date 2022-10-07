#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int visitado;
	int lista_adj[100];
	int tamanho_lista;
	int isMacho;
}Vertice;

int dfs(Vertice * v, int pos, int isMacho){
	v[pos].visitado = 1;
	v[pos].isMacho = isMacho;

	int isBipartido = 1;
	for(int i = 0 ; i < v[pos].tamanho_lista; i++){
		int el = v[pos].lista_adj[i];
		
		if(v[el].visitado == 0){
			isBipartido = dfs(v, el, !isMacho);
		}

		if(v[el].isMacho == isMacho){
			isBipartido = 0;
		}

	}
	return isBipartido;
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

	int isB = 1;
	for(i = 1; i <= n ;i++){
		if(vs[i].visitado == 0){
			if(!dfs(vs, i, 0)){
				isB = 0;
			}
		}
	}

	printf("\n %d", isB);

	printf("\n");
	return 0;
}