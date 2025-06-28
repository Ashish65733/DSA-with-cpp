#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Leetcode - 684 : Redundant connection 

vector<int> par;

int find(int x){
    if(par[x] != x){
        par[x] = find(par[x]);  // Path compression
    }
    return par[x];
}

bool unionSet(int a, int b){
    int parA = find(a);
    int parB = find(b);

    if(parA == parB){
        return false;
    }else{
        par[parA] = parB;
    }
    return true;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    for(int i=0; i<=n; i++){
        par.push_back(i);
    }

    for(vector<int> edge : edges){
        if(!unionSet(edge[0],edge[1])){
            return edge;
        }
    }
    return {};
}


int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};

    vector<int> ans = findRedundantConnection(edges);
    
    cout << ans[0] << " , " << ans[1] << endl;

    return 0;
}