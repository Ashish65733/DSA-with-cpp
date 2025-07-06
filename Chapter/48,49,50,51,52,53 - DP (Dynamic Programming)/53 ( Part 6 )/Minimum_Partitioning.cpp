#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int getMinDiff(vector<int> nums){
    int totSum = 0;
    for(int el : nums){
        totSum += el;
    }

    int n = nums.size();
    int W = totSum / 2;
    vector<vector<int>> dp(n+1, vector<int>(W+1,0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1]+dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1Sum = dp[n][W];
    int grp2Sum = totSum - grp1Sum;

    return abs(grp1Sum - grp2Sum);
}

int main(){
    vector<int> nums = {1, 6, 11, 5};

    cout << getMinDiff(nums) << endl;

    return 0;
}