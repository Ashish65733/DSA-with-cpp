#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int minCostConnectPoints(vector<vector<int>>& points) {
    int V = points.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> mst(V,false);

    pq.push({0,0}); // <0, src>
    int minCost = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(!mst[u]){
            mst[u] = true;
            minCost += cost;

            for(int v=0; v<V; v++){
                if(u != v){ // u--->v
                    int wt = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                    pq.push({wt,v});
                }
            }
        }
    }
    return minCost;
}

int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    cout << minCostConnectPoints(points) << endl;
    
    return 0;
}