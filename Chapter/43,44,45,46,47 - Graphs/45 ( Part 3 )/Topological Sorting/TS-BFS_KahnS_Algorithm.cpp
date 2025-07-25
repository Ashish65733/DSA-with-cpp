#include<iostream>
#include<list>
#include<queue>
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

    void calcIndegree(vector<int> &indeg){
        for(int u=0; u<V; u++){
            list<int> neighbors = l[u];
            for(int v : neighbors){
                indeg[v]++;
            }
        }
    }

    void topSort(){ // kahn's algo - BFS
        vector<int> indeg(V,0);
        calcIndegree(indeg);
        queue<int> q;

        // 0 indeg nodes -> starting points
        for(int i=0; i<V; i++){ // DAG has atleast one vertex with in-degree or out-degree = 0
            if(!indeg[i]){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for(int v : l[curr]){
                indeg[v]--;
                if(!indeg[v]){  // no pending dependencies
                    q.push(v);
                }
            }
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