#include<iostream>
#include<climits>
#include<vector>
using namespace std;
// Leetcode 198 : House Robber

int rob(vector<int>& nums) {
    int n = nums.size();

    if(n == 0) return 0;
    if(n == 1) return nums[0];
    // vector<int> dp(n,-1);

    // dp[0] = nums[0];
    // dp[1] = max(nums[0],nums[1]);
    int rob1 = nums[0];
    int rob2 = max(nums[0],nums[1]);

    for(int i=2; i<n; i++){ 
        // dp[i] = max[dp[i-1], nums[i]+dp[i-2]];
        int temp = max(rob2, nums[i]+rob1);
        rob1 = rob2;
        rob2 = temp;
    }
    // return dp[n-1];
    return rob2;
}

int main(){
    vector<int> nums = {1,2,3,1};
    
    cout << rob(nums) << endl;

    return 0;
}