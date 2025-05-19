#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int CountingSort(vector<int>& nums){
    int n = nums.size();
    int maxNum = INT_MIN,minNum = INT_MAX;

    for(int i=0; i<n; i++){
        maxNum = max(maxNum, nums[i]);
        minNum = min(minNum, nums[i]);
    }

    vector<int> freq(maxNum+1,0);

    for(int i=0; i<n; i++){
        freq[nums[i]]++;
    }

    for(int i=minNum,j=0; i<=maxNum; i++){
        while (freq[i]>0)
        {
            nums[j++] = i;
            freq[i]--;
        }
    }

    return 0;
}

void printArr(vector<int>& arr,int n){
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

    CountingSort(nums);

    cout<<endl<<"After sorting : ";
    printArr(nums,n);
    return 0;
}