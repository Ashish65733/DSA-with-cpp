#include<iostream>
#include<vector>

using namespace std;

int countWayTab(int n){ // O(n) - Using Tabulation  -  Always Preferred
    vector<int> dp(n+1,-1); // dp[i] -> ways
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    int n = 6;

    cout << countWayTab(n) << endl;
    return 0;
}