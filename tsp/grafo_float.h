typedef struct {
	int valor;
	float peso;
} Elemento;

typedef struct {
	int id;
	Elemento lista_adj[100];
	int tamanho_lista;
} Vertice;

Elemento novo_elemento(int valor, float peso){
	Elemento novo;
	novo.valor = valor;
	novo.peso = peso;
	return novo;
}

int soma_fat(int num){
	if(num <= 1){
		return 1;
	}else{
		return num + soma_fat(num-1);
	}
}

int fat(int num)
{
	if(num <= 1){
		return 1;
	}else{
		return num * fat(num-1);
	}
}

void addAresta(Vertice * v, int x, int y, float peso){
	Elemento novo = novo_elemento(y, peso);

	v[x].lista_adj[ v[x].tamanho_lista++ ] = novo;
}
