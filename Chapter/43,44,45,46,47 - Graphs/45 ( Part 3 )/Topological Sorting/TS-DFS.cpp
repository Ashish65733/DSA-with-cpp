#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

// Unweighted directed Graph
class Graph{
    int V;  // No. of vertices (Nodes)
    list<int>* l;   // pointer to an array of list.
    bool isUndir;
public:
    Graph(int V,bool isUndir){
        this->V = V;
        l = new list<int> [V];  // Dynamically allocates an array of type list<int> of size V.
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){ // u----->v
        l[u].push_back(v);
        if(isUndir)
            l[v].push_back(u);  
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

    void topoHelper(int src, vector<bool> &vis, stack<int> &s){  // DFS - O(V + E)
        vis[src] = true;

        for(int v : l[src]){  // l[i] = neighbor
            if(!vis[v]){
                topoHelper(v,vis,s);
            }
        }
        s.push(src);
    }

    void topSort(){
        vector<bool> vis(V,false);
        stack<int> s;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoHelper(i,vis,s);
            }
        }

        // print topological order
        while(s.size() > 0){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

};

int main(){
    // DAG - Directed Acyclic Graph
    Graph graph(6,false);

    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    

    // graph.print();

    graph.topSort();

    return 0;
}