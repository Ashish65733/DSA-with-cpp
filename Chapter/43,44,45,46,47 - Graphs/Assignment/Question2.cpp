#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<pair<int,int>,int>> q;   // <<row,col>,dist>

    int fresh = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
            }else if(grid[i][j] == 1){
                fresh++;
            }
        }
    }
    if(fresh == 0) return 0;

    int time = 0;

    int dr[] = {-1, 1, 0, 0}; // top, bottom, right, left
    int dc[] = {0, 0, 1, -1};

    while(q.size() > 0 && fresh != 0){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Out of Grid :
            if(nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

            if(grid[nr][nc] == 1){
                grid[nr][nc] = 2;  // visited (Rotten)
                fresh--;
                q.push({{nr,nc},d+1});
                time = d+1;
            }
        }
    }
    if(fresh > 0) return -1;
    return time;
}

int main(){
    vector<vector<int>> grid = {{2,1,1},
                                {0,1,1},
                                {0,0,1}};

    cout << "Time = " << orangesRotting(grid) << endl;
    return 0;
}