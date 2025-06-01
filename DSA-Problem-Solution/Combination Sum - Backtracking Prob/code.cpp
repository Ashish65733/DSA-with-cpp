#include<iostream>
#include<climits>
#include<vector>
#include<set>

using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int>& arr,int idx, int tar,vector<vector<int>> &ans,vector<int> &combin){
    if(idx == arr.size() || tar < 0){
        return;
    }
    if(tar == 0){
        if(s.find(combin) == s.end()){
            s.insert(combin);
            ans.push_back(combin);
            cout << " [ " ;
            for (int i = 0; i < combin.size(); i++)
            {
                cout << combin[i] << " " ;
            }
            cout << "] " << endl;
        }
        return;
    }

    combin.push_back(arr[idx]);
    //single
    getAllCombinations(arr,idx+1,tar-arr[idx],ans,combin);
    //Multiple
    getAllCombinations(arr,idx,tar-arr[idx],ans,combin);
    combin.pop_back();
    //exclusion
    getAllCombinations(arr,idx+1,tar,ans,combin);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> combin;     
    
    getAllCombinations(arr,0,target,ans,combin);
    return ans;
}

int main(){
    vector<int> vec = {2,3,5};

    combinationSum(vec,8);

    return 0;
}