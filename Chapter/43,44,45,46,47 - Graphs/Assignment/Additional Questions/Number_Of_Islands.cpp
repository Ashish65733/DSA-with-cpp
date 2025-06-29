#include<iostream>
#include<vector>
using namespace std;

class DSU{
    vector<int> par;
    vector<int> rank;
public:
    DSU(int n){

        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(1);
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

        if(rank[pA] > rank[pB]){
            par[pB] = pA;
            rank[pA] += rank[pB];
        }else{
            par[pA] = pB;
            rank[pB] += rank[pA];
        }
        return true;    // Successfully unioned
    }
};

int numIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    DSU D(n*m);
    int count = 0;

     // Step 1: Count total land cells
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                count++;
            }
        }
    }

    // Step 2: Try union with 4 neighbors

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
                   if(D.unionByRank(idx,nIdx)){
                       count--; // Only decrement if a union actually happened
                   }
                }
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>> grid = {{1, 1, 0, 1, 0},
                                {1, 1, 0, 1, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1}};

    cout << numIslands(grid) << endl;
    return 0;
}