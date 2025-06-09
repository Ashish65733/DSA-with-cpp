#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>

using namespace std;

int minAbsDiff(vector<int> A, vector<int> B){
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int minDiff = 0;

    for(int i=0; i<A.size(); i++){
        minDiff += abs(A[i]-B[i]);
    }

    return minDiff;
}

int main(){
    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 5};

    cout << "Minimum abs Diff = " << minAbsDiff(A,B) << endl;
    return 0;
}