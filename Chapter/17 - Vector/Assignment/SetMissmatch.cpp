#include<iostream>
#include<climits>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> ans;
    
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == nums[i-1]){
            if (nums[i+1] == nums[i]+1)
            {
                nums[i-1]--;
                ans.push_back(nums[i-1]);
                ans.push_back(nums[i]);
                return ans;
            }else{
                nums[i]++;
                ans.push_back(nums[i-1]);
                ans.push_back(nums[i]);
                return ans;
            }
        }
    }
}
int main(){
    vector<int> nums = {1,2,2,4} ;

    vector<int> ans =  findErrorNums(nums);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl ;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << " " ;
    // }
    
    return 0;
}