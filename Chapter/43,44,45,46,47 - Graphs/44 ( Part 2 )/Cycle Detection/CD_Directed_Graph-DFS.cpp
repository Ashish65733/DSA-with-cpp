#include<iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;

// Unweighted directed Graph
class Graph{
    int V;  // No. of vertices (Nodes)
    list<int>* l;   // pointer to an array of list.
    bool isUndirected;
public:
    Graph(int V,bool isUndirected){
        this->V = V;
        l = new list<int> [V];  // Dynamically allocates an array of type list<int> of size V.
        this->isUndirected = isUndirected;
    }

    void addEdge(int u, int v){ // u----->v
        l[u].push_back(v);
        if(isUndirected){
            l[v].push_back(u);  
        }
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

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                return dirCycleHelper(v,vis,recPath);
            }else{
                if(recPath[v]){   // Cycle
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                return dirCycleHelper(i,vis, recPath);
            }
        }

        return false;
    }

};

int main(){
    Graph graph(4,false);

    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    

    // graph.print();

    cout << graph.isCycleDir() << endl; 

    return 0;
}