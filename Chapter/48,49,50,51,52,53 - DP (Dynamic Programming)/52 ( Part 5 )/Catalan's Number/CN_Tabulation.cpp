#include<iostream>
#include<vector>

using namespace std;

int catalanTab(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<n+1; i++){   // ith catalan
        for(int j=0; j<i; j++){ // 0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main(){

    for(int i=0; i<=6; i++){
        cout << catalanTab(i) <<  " ";
    }
    cout << endl;

    return 0;
}