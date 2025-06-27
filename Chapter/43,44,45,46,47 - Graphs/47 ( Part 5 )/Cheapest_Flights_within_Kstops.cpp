#include<iostream>
#include<climits>
#include<queue>
#include<vector>

using namespace std;

class Info{
public:
    int u;
    int cost;
    int stop;

    Info(int u,int cost,int stop){
        this->u = u;
        this->cost = cost;
        this->stop = stop;
    }
};

int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
    queue<Info> q;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    q.push(Info(src, 0, -1));

    while(q.size() > 0){
        Info curr = q.front();
        q.pop();

        for(int i=0; i<flights.size(); i++){
            if(flights[i][0] == curr.u){
                int v = flights[i][1];
                int wt = flights[i][2];

                if(dist[v] > curr.cost + wt && curr.stop + 1 <= k){
                    dist[v] = curr.cost + wt;
                    q.push(Info(v, dist[v], curr.stop+1));
                }
            }
        }
    }
    if(dist[dst] == INT_MAX){
        return -1;
    }
    return dist[dst];
}

int main(){
    vector<vector<int>>  flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int k = 1;

    cout << "Cheapest flight cost within " << k << " stops = " << findCheapestPrice(4, flights, 0, 3, k) << endl;

    return 0;
}