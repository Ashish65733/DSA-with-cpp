#include<iostream>
#include<climits>
#include<vector>

using namespace std;

bool check(vector<int>& nums) {
    int count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > nums[(i+1)%nums.size()]){ // in i=nums.size() iteration (i+1)%nums.size() = 1   -> Circular
            count++;
        }
    }
    return count <= 1;
}

int main(){
    vector<int> arr1 = {4,5,6,7,0,1,2};
    vector<int> arr2 = {2,1,3,4};

    if(check(arr1)){
        cout << "Array is Sorted and Rotated." << endl;
    }else{
        cout << "Array is not Sorted and Rotated." << endl;
    }
    
    return 0;
}