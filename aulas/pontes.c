#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int visitado;
	int lista_adj[100];
	int tamanho_lista;
}Vertice;

void dfs(Vertice * v, int pos, int pai);

int * in;
int * lower;
int cc = 0;

int min(int x, int y){
	if(x < y) 
		return x;
	return y;
}

int main(){

	int n, a, i, x, y;

	scanf("%d %d", &n, &a);

	in = malloc(sizeof(int)*(n+1));
	lower = malloc(sizeof(int)*(n+1));

	Vertice * vertices = malloc(sizeof(Vertice)*(n+1));

	for(i = 0; i < a; i++){
		scanf("%d %d", &x, &y);
		vertices[x].lista_adj[ vertices[x].tamanho_lista++ ] = y;
		vertices[y].lista_adj[ vertices[y].tamanho_lista++ ] = x;
	}

	dfs(vertices, 1, 0);

	printf("\n");
	return 0;
}

void dfs(Vertice * v, int pos, int pai)
{
	in[pos] = cc;
	lower[pos] = cc;
	cc++;

	v[pos].visitado = 1;

	for(int i = 0; i < v[pos].tamanho_lista; i++){
		int filho = v[pos].lista_adj[i];

		if(v[filho].visitado == 0){
			dfs(v, filho, pos);

			if(lower[filho] > in[pos]){
				//ponte
				printf("\nPonte: %d -> %d", pos, filho);
			}else{
				lower[pos] = min(lower[pos], lower[filho]);
			}
		}else{
			if(filho != pai){
				lower[pos] = min(lower[pos], in[filho]);
			}
		}
	}
}