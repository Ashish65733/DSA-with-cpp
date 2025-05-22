#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Majority Element : Leetcode 169
// This is Moore's voting algorithm (Most optimized for this problem)
// The other two approaches are in DSA-Problem-Solution File

int majorityElement(vector<int> &nums){
    int freq = 0,ans = 0;

    for(int i=0; i<nums.size(); i++){
        if(freq == 0){
            ans = nums[i];
        }
        if(ans = nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1,2,2,1,1};

    cout << "Majority Element is : " << majorityElement(nums) << endl;
    return 0;
}