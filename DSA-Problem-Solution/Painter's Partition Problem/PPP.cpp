#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool IsPossible(vector<int> arr,int n,int m,int mid){
    int painters = 1, Time = 0;
    for (int i = 0; i < n; i++){
        if(Time+arr[i] <= mid){
            Time += arr[i];
        }else{
            painters++;
            Time = arr[i];
        }
    }
   return painters<=m; 
}
int MinTime(vector<int> arr,int n,int m){
    int sum = 0,MaxVal = INT_MIN;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        MaxVal = max(MaxVal,arr[i]);
    }

    int st = MaxVal , end = sum , ans = -1;
    while (st<=end){
        int mid = st + (end - st)/2;
        if(IsPossible(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}
int main(){
    // vector<int> arr = {2,1,3,4};
    vector<int> arr = {40,30,10,20};
    int n = arr.size();
    int m = 2;

    int result = MinTime(arr,n,m);

    cout<<"Mainimum Time : "<<result<<endl;
    return 0;
}