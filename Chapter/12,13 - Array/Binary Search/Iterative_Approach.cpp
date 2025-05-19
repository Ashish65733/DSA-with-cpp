#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int> arr,int tar){  // Iterative
    int st = arr[0], end = arr.size()-1;

    while (st <= end){
        int mid = st + ((end-st)/2) ; // mid = (st+end)/2
        if(tar>arr[mid]){
            st = mid + 1;
        }else if(tar<arr[mid]){
            end = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> arr1 = {-1,0,3,4,5,9,12};
    int tar1 = 12;

    cout<<binarysearch(arr1,tar1)<<endl;

    vector<int> arr2 = {-1,0,3,4,5,9,12,2};
    int tar2 = 9;
    
    cout<<binarysearch(arr2,tar2)<<endl;

    return 0;
}