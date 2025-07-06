#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int mcmTab(vector<int> arr, int i, int j){  
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,0));

    // initialization
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }

    // bottom-up fill
    for(int len=2; len<n; len++){
        for(int i=1; i<=n-len; i++){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    return dp[1][n-1];
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 3};  // n -> n-1 matrices (1 to n-1)
    int n = arr.size();

    cout << mcmTab(arr,1,n-1) << endl;

    return 0;
}