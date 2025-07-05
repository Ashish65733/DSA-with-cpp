#include<iostream>
#include<vector>

using namespace std;

// same as Catalan's Number
int mountainRange(int n){
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 3;

    cout << mountainRange(n) << endl;

    return 0;
}