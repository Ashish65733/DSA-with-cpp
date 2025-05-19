#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispossible(vector<int> &arr,int n,int c,int mid){
    int cow = 1,position = arr[0];
    for (int i = 0; i < n; i++){
        if ((arr[i]-position) >= mid){
            position = arr[i];
            cow++;
        }
        if(cow==c) return true;
    }
    return false; 
}
int MaxDistance(vector<int> &arr,int n,int c){
    sort(arr.begin(),arr.end());    //NlogN
    int st = 1,end = arr[n-1]-arr[0],ans = -1;

    while (st<=end){//)(log(range) * N)
        int mid = st + (end - st)/2;
        if(ispossible(arr,n,c,mid)){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }  
    return ans;  
}   
int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = arr.size();
    int c = 3;

    int result = MaxDistance(arr,n,c);

    cout<<"Mainimum Distance : "<<result<<endl;
    return 0;
}