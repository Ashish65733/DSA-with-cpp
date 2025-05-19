#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n = 7; 
    int arr[]={3,-4,5,4,-1,7,-8};

    int maxSum = INT_MIN ;
    for (int st = 0; st < n; st++)
    {
        int currSum = 0;
        for (int end = st; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum,maxSum); 
        }  
    }

    cout<<"Max subarray sum = "<<maxSum<<endl;
    return 0;
}