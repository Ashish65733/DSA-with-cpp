#include<iostream>
#include<vector>
using namespace std;

int Majority_Element(vector<int> nums){
    vector<int> ans;
    int n = nums.size();

    for (int val : nums)
    {
        int freq=0;
        for (int el : nums)
        {
            if (el == val)
            {
                freq++;
            }  
        }
       if (freq>n/2)
       {
            return val;
       }
        
    }
    
}
int main(){
    vector<int> nums = {1,1,2,2,1,1,2};

    int ans = Majority_Element(nums);
    cout<< ans <<endl;
    return 0;
}