#include<iostream>
#include<vector>
using namespace std;

int PeakINXMountainArr(vector<int> nums){
    int n = nums.size();
    int st = nums[1],end = nums[n-2];

    for (int i = 0; i < n; i++)
    {
        int mid = st + (end-st)/2;
        if (nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
            return mid;
        }else if(nums[mid-1]<nums[mid]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }   
    }
}

int main(){
    vector<int> arr = {0,3,8,9,5,2};

    int result = PeakINXMountainArr(arr);

    cout<<"Peak Index in Given Mountain Array = "<<result<<endl; 
    return 0;
}
