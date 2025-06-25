#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &graph){
    vis[src] = true;
    rec[src] = true;

    for(int i=0; i<graph.size(); i++){
        int u = graph[i][1];
        int v = graph[i][0];

        if(u == src){
            if(!vis[v]){
                if(isCycle(v, vis, rec, graph)){
                    return true;
                }
            }else{
                if(rec[v]){
                    return true;
                }
            }
        }
    }
    rec[src] = false;
    return false;
}

void topSort(int src,vector<bool> &vis2,stack<int> &s,vector<vector<int>> &graph){
    vis2[src] = true;

    for(int i=0; i<graph.size(); i++){
        int u = graph[i][1];
        int v = graph[i][0];
        if(u == src){
            if(!vis2[v]){
                topSort(v,vis2,s,graph);
            }
        }
    }
    s.push(src);
}

vector<int> findOrder(int numCourses, vector<vector<int>> &graph){
    int V = numCourses;
    vector<bool> vis(V,false);
    vector<bool> rec(V,false);
    vector<int> ans;

    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(isCycle(i,vis,rec,graph)){
                return ans;
            }
        }
    }

    // topological sorting
    vector<bool> vis2(V,false);
    stack<int> s;
    for(int i=0; i<V; i++){
        if(!vis2[i]){
            topSort(i, vis2, s, graph);
        }
    }

    while(s.size() > 0){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    
}

int main(){
    vector<vector<int>> graph = {{1,0},{2,0},{3,1},{3,2}};

    vector<int> ans = findOrder(3, graph);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}