#include <iostream>
#include <stdlib.h>

using namespace std;

class Elemento
{
public:
	Elemento()
	{
		this->current = 0;
		this->distance = 0;
		this->prox = NULL;
	}

	Elemento(int cur, int dist)
	{
		this->current = cur;
		this->distance = dist;
		this->prox = NULL;
	}

	int getDistance()
	{
		return this->distance;
	}

	int getCurrent()
	{
		return this->current;
	}

	Elemento *getProx()
	{
		return this->prox;
	}

	void setProx(Elemento *e)
	{
		this->prox = e;
	}

	void mostra()
	{
		cout << ">>> " << this->current << " : " << this->distance << endl;
	}

private:
	int current;
	int distance;
	Elemento *prox;
};

class PriorityQueue
{

public:
	PriorityQueue()
	{
		this->size = 0;
		this->topo = NULL;
	}

	void push(int cur, int dist)
	{
		Elemento *novo = new Elemento(cur, dist);

		if (!this->empty())
		{

			Elemento *aux = this->topo, *ant = NULL;

			while (novo->getDistance() > aux->getDistance() && aux->getProx() != NULL)
			{
				ant = aux;
				aux = aux->getProx();
			}

			if (ant == NULL)
			{
				if (aux->getDistance() < novo->getDistance())
				{
					aux->setProx(novo);
				}
				else
				{
					novo->setProx(aux);
					this->topo = novo;
				}
			}
			else
			{
				if (aux->getDistance() < novo->getDistance())
				{
					aux->setProx(novo);
				}
				else
				{
					ant->setProx(novo);
					novo->setProx(aux);
				}
			}
		}
		else
		{
			this->topo = novo;
		}

		this->size++;
	}

	Elemento pop()
	{
		if (this->empty())
		{
			return Elemento(-1, -1);
		}

		Elemento *aux = this->topo;

		int cur, dist;
		cur = aux->getCurrent();
		dist = aux->getDistance();

		this->topo = aux->getProx();
		this->size--;

		return Elemento(cur, dist);
	}

	void mostra()
	{
		Elemento *aux = this->topo;

		while (aux != NULL)
		{
			cout << aux->getDistance() << " : " << aux->getCurrent() << endl;
			aux = aux->getProx();
		}
	}

	bool empty()
	{
		return this->size == 0;
	}

private:
	int size;
	Elemento *topo;
};

/* int main()
{
	PriorityQueue * heap = new PriorityQueue();

	heap->push(0, 2);
	heap->push(0, 3);
	heap->push(0, 1);
	heap->push(0, 5);
	heap->push(0, 4);

	heap->pop().mostra();
	heap->pop().mostra();
	heap->pop().mostra();
	heap->pop().mostra();

	heap->mostra();

	return 0;
} */