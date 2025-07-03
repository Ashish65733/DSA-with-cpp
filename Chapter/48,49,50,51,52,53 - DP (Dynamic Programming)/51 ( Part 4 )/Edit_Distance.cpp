#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Leetcode 72 : Edit Distance
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int j=0; j<=m; j++){    // 0th row initialize - insert ops
        dp[0][j] = j;
    }

    for(int i=0; i<=n; i++){    // 0th col initialize - delete ops
        dp[i][0] = i;
    }

    // bottom-up fill
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(){
    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1,word2) << endl;
    
    return 0;
}