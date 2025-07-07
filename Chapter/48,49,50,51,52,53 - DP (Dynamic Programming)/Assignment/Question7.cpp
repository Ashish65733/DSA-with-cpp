#include<iostream>
#include<vector>

using namespace std;

// Leetcode 416 : Partition Equal Subset Sum

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totSum = 0;
    for(int el:nums){
        totSum += el;
    }

    if(totSum % 2 != 0) return false;

    int W = totSum / 2;

    vector<bool> dp(W+1,false);
    dp[0] = true;

    for(int num : nums){
        for(int j=W; j>= num; j--){
            dp[j] = dp[j-num] || dp[j];
        }
    }

    return dp[W];
}

int main(){
    vector<int> nums = {1,5,11,5};

    cout << canPartition(nums) << endl;

    return 0;
}