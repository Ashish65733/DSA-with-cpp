#include<iostream>
#include<vector>

using namespace std;

// Leetcode 329 : Longest Increasing Path in a Matrix

int rec(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(dp[r][c] != -1){
        return dp[r][c];
    }
    int ans = 1;

    // top
    if(r-1 >= 0 && matrix[r][c] > matrix[r-1][c])
        ans = max(ans, rec(r-1, c, matrix, dp) + 1);
    // bottom
    if(r+1 < matrix.size() && matrix[r][c] > matrix[r+1][c])
        ans = max(ans, rec(r+1, c, matrix, dp) + 1);
    // left
    if(c-1 >= 0 && matrix[r][c] > matrix[r][c-1])
        ans = max(ans, rec(r, c-1, matrix, dp) + 1);
    // right
    if(c+1 < matrix[0].size() && matrix[r][c] > matrix[r][c+1])
        ans = max(ans, rec(r, c+1, matrix, dp) + 1);
    
    return dp[r][c] = ans;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int lis = 1;
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            int ans = rec(r, c, matrix, dp);
            lis = max(lis,ans);
        }
    }

    return lis;
}

int main(){
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};

    cout << longestIncreasingPath(matrix) << endl;

    return 0;
}