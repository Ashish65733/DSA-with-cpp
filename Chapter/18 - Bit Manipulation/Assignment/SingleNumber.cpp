#include<iostream>
#include<climits>
using namespace std;
// 136 - Single Number
int SingleNum(int nums[],int n){
    int ans = nums[0];
    for(int i=1; i < n; i++){
        ans = ans ^ nums[i];
    }
    return ans;
}

int main(){
    int arr[] = {4,1,2,1,2};
    cout << SingleNum(arr,5) << endl;
    return 0;
}