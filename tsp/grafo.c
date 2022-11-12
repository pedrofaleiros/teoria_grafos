#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int valor;
	int peso;
} Elemento;

typedef struct {
	int id;
	Elemento lista_adj[100];
	int tamanho_lista;
} Vertice;

Elemento novo_elemento(int valor, int peso){
	Elemento novo;
	novo.valor = valor;
	novo.peso = peso;
	return novo;
}

int fat(int num)
{
	if(num <= 1){
		return 1;
	}else{
		return num * fat(num-1);
	}
}

void addAresta(Vertice * v, int x, int y, int peso){
	Elemento novo = novo_elemento(y, peso);

	v[x].lista_adj[ v[x].tamanho_lista++ ] = novo;

	novo = novo_elemento(x, peso);
	v[y].lista_adj[ v[y].tamanho_lista++ ] = novo;
}

//int * calcula_rota(Vertice * v, int n, int root);
void calcula_rota(Vertice * v, int n, int root);
void calcula_distancia(Vertice * v, int * visitados, int elemento, int dist_atual, int n, int root);

int menor_distacia = 9999;
int * melhor_rota;

int main()
{
	int n, x, y, peso, i, lim;

	// scanf("%d", &n);
	n = 4;

	Vertice * vertices = malloc(sizeof(Vertice)*(n));

	lim = fat(n-1);

	addAresta(vertices, 0, 1, 3);
	addAresta(vertices, 0, 2, 4);
	addAresta(vertices, 0, 3, 5);
	addAresta(vertices, 1, 2, 5);
	addAresta(vertices, 1, 3, 4);
	addAresta(vertices, 2, 3, 3);

	/* for(i = 0; i < lim; i++){
		scanf("%d %d %d", &x, &y, &peso);

		addAresta(vertices, x, y, peso);
		addAresta(vertices, y, x, peso);
	} */

	int * rota = malloc(sizeof(int)*(n+1));

	calcula_rota(vertices, n, 0);

	printf("\nMenor distancia: %d", menor_distacia);

	printf("\n");
	return 0;
}

//int * calcula_rota(Vertice * v, int n, int root)
void calcula_rota(Vertice * v, int n, int root)
{
	//int * rota = malloc(sizeof(int)*(n+1));
	int * visitados = malloc(sizeof(int)*n);
	int elemento, i, dist, dist_atual;
	melhor_rota = malloc(sizeof(int)*(n+1));

	visitados[root] = 1;

	for(i = 0; i < n; i++){
		elemento = v[root].lista_adj[i].valor;
		dist = v[root].lista_adj[i].peso;
		
		dist_atual = 0;

		calcula_distancia(v, visitados, elemento, dist_atual+dist, n, root);
	}

	//return rota;
}

void calcula_distancia(Vertice * v, int * visitados, int elemento, int dist_atual, int n, int root){

	int i, this_el, dist;

	visitados[elemento] = 1;

	int flag = 1;

	int tam = v[elemento].tamanho_lista;

	for(i = 0; i < tam; i++){
		this_el = v[elemento].lista_adj[i].valor;

		if(visitados[ this_el ] == 0){
			flag = 0;
			dist = v[elemento].lista_adj[i].peso;
			calcula_distancia(v, visitados, this_el, dist_atual+dist, n, root);
		}
	}

	if(flag == 1){

		dist = v[root].lista_adj[elemento].peso + dist_atual;

		if(dist < menor_distacia){
			menor_distacia = dist;
		}
	}
}