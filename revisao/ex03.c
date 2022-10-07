#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
	int visitado;
	int hasGirl;
	int distancia;
	int lista[100];
	int tamanho_lista;
} vertice;

void dfs(vertice *v, int i, int distancia)
{

	v[i].visitado = 1;
	v[i].distancia = distancia;

	for (int j = 0; j < v[i].tamanho_lista; j++)
	{
		if (v[v[i].lista[j]].visitado == 0)
		{
			dfs(v, v[i].lista[j], distancia + 1);
		}
	}
}

typedef struct lista
{
	struct elemento *inicio;
} lista;

typedef struct elemento
{
	int valor;
	struct elemento *prox;
} elemento;

elemento *elemento_alloc()
{
	elemento *novo = malloc(sizeof(elemento));
	novo->prox = NULL;
	novo->valor = 0;
	return novo;
}

lista *lista_alloc()
{
	lista *nova = malloc(sizeof(lista));
	nova->inicio == NULL;
	return nova;
}

void inclui_lista(lista *l, int valor)
{
	if (l == NULL)
		return;

	elemento *aux = NULL, *ant = NULL;
	elemento *novo;
	novo = elemento_alloc();
	novo->valor = valor;

	if (l->inicio != NULL)
	{
		aux = l->inicio;
		int inserido = 0;
		while(aux != NULL && !inserido){
			if(aux->valor == novo->valor) return;
			if(novo->valor > aux->valor){
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
	else
	{
		l->inicio = novo;
	}
}

int main()
{

	int n, i, x, y;
	vertice *v;

	scanf("%d", &n);

	v = malloc(sizeof(vertice) * (n + 1));

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);

		v[x].lista[v[x].tamanho_lista++] = y;
		v[y].lista[v[y].tamanho_lista++] = x;
	}

	int q;
	scanf("%d", &q);

	for (i = 0; i < q; i++)
	{
		scanf("%d", &x);

		v[x].hasGirl = 1;
	}

	dfs(v, 1, 0);

	int menor = n;
	for (i = 2; i <= n; i++)
	{
		if (v[i].hasGirl)
		{
			if (v[i].distancia < menor)
			{
				menor = v[i].distancia;
			}
		}
	}

	lista *m = lista_alloc();
	for (i = 2; i <= n; i++)
	{
		if (v[i].hasGirl && v[i].distancia == menor)
		{
			inclui_lista(m, i);
		}
	}

	printf("%d", m->inicio->valor);
	return 0;
}
