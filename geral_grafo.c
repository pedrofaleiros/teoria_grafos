#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

typedef struct Vertice{
	int visitado;
	int distancia;
	int cor;
	struct Lista * lista_adj;
}Vertice;

typedef struct Lista{
	struct elemento * inicio;
}Lista;

typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;

elemento * aloca_elemento();
void mostra_lista(Lista * lista);
void inclui_elemento(Lista * l, int valor);
Lista * aloca_lista();
Vertice * aloca_vertices(int qtd);
void zera_valores(Vertice * v, int qtd);
void inclui_aresta(Vertice * v, int valor);
void mostra_grafo(Vertice * v, int qtd);
void preenche(Vertice * v, int qtd);
bool is_tree(Vertice * v, int qtd_v, int qtd_a);
bool dfs(Vertice * v, int i, int distancia, int cor);
void mostra_distancia(Vertice * v, int pos, int qtd);

int main(int argc, char * argv[]){

	int i, n, a;
	Vertice * vertices;

	scanf("%d %d", &n, &a);

	vertices = aloca_vertices(n);
	preenche(vertices, a);

	is_tree(vertices, n, a) ? 
	printf("\n ARVORE") : 
	printf("\n NAO");

	zera_valores(vertices, n);

	dfs(vertices, 1, 0, 0) ? 
	printf("\n Bipartido") : 
	printf("\n NAO");

	printf("\nDistancias:");
	mostra_distancia(vertices, 1, n);

	printf("\n");
	return 0;
}

void mostra_distancia(Vertice * v, int pos, int qtd){

	zera_valores(v, qtd);
	dfs(v, pos, 0, 0);

	for(int i = 1; i <= qtd; i++){
		printf("\n %d -> %d: %d", pos, i, v[i].distancia);
	}

}

bool dfs(Vertice * v, int i, int distancia, int cor){

	v[i].visitado = 1;
	v[i].distancia = distancia;
	v[i].cor = cor;

	bool ret = true;
	if(v[i].lista_adj != NULL){

		elemento * aux;
		aux = v[i].lista_adj->inicio;

		while(aux != NULL){

			if(v[aux->valor].visitado == 0){
				ret = dfs(v, aux->valor, distancia+1, !cor);
			}

			if(v[i].cor == v[aux->valor].cor){
				return false;
			}

			aux = aux->prox;
		}
	}

	return ret;
}

bool is_tree(Vertice * v, int qtd_v, int qtd_a){

	if(qtd_a != qtd_v-1) return false;

	int cont = 0;

	for(int i = 1; i <= qtd_v; i++){
		if(v[i].visitado == 0){
			dfs(v, i, 0, 0);
			cont++;
		}
	}

	return cont == 1;
}

void preenche(Vertice * v, int qtd){
	for(int i = 0; i < qtd; i++){
		int x, y;

		scanf("%d %d", &x, &y);

		inclui_aresta(&v[x], y);
		inclui_aresta(&v[y], x);
	}
}

void mostra_grafo(Vertice * v, int qtd){
	for(int i = 1; i <= qtd; i++){
		printf("\n %d -> ", i);
		mostra_lista(v[i].lista_adj);
	}
}

void zera_valores(Vertice * v, int qtd){

	for(int i = 0; i <= qtd; i++){
		v[i].cor = 0;
		v[i].distancia = 0;
		v[i].visitado = 0;
	}
}

void inclui_aresta(Vertice * v, int valor){
	if(v->lista_adj == NULL)
		v->lista_adj = aloca_lista();
	inclui_elemento(v->lista_adj, valor);
}

Vertice * aloca_vertices(int qtd){
	Vertice * novo;
	novo = malloc(sizeof(Vertice) * (qtd+1) );
	return novo;
}

void inclui_elemento(Lista * l, int valor){

	elemento * novo;
	novo = aloca_elemento();
	novo->valor = valor;

	if(l->inicio == NULL){
		l->inicio = novo;
	}else{
		elemento * aux, * ant = NULL;

		aux = l->inicio;
		
        int inserido = 0;
        while(aux != NULL && !inserido){
            if(aux->valor == novo->valor) return;
            if(aux->valor < novo->valor){
                ant = aux;
                aux = aux->prox;
            }else{
                if(ant != NULL)
                    ant->prox = novo;
                else
                    l->inicio = novo;
                novo->prox = aux;
                inserido = 1;
            }
        }
        if(!inserido){
            ant->prox = novo;
        }
	}
}

void mostra_lista(Lista * lista){
	
	if(lista->inicio == NULL) return;
	
	elemento * aux;
	aux = lista->inicio;

	while(aux != NULL){
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
}

elemento * aloca_elemento(){
	elemento * novo;
	novo = malloc(sizeof(elemento));
	return novo;
}

Lista * aloca_lista(){
	Lista * nova;
	nova = malloc(sizeof(Lista));
	return nova;
}