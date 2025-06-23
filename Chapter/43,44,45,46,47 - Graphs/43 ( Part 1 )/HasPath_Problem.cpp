#include<iostream>
#include<list>
#include<vector>

using namespace std;

// Unweighted Undirected Graph
class Graph{
    int V;  // No. of vertices (Nodes)
    list<int>* l;   // pointer to an array of list.
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];  // Dynamically allocates an array of type list<int> of size V.
    }

    void addEdge(int u, int v){ // u-----v
        l[u].push_back(v);
        l[v].push_back(u);  // just removing this line we can implement directed graph
        // Since the graph is undirected, both nodes store each other as neighbors.
    }

    void print(){
        for(int u=0; u<V; u++){
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool pathHelper(int src, int dest, vector<bool> &vis){
        if (src == dest){
            return true;
        }
        
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(pathHelper(v,dest,vis)){
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int src, int dest){
        vector<bool> vis(V,false);
        return pathHelper(src,dest,vis);
    }

};

int main(){
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    // graph.print();

    cout << graph.hasPath(0,5) << endl;

    return 0;
}