// Optimal Approach : O(n) 
#include<iostream>
#include<vector>
using namespace std;

vector<int> ProductExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,1);
    vector<int> prefix(n,1);
    vector<int> sufix(n,1);

    // Prefix :
    for (int i = 1; i < n; i++)
    {
        prefix[i] = nums[i-1] * prefix[i-1];
    }

    // Sufix :
    for (int i = n-2; i >= 0; i--)
    {
        sufix[i] = nums[i+1] * sufix[i+1];
    }

    // Answer :
    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix[i] * sufix[i];
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