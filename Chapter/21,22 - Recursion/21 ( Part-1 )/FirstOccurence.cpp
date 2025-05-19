#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int firstOccurence(vector<int> &arr, int i,int tar){
    if(i == arr.size()) return -1;

    if(tar == arr[i]) return i;

    return firstOccurence(arr,i+1,tar);
}

int main(){
    vector<int> arr = {1,2,4,4,5};

    cout << firstOccurence(arr,0,4) << endl;
    return 0;
}