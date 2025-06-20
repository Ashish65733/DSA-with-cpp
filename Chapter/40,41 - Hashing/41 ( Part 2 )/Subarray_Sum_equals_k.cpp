#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int largestSubarrWith0Sum(vector<int> arr,int k){
    unordered_map<int, int> m;  // sum, count
    m[0] = 1;
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size(); j++){
        sum += arr[j];

        if(m.count(sum-k)){
            ans += m[sum-k];
        }

        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }
    
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    int k = 3;

    cout << "count of Subarray sum with sum " << k << " : " << largestSubarrWith0Sum(arr,k) << endl;

    return 0;
}