#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int mcmRec(vector<int> arr, int i, int j){  // return minCost
    if(i == j){
        return 0;
    }

    int minCost = INT_MAX;

    for(int k=i; k<j; k++){
        // (i, k)
        int cost1 = mcmRec(arr,i,k);
        // (k+1, j)
        int cost2 = mcmRec(arr,k+1,j);

        // curr partition cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);

        minCost = min(minCost,currCost);
    }

    return minCost;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 3};  // n -> n-1 matrices (1 to n-1)
    int n = arr.size();

    cout << mcmRec(arr,1,n-1) << endl;

    return 0;
}