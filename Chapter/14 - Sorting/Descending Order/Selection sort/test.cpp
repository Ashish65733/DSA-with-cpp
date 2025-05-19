#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int selectionSort(vector<int>& nums){
    int n = nums.size();

    for (int i = 0; i < n-1; i++)
    {
        int maxInd = i;
        for (int j = i+1; j < n ; j++)
        {
            if(nums[j] > nums[maxInd]){
                maxInd = j;
            }
        }
        swap(nums[maxInd],nums[i]);
    }
    return 0;   
}

void printArr(vector<int> arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> nums = {3,6,2,1,8,7,4,5,3,1};
    int n = nums.size();

    cout<<"Brfore sorting : ";
    printArr(nums,n);
    
    selectionSort(nums);

    cout<<endl<<"After sorting : ";
    printArr(nums,n);
    return 0;
}