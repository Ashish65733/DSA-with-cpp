#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Majority_Element(vector<int> nums){
    int n = nums.size();

    // sort
    sort(nums.begin(),nums.end());

    // freq count
    int freq = 1;
    int ans = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == nums [i-1])
        {
            freq++;
        }else{
            freq=1;
            ans = nums[i];
        }
        if (freq>n/2){
            return ans;
        }    
    }
    return ans; 
}
int main(){
    vector<int> nums = {1,1,2,2,1,1,2};

    int ans = Majority_Element(nums);
    cout<< ans <<endl;
    return 0;
}