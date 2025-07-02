#include<iostream>
#include<vector>

using namespace std;
// Leetcode 518 : Coin Change 2

// this is not optimized as space (can't submit)
int change(int amount, vector<int>& coins) {    // O(n * amount)
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=amount; j++){
            if(coins[i-1] <= j){    // valid
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];    // inclution + exclution
            }else{  // invalid
                dp[i][j] = dp[i-1][j];  // exclution
            }
        }
    }
    return dp[n][amount];
}


int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << change(amount, coins) << endl;

    return 0;
}