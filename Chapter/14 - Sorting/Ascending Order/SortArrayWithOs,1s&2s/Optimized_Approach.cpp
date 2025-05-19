#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int>& arr,int n){ // 0(n)
    int count0=0,count1=0,count2=0;

    // 0(n)
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }

    // 0(n)
    int currInd = 0;
    for (int i = 0; i < count0; i++)
    {
        arr[currInd++] = 0;
    }
    for (int i = 0; i < count1; i++)
    {
        arr[currInd++] = 1;
    }
    for (int i = 0; i < count2; i++)
    {
        arr[currInd++] = 2;
    } 
}

int main(){
    vector<int> arr = {2,0,2,1,1,0,1,2,0,0};
    int n = arr.size();

    sortArray(arr,n);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}