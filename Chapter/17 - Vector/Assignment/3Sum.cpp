#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(arr);

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}