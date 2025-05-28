#include<iostream>
#include<climits>
#include<string>
using namespace std;

int GridWays(int row, int col, int n, int m,string ans){    // O(2^(n+m)) --> Using DP Time Complexity reduces to O(n*m)

    if(row == n-1 && col == m-1){
        cout << ans << endl;
        return 1;
    }

    if(row >= n || col >= m){
        return 0;
    }

    // Right 
    int way2 = GridWays(row,col+1,n,m,ans+'R');
    // Down 
    int way1 = GridWays(row+1,col,n,m,ans+'D');

    return way1+way2;
}

int main(){
    string ans = "";
    cout << "Total ways : " << GridWays(0,0,3,3,ans) << endl;
    return 0;
}