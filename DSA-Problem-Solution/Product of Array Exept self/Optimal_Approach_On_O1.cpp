// Optimal Approach : Time Complaxity : O(n)  Space Complaxity : O(1)
#include<iostream>
#include<vector>
using namespace std;

vector<int> ProductExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,1);

    // Prefix :
    for (int i = 1; i < n; i++)
    {
        ans[i] = nums[i-1] * ans[i-1];
    }

    // Sufix :
    int sufix = 1;
    for (int i = n-2; i >= 0; i--)
    {
        sufix *= nums[i+1]; // ith sufix
        ans[i] *= sufix;    //ans
    }
     
    return ans;  
}

int main(){
    vector<int> nums = {1,2,3,4};\
    
    vector<int> Ans = ProductExceptSelf(nums);

    for(int val : Ans){
        cout<<val<<" ";
    }

    return 0;
}