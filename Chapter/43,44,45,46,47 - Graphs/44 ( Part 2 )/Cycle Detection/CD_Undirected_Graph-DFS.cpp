#include<iostream>
#include<list>
#include<queue>
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

    bool undirCycleHelper(int src, int par, vector<bool> &vis){
        vis[src] = true;

        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                return undirCycleHelper(v,src,vis);
            }else{
                if(v != par){   // Cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool> vis(V,false);
        return undirCycleHelper(0,-1,vis);
    }    

};

int main(){
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    

    // graph.print();

    cout << graph.isCycleUndir() << endl; 

    return 0;
}