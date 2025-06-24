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

    bool isBipartite(){ // assuming that all nodes are connected to each other.
        queue<int> q;
        // vector<bool> vis(V,false);
        vector<int> color(V,-1);

        q.push(0);
        // vis[0] = true;
        color[0] = 0;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors){
                if(color[v] == -1){
                    // vis[v] = true;
                    
                    color[v] = !color[curr];
                    q.push(v);
                }else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
       

};

int main(){
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    // graph.addEdge(0, 3);

    // graph.print();

    cout << graph.isBipartite() << endl; 

    return 0;
}