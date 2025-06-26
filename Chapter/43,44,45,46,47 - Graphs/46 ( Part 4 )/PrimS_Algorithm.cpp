#include<iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;

// Weighted Undirected Graph
class Graph{
    int V;  // No. of vertices (Nodes)
    list<pair<int,int>>* l;   // pointer to an array of list.
    bool isUndir;
public:
    Graph(int V,bool isUndir = true){
        this->V = V;
        l = new list<pair<int,int>> [V];  // Dynamically allocates an array of type list<int> of size V.
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt){ // u----v (Weighted)
        l[u].push_back({v,wt});
        if(isUndir)
            l[v].push_back({u,wt});  
    }

    int primsAlgo(int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    // minHeap --> (wt, u)
        vector<bool> mst(V, false);

        pq.push({0,src});
        int ans = 0;

        while(pq.size() > 0){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans += wt;
                list<pair<int,int>> neighbors = l[u];
                for(pair<int,int> n : neighbors){
                    int v = n.first;
                    int currWt = n.second;
                    pq.push({currWt,v});
                }
            }
        }
        return ans;
    }
};

int main(){
    // Prim's Algo Graph
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);

    graph.addEdge(1, 3, 40);
    
    graph.addEdge(2, 3, 50);
    
    cout << "Final cost of MST = " << graph.primsAlgo(0) << endl;

    return 0;
}