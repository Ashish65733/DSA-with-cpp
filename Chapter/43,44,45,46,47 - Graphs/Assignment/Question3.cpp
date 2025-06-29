#include<iostream>
#include<vector>

// leetcode 695 - Max Area of Island
using namespace std;

class DSU{
    vector<int> par;
    vector<int> size;
public:
    DSU(int n){

        for(int i=0; i<n; i++){
            par.push_back(i);
            size.push_back(0);
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unionByRank(int a, int b){
        int pA = find(a);
        int pB = find(b);

        if(pA == pB) return false;  // They are already in the same set

        par[pB] = pA;
        size[pA] += size[pB];
        return true;    // Successfully unioned
    }

    void makeIsland(int x){
        size[x] = 1;
    }

    int maxRank(){
        int maxi = size[0];
        for(int i : size){
            maxi = max(maxi, i);
        }
        return maxi;
    }
};

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    DSU D(n*m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                int idx = i * m + j;
                D.makeIsland(idx);
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};  // up, down, left, right
    int dc[] = {0, 0, -1, 1};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 0) continue;

            int idx = i*m+j;

            for(int d=0; d<4; d++){
                int nr = i + dr[d];
                int nc = j + dc[d];
                int nIdx = nr*m+nc;

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                    D.unionByRank(idx,nIdx);
                }
            }
        }
    }
    return D.maxRank();
}

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}