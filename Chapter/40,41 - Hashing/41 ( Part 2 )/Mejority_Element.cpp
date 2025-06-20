#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

// Find elements that appear more than n/3 times.

void mejorityEl(vector<int> nums){
    unordered_map<int, int> m;  // < element , freq >

    for(int i=0; i<nums.size(); i++){
        if(m.count(nums[i])){
            m[nums[i]]++;
        }else{
            m[nums[i]] = 1;
        }
    }

    for(pair<int,int> pair : m){
        if(pair.second > nums.size()/3){
            cout << pair.first << endl;
        }
    }
}

int main(){
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums2 = {1,2};

    mejorityEl(nums);

    return 0;
}