#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int visitado;
	int in;
	int lower;
	int lista_adj[100];
	int tamanho_lista;
} Vertice;

void dfs_bridges(Vertice * v, int elemento, int pai);

int count = 0;

int min(int x, int y)
{
    return (x<y) ? x : y;
}

int main()
{
	int n, a, i, x, y;

	scanf("%d %d", &n, &a);

	Vertice * ver = malloc(sizeof(Vertice)*(n));

	for(i = 0; i < a; i++){
		scanf("%d %d", &x, &y);
		x--;
		y--;

		ver[x].lista_adj[ver[x].tamanho_lista++] = y;
		ver[y].lista_adj[ver[y].tamanho_lista++] = x;
	}

	dfs_bridges(ver, 0, 0);

	return 0;
}

void dfs_bridges(Vertice * v, int elemento, int pai)
{
	v[elemento].in = count;
	v[elemento].lower = count;
	v[elemento].visitado = 1;

	count++;

	for(int i = 0; i < v[elemento].tamanho_lista; i++){

		int filho = v[elemento].lista_adj[i];

		if(filho != pai){

			if(v[filho].visitado == 0){
				dfs_bridges(v, filho, elemento);
				v[elemento].lower = min(v[elemento].lower, v[filho].lower);
				if(v[filho].lower > v[elemento].in){
					printf("\n ponteeeeee %d -> %d", elemento+1, filho+1);
				}
			}else{

				v[elemento].lower = min(v[elemento].lower, v[filho].in);
			}

		}else{
			continue;
		}
	}
}