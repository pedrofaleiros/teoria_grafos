#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
	int visitado;
	int lista_adj[100];
	int tamanho_lista;
	int isMuie;
	int distancia;
}Vertice;

void dfs(Vertice * v, int pos, int distancia)
{
	v[pos].visitado = 1;
	v[pos].distancia = distancia;

	for(int i = 0 ; i < v[pos].tamanho_lista; i++){
		int el = v[pos].lista_adj[i];
		if(v[el].visitado == 0){
			dfs(v, el, distancia+1);
		}
	}
}



int main(){

	int n, i, x, y;

	scanf("%d", &n);

	Vertice * vs = malloc(sizeof(Vertice)*(n+1));

	for(i = 0; i < (n-1); i++){
		scanf("%d %d", &x, &y);
		vs[x].lista_adj[ vs[x].tamanho_lista++ ] = y;
		vs[y].lista_adj[ vs[y].tamanho_lista++ ] = x;
	}

	int q;
	scanf("%d", &q);

	for(i = 0; i < q; i++){
		scanf("%d", &x);
		vs[x].isMuie = 1;
	}

	dfs(vs, 1, 0);

	int vet[q];

	int j = 0;
	for(i = 2; i <= n; i++){
		if(vs[i].isMuie){
			vet[j] = i;
			j++;
		}
	}

	int indice_menor_dist = 0;

	for(i = 0; i < q; i++){
		if(vs[ vet[i] ].distancia < vs[vet[indice_menor_dist]].distancia){
			indice_menor_dist = vet[i];
		}
	}
	
	for(i = 0; i < q; i++){
		if(vs[ vet[i] ].distancia == vs[ vet[indice_menor_dist]].distancia){
			printf("%d", vet[i]);
			break;
		}
	}

	return 0;
}