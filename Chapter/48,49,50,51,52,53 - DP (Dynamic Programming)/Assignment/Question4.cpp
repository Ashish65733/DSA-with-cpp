#include<iostream>
#include<vector>

using namespace std;
// Leetcode - 22 : Generate Parentheses

void GPhelper(string curr, int open, int close, int n, vector<string> &ans){
    if(curr.size() == 2*n){
        ans.push_back(curr);
        return;
    }
    if(open < n){
        GPhelper(curr + '(', open+1, close, n, ans);
    }
    if(close < open){
        GPhelper(curr + ')', open, close+1, n, ans);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    GPhelper("",0,0,n,ans);
    return ans;
}

int main(){
    int n = 3;
    
    vector<string> result = generateParenthesis(n);

    for(string s : result){
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}