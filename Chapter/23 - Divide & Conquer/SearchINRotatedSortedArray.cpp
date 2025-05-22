#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Leetcode problem no. 33 
// similer problems : 81, 153, 1752

int search(vector<int> &arr,int si,int ei,int tar){ // O(log n)
    if(si > ei){
        return -1;
    }

    int mid = si + (ei-si)/2;
    if(arr[mid] == tar){
        return mid;
    }

    if(arr[si] < arr[mid]){ // Case 1 : The left part of array is sorted in ascending order
        if(arr[si] <= tar && tar <= arr[mid]){ // Left Part
            return search(arr,si,mid-1,tar);
        }else{  // Right Part
            return search(arr,mid+1,ei,tar);
        }
    }else{ // Case 2 : The right part of array is sorted in sorted in ascending order
        if(arr[mid] <= tar && tar <= arr[ei]){    // Right Part
            return search(arr,mid+1,ei,tar);
        }else{  // Left Part
            return search(arr,si,mid-1,tar);
        }
    }

}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    cout << "Target found at index : " << search(arr,0,arr.size()-1,1) << endl;

    return 0;
}