#include<iostream>
#include<vector>

using namespace std;

int knapsackMem(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>> &dp){    // O(n*w)
    if(n == 0 || w == 0){
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){    // valid wt
        //include
        int ans1 = knapsackMem(val, wt, w-itemWt, n-1, dp) + itemVal;
        //exclude
        int ans2 = knapsackMem(val, wt, w, n-1, dp);

        dp[n][w] = max(ans1,ans2);
    }else{
        //exclude
        dp[n][w] = knapsackMem(val, wt, w, n-1, dp);
    }

    return dp[n][w];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int w = 7;
    int n = 5;

    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));

    cout << knapsackMem(val,wt,w,n,dp) << endl;

    cout << "Memoization Matrix : " << endl;

    for(int i=0; i<dp.size(); i++){ // The cell having value -1 has not been called.
        for (int j = 0; j < dp[i].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}