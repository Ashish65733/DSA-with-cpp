#include<iostream>
#include<vector>
#include<string>

using namespace std;


// Longest Common SubString
int lcsTab(string str1,string str2){    // O(n*m)
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << lcsTab(str1,str2) << endl;  // 4 - "abdg"

    return 0;
}