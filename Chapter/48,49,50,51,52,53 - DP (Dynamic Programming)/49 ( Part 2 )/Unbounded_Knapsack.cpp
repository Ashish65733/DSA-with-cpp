#include<iostream>
#include<vector>

using namespace std;

int unboundedKnapsack(vector<int> val, vector<int> wt, int w, int n){
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            int itemVal = val[i-1];
            int itemWt = wt[i-1];

            if(itemWt <= j){
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int w = 7;
    int n = 5;

    cout << unboundedKnapsack(val,wt,w,n) << endl;  // 100
    return 0;
}