#include<iostream>
#include<list>
#include<string>
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

    void addEdge(int u, int v){ // u-----v
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

    void pathHelper(int src, int dest, vector<bool> &vis, string &path){
        if(src == dest){
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);

        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                pathHelper(v,dest,vis,path);
            }
        }

        path = path.substr(0,path.size()-1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest){
        vector<bool> vis(V,false);
        string path = "";
        pathHelper(src,dest,vis,path);
    }

};

int main(){
    Graph graph(6,false);

    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    

    // graph.print();

    graph.printAllPaths(5,1);

    return 0;
}