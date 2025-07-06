#include<iostream>
#include<vector>

using namespace std;

// Leetcode 1137 : N-th Tribonacci Number

int tribonacci(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
        
    vector<int> dp(n+1,0);
    dp[1] = dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main(){
    int n = 5;

    cout << tribonacci(n) << endl;

    return 0;
}