#include<iostream>
#include<climits>

using namespace std;
// This is recursive approach, this is not most optimal solution
// Optimal solution is done by DP(Dynamic Programming) approach

// 2*n
int tilingProblem(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return tilingProblem(n-1) + tilingProblem(n-2);
    // int ans1 = tilingProblem(n-1); // vertical
    // int ans2 = tilingProblem(n-2); // Horizontal
    // return ans1+ans2;
}
int main(){
    cout << tilingProblem(5) << endl;
    return 0;
}