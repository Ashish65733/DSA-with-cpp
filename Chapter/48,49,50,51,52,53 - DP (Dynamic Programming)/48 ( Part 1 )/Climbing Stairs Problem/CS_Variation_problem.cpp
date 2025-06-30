#include<iostream>
#include<vector>

using namespace std;

// Count ways to reach the nth stair. A person can climb 1,2 or 3 stairs at a time.

int countWayTab(int n){ // O(n) 
    vector<int> dp(n+1,-1); 
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main(){
    int n = 4;

    cout << countWayTab(n) << endl;
    return 0;
}