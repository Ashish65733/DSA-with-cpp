#include<iostream>
#include<vector>
using namespace std;

int RecursiveBS(vector<int> arr,int tar,int st,int end){  // Iterative

    if (st <= end){
        int mid = st + ((end-st)/2) ; // mid = (st+end)/2
        if(tar>arr[mid]){   // 2nd half array
            return RecursiveBS(arr,tar,mid+1,end);
        }else if(tar<arr[mid]){     // 1st half array
            return RecursiveBS(arr,tar,st,mid-1);
        }else{      // mid = target
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {-1,0,3,4,5,9,12};
    int tar = 12 , st = arr[0], end = arr.size()-1;

    cout<<RecursiveBS(arr,tar,st,end)<<endl;

    return 0;
}