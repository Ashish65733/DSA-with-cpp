#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int lp, int rp, int tar){
    if(lp > rp){
        return -1;
    }
    int mid = rp + (lp-rp)/2;
    if(arr[mid] == tar){
        return mid;
    }else if(arr[mid] > tar){
        return binarySearch(arr,lp,mid-1,tar);
    }else{
        return binarySearch(arr,mid+1,rp,tar);
    }
}

int main(){
    vector<int> vec ={1,2,3,4,5,7,8,9};
    
    cout << "Value found at index : " << binarySearch(vec,0,vec.size()-1,8) << endl;
    return 0;
}