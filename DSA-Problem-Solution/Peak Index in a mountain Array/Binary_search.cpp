#include<iostream>
#include<vector>
using namespace std;

int PeakINXMountainArr(vector<int> arr){
    int n = arr.size();
    int st = arr[1],end = arr[n-2];

    for (int i = 0; i < n; i++)
    {
        int mid = st + (end-st)/2;
        if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid-1]<arr[mid]){
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
