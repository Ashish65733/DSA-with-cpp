#include<iostream>
#include<vector>
using namespace std;

int PeakINXMountainArr(vector<int> arr){
    int n = arr.size();

    for (int i = 1; i < n-1; i++)
    {
        if (arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            return i;
        }      
    }
}

int main(){
    vector<int> arr = {0,3,8,9,5,2};

    int result = PeakINXMountainArr(arr);

    cout<<"Peak Index in Given Mountain Array = "<<result<<endl; 
    return 0;
}
