#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// Leetcode 1691 : Maximum Height by Stacking Cuboids 
int solve(vector<vector<int>>& cuboids, int prev, int idx, vector<vector<int>>& dp){
    if(idx == cuboids.size()){
        return 0;
    }

    if(dp[prev+1][idx] != -1){
        return dp[prev+1][idx];
    }
    int skip_idx = solve(cuboids, prev, idx+1 , dp);
    int select = 0;

    if(prev == -1 || (cuboids[prev][0] <= cuboids[idx][0] && cuboids[prev][1] <= cuboids[idx][1] && cuboids[prev][2] <= cuboids[idx][2])){
        select = cuboids[idx][2] + solve(cuboids, idx, idx+1, dp);
    }

    dp[prev+1][idx] = max(skip_idx, select);
    return dp[prev+1][idx];
}

int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    sort(cuboids.begin(), cuboids.end());
    int ans = solve(cuboids, -1, 0,dp);
    return ans;
}

int main(){
    vector<vector<int>> cuboids = {{38,25,45},{76,35,3}};

    cout << maxHeight(cuboids) << endl;

    return 0;
}