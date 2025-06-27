#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Edge{
public: 
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph{
public:
    int V;                         // Number of vertices
    vector<Edge> edges;            // All graph edges
    vector<int> par;               // DSU parent array
    vector<int> rank;              // DSU rank array


    Graph(int V){
        this->V = V;

        for(int i=0; i<V; i++){
            par.push_back(i);   // Initially, each node is its own parent
            rank.push_back(0);   // Initial rank is 0
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v){
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]){
            par[parV] = parU;
            rank[parU]++;
        }else if(rank[parU] > rank[parV]){
            par[parV] = parU;
        }else{
            par[parU] = parV;
        }

    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u,v,wt));
    }

    int kruskals(){ //O(E log E)
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});   
        int minCost = 0;
        int count = 0;

        for(int i=0; i<edges.size() && count < V-1; i++){
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){   // No cycle edge
                unionByRank(parU,parV);
                minCost += e.wt;
                count++;
            }
        }
        return minCost;
    }

};

int main(){
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    cout << "Minimum cost = " << graph.kruskals() << endl;

    return 0;
}