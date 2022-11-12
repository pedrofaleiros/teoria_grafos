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