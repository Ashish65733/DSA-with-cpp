#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int lastOccurence(vector<int> &arr, int i,int tar){
    if(i == arr.size()){
        return -1;
    }

    int idxFound = lastOccurence(arr,i+1,tar);
    if(idxFound == -1 && arr[i] == tar){ 
        return i;
    }
    return idxFound;
}

int main(){
    vector<int> arr = {1,2,4,4,5};

    cout << lastOccurence(arr,0,4) << endl;
    return 0;
}