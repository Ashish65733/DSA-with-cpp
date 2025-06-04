#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreater(vector<int> arr,vector<int> &ans){  // O(n)
    stack<int> s;
    int idx = arr.size()-1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for(idx=idx-1; idx >= 0; idx--){
        int curr = arr[idx];
        while(!s.empty() && curr >= s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }
        s.push(arr[idx]);
    }

    return ans;
}

int main(){
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = {0, 0, 0, 0, 0};
    ans = nextGreater(arr,ans);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}