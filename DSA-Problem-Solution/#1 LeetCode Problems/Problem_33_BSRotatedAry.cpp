#include<iostream>
#include<vector>
using namespace std;

int BSRotatedArray(vector<int> arr,int tar){  // Iterative
    int st = arr[0], end = arr.size()-1;

    while(st<=end){
        int mid = st + (end-st)/2;
        if(arr[mid] == tar){
            return mid;
        }

        if(arr[st] <= arr[mid]){
            if(arr[st] <= tar && tar <= arr[mid]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if(arr[mid] <= tar && tar <= arr[end]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr1 = {3,4,5,6,7,0,1,2};
    int tar1 = 1;

    cout<<BSRotatedArray(arr1,tar1)<<endl;

    vector<int> arr2 = {5,6,7,0,1,2,3,4};
    int tar2 = 1;
    
    // cout<<BSRotatedArray(arr2,tar2)<<endl;

    return 0;
}

// 6359482993
// 