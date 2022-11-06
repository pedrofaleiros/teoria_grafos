#include "Graph.h"

int main()
{
	int num, x, y, peso;
	cin >> num;
	Graph g = Graph(num);

	while(true){
		cin >> x;
		cin >> y;
		cin >> peso;

		if(!x) break;

		g.addAresta(x, y, peso);
	}

	g.dijkstra(1);

	return 0;
}