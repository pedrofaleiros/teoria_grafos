#include <iostream>
#include <stdlib.h>
#include "MinHeap.h"

using namespace std;

class Vertice
{
public:
	Vertice()
	{
	}

	int getVisitado()
	{
		return this->visitado;
	}

	void setVisitado(int x)
	{
		this->visitado = x;
	}

	int getDistancia()
	{
		return this->distancia;
	}

	void setDistancia(int x)
	{
		this->distancia = x;
	}

	int getTamanhoLista()
	{
		return this->tamanho_lista;
	}

	void addAresta(int x, int peso)
	{
		this->lista_adj[getTamanhoLista()] = x;
		this->lista_pesos[getTamanhoLista()] = peso;

		this->tamanho_lista++;
	}

	void mostra(int i)
	{
		cout << i << " -> ";
		for (int j = 0; j < getTamanhoLista(); j++)
		{
			cout << "(" << this->lista_adj[j] << ", " << this->lista_pesos[j] << ") ";
		}
		cout << endl;
	}

	int getElementoLista(int indice){
		return this->lista_adj[indice];
	}

	int getPesoElemento(int indice){
		return this->lista_pesos[indice];
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

	void addAresta(int x, int y, int peso)
	{
		this->vertices[x].addAresta(y, peso);
		this->vertices[y].addAresta(x, peso);
	}

	void mostra()
	{
		for (int i = 1; i <= this->num_vertices; i++)
		{
			this->vertices[i].mostra(i);
		}
	}

	void dijkstra(int root){
		MinHeap heap = MinHeap();

		Elemento aux;
		int cur, dist, elemento, i;

		for(i = 1; i <= this->num_vertices; i++){
			this->vertices[i].setDistancia(9999);
		}
		this->vertices[root].setDistancia(0);

		heap.push(root, 0);

		while(!heap.empty()){

			aux = heap.pop();
			cur = aux.getCurrent();
			dist = aux.getDistance();

			for(i = 0; i < this->vertices[cur].getTamanhoLista(); i++){
				elemento = this->vertices[cur].getElementoLista(i);

				if(dist + this->vertices[cur].getPesoElemento(i) < this->vertices[elemento].getDistancia()){
					
					this->vertices[elemento].setDistancia( dist + this->vertices[cur].getPesoElemento(i) );
					heap.push(elemento, this->vertices[elemento].getDistancia());
				}
			}
		}

		//int vet[100];
		for(i = 1; i <= this->num_vertices; i++){
			cout << "distancia ate o no raiz do no " << i << " : " << this->vertices[i].getDistancia() << endl;
		}

		//return vet;
	}

private:
	int num_vertices;
	Vertice vertices[100];
};