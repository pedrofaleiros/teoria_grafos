#include <iostream>
#include <list>

#define INF 9999

using namespace std;

class Node {
    public:
    Node(int value){
        this->value = value;
    }

    int getValor(){
        return this->value;
    }

    void addEdge(int x, int cost){
        this->adj_list.push_back(make_pair(x, cost));
    }

    list<pair<int, int>> getAdjList(){
        return this->adj_list;
    }

    int getSizelista(){
        return this->adj_list.size();
    }

    int teste(int num){
        return num*2;
    }
        
    private:
    int value;
    list<pair<int, int>> adj_list;
};

class Graph {
    public:
    Graph(int num){
        this->num_nodes = num;
        for(int i = 0; i < num; i++){
            this->nodes.push_back(Node(i));
        }
    }

    void addEdge(int x, int y, int cost){
        auto node = this->nodes.begin();
        advance(node, x);

        node->addEdge(y, cost);
    }

    void show(){
        for(Node node : this->nodes){
            cout << node.getValor() << " -> ";
            for(auto par : node.getAdjList()){
                cout << par.first << " ";
            }
            cout <<endl;
        }
    }

    void dijkstra(int root){
        list<pair<int, int>> queue;
        pair<int, int> aux;

        int cur, dista, i;

        int dist[100];
        for(int i = 0; i < this->num_nodes; i++){
            dist[i] = INF;
        }
        dist[root] = 0;

        queue.push_back(make_pair(0, root));

        while(!queue.empty()){

            queue.sort();
            
            aux = queue.front();
            queue.pop_front();
            
            dista = aux.first;
            cur = aux.second;

            auto element = this->nodes.begin();
            advance(element, cur);
            for(pair<int, int> el : element->getAdjList()){
                if(dista + el.second < dist[el.first]){
                    dist[el.first] = dista + el.second;
                    queue.push_back(make_pair(dist[el.first], el.first));
                }
            }
        }

        for(int i = 0; i < this->num_nodes; i++){
            cout << "distancia ate o no raiz do no " << i << " : " << dist[i] << endl;
        }
    }

    private:
    int num_nodes;
    list<Node> nodes;
};