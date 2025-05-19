#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void NextPermutation(vector<int>& A,int n){//   TC : O(n) & SC : O(1)
    // Find Pivot
    int piv = -1;
    for (int i = n-2; i >= 0; i--){
        if (A[i] < A[i+1]){
            piv = i;
            break;
        }
    }
    if (piv == -1){
        reverse(A.begin(),A.end()); // in place change
        return;
    }
    
    // 2nd step : next larger element
    for (int i = n-1 ; i > piv; i--){
        if (A[i] > A[piv]){
            swap(A[i],A[piv]);
            break;
        }   
    }
    
    // 3rd step : reverse (piv+1 to n-1)
    // reverse(A.begin() + pivot , A.end());
    
    int i = piv + 1, j = n-1;
    while(i <= j){
        swap(A[i++],A[j--]);
    }
    
}

int main(){
    vector<int> A = {1,2,3,6,5,4};
    int n = A.size();

    NextPermutation(A,n);

    for (int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }

    return 0;
}