#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> arr,int n ,int m,int mid){
    int student = 1,pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid<arr[i]) return false;
        if (pages+arr[i] <= mid){   //!
            pages += arr[i];
        }else{
            student++;
            pages = arr[i];
        }     
    }
    return student<=m ? true : false;  //!
}
int MaxPages(vector<int> arr,int n,int m){
    if(n<m) return -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    int st = 0 ,end = sum,ans = -1; //!

    while (st<=end) {
        int mid = st + (end - st)/2;
        if(isValid(arr,n,m,mid)){
            ans = mid;      //!
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}
int main(){
    // vector<int> arr = {2,1,3,4};
    vector<int> arr = {15,17,20};
    int n = arr.size();
    int m = 2;

    int result = MaxPages(arr,n,m);

    cout<<"Maximum Pages : "<<result<<endl;
    return 0;
}