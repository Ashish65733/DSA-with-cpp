#include<iostream>
#include<climits>
#include<vector>
using namespace std;
// For a given integer array of size N.You have to find all the occurrences(indices) of a given element(key) and print them.
// Use recursive function to solve this problem.

void printOccurrences(vector<int> &arr,int i,int key){
    if(i == arr.size()){
        return;
    }

    if(arr[i] == key){
        cout << i << " ";
    }
    printOccurrences(arr,i+1,key);
}

int main(){
    vector<int> vec = {3,2,4,5,6,2,7,2,2};
    printOccurrences(vec,0,2);
    return 0;
}