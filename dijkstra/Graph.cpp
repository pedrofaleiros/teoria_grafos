#include <iostream>
#include <stdlib.h>

using namespace std;

class Vertice
{
public:
	Vertice(){

	}

	int getVisitado(){
		return this->visitado;
	}

	void setVisitado(int x){
		this->visitado = x;
	}

	int getDistancia(){
		return this->distancia;
	}

	void setDistancia(int x){
		this->distancia = x;
	}

	int getTamanhoLista(){
		return this->tamanho_lista;
	}

	void addAresta(int x, int peso){
		this->lista_adj[ getTamanhoLista() ] = x;
		this->lista_pesos[ getTamanhoLista()] = peso;

		this->tamanho_lista++;
	}

	void mostra(int i){
		cout << i << " -> ";
		for(int j = 0; j < getTamanhoLista(); j++){
			cout << "(" << this->lista_adj[j] << ", " << this->lista_pesos[j] << ") ";
		}
		cout << endl;
	}


private:
	int visitado;
	int distancia;
	int lista_adj[100];
	int lista_pesos[100];
	int tamanho_lista;
};

class Graph
{
public:
	Graph(int n)
	{
		this->num_vertices = n;
	}

	void addAresta(int x, int y, int peso){
		this->vertices[x].addAresta(y, peso);
		this->vertices[y].addAresta(x, peso);
	}

	void mostra(){
		for(int i = 1; i <= this->num_vertices; i++){
			this->vertices[i].mostra(i);
		}
	}

private:
	int num_vertices;
	Vertice vertices[100];
};

int main()
{
	Graph g = Graph(5);

	g.addAresta(1, 2, 0);
	g.addAresta(1, 3, 0);
	g.addAresta(2, 4, 0);
	g.addAresta(3, 5, 0);

	g.mostra();

	return 0;
}