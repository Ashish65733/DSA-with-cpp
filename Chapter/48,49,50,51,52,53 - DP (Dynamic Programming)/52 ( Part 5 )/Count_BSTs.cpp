#include<iostream>
#include<vector>

using namespace std;

// // Leetcode 96 : Unique Binary Search Trees
// same as Catalan's Number

int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }        
    return dp[n];
}

int main(){
    int n = 4;

    cout << numTrees(n) << endl;

    return 0;
}