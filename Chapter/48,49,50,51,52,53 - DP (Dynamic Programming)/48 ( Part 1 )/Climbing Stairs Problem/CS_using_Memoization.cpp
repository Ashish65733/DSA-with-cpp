#include<iostream>
#include<vector>

using namespace std;

int countWayMem(int n, vector<int> &dp){ // O(n) - using Memoization
    if(n == 0 || n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = countWayMem(n-1,dp) + countWayMem(n-2,dp);

    return dp[n];
}

int main(){
    int n = 6;
    vector<int> dp(n+1,-1);

    cout << countWayMem(n,dp) << endl;
    return 0;
}