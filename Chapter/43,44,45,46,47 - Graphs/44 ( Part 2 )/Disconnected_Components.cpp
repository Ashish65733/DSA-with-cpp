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

    void bfsHelper(int st, vector<bool> &vis){ // O(V + E)
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(q.size() > 0){
            int u = q.front();  // curr vertex
            q.pop();
            cout << u << " ";

            list<int> neighbors = l[u]; 
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void bfs(){
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                bfsHelper(i,vis);
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for(int v : neighbors){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsHelper(i,vis);
                cout << endl;
            }
        }
    }

};

int main(){
    Graph graph(10);

    graph.addEdge(0, 2);
    graph.addEdge(2, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 7);
    graph.addEdge(3, 8);

    // graph.print();

    graph.dfs();
    graph.bfs();

    return 0;
}