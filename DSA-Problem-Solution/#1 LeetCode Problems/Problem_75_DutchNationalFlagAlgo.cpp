// Dutch national flag algorithm : 

#include<iostream>
#include<vector>
using namespace std;

void SortArr(vector<int>& nums,int n){  // 0(n)
    int low = 0, mid = 0, high = n-1;

    while (mid <= high)
    {
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            mid++;
            low++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }  
}

int main(){
    vector<int> nums = {2,0,2,1,1,0,1,2,0,0};
    int n = nums.size();

    SortArr(nums,n);

    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}