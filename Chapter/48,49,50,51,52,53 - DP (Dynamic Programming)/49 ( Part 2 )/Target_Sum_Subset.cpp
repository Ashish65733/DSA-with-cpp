#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// variation of 0-1 knapsack

bool targetSum(vector<int> nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(nums[i] <= j){
                dp[i][j] = max(nums[i]+dp[i-1][j-nums[i]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // just for understanding :
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][target] == target;
}

int main(){
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 10;

    cout << targetSum(nums,target) << endl;

    return 0;
}