#include "list_graph.h"

int main()
{
    int n, i, x, y, peso;
    cin >> n;
    Graph graph = Graph(n);

    while(true){
        cin >> x;
        cin >> y;
        cin >> peso;

        if(x == 0) break;

        graph.addEdge(x-1, y-1, peso);

        graph.addEdge(y-1, x-1, peso);
    }
    
    //graph.show();

    graph.dijkstra(0);

    return 0;
}