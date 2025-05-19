#include<iostream>
#include<vector>
using namespace std;

int SingleElement(vector<int> arr){
    int n = arr.size();
    if(n==1) return arr[0];

    for (int i = 0; i < n; i++)
    {
       if(arr[i-1]!=arr[i] && arr[i]!=arr[i+1]) return arr[i];       
    }
}
int main(){
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    vector<int> arr2 = {3,3,7,7,10,11,11};

    int result = SingleElement(arr);
    // int result = SingleElement(arr2);

    cout<<"Single Element in Sorted Array : "<<result<<endl;
    return 0;
}