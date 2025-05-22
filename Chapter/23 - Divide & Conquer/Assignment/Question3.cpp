#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Inversion Count :

// This is modified mergeSort 
int merge(vector<int> &arr,int si,int ei,int mid){ // O(n)
    int i = si;
    int j = mid+1;
    vector<int> temp;
    int invCount = 0 ;  // *

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
            invCount += (mid-i+1); // *
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
         temp.push_back(arr[j++]);
    }
    for (int i = si, x = 0; i <= ei; i++){
        arr[i] = temp[x++];
    }
    return invCount;    // *
}

int mergeSort(vector<int> &arr,int si,int ei){ // O(n * log n)
    if(si < ei){    // *
        int mid = si + (ei-si)/2;

        // Divide :
        int leftInvCount = mergeSort(arr,si,mid);      //Left Half      *
        int rightInvCount = mergeSort(arr,mid+1,ei);    //Right Half    *
        // Conquer :
        int invCount = merge(arr,si,ei,mid);    // *

        return leftInvCount + rightInvCount + invCount; // *
    }
    return 0;
}

int main(){
    vector<int> arr = {6,3,5,2,7};

    cout << "Inv count = " << mergeSort(arr,0,arr.size()-1) << endl;
    return 0;
}