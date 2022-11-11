#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define INF 9999
#define ELEMENTO first
#define PESO second

class Grafo {
    private:
    int num_vertices;
    list<pair<int, int>> * vertices;

    public:
    Grafo(int n){
        this->num_vertices = n;
        this->vertices = new list<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int peso){
        this->vertices[x].push_back(make_pair(y, peso));
        this->vertices[y].push_back(make_pair(x, peso));
    }

    list<pair<int, int>> getListaOf(int i){
        return this->vertices[i];
    }
};

int main()
{
    int n, x, y, peso;
    cin >> n;

    Grafo g = Grafo(n);

    while(true){
        cin >> x;
        cin >> y;
        cin >> peso;
        if(x==-1){
            break;
        }

        g.addEdge(x, y, peso);
    }

    for(int i = 0; i <n; i++){
        cout << endl << i << " -> ";
        for(pair<int, int> p : g.getListaOf(i)){
            cout << p.ELEMENTO << " ";
        }
    }

    return 0;
}