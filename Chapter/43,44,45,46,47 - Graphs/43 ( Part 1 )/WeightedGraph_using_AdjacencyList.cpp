#include<iostream>
#include<list>

using namespace std;

// Unweighted Undirected Graph
class Graph{
    int V;  // No. of vertices (Nodes)
    list<pair<int,int>>* l;   // pointer to an array of list of pair. <neighbor, weight>
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>> [V];  // Dynamically allocates an array of type list<pair<int,int>> of size V.
    }

    void addEdge(int u, int v, int wt){ // u-----v
        l[u].push_back({v,wt});
        l[v].push_back({u,wt});  // just removing this line we can implement directed graph
        // Since the graph is undirected, both nodes store each other as neighbors.
    }

    void print(){
        for(int u=0; u<V; u++){
            list<pair<int,int>> neighbors = l[u];
            cout << u << " : ";
            for(pair<int,int> v : neighbors){
                cout << "(" << v.first << "," << v.second << ") ";
            }
            cout << endl; 
        }
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 2);

    graph.print();

    return 0;
}