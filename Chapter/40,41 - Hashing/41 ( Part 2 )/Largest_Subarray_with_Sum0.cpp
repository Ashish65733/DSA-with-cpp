#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

// sum[i,j] = sum[j] - sum[i-1]
int largestSubarrWith0Sum(vector<int> arr){
    unordered_map<int, int> m;  // sum, idx
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size(); j++){
        sum += arr[j];

        if(m.count(sum)){
            int currSum = j-m[sum]; // j-idx
            ans = max(ans, currSum);
        }else{
            m[sum] = j;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    cout << "Largest Subarray with sum 0 : " << largestSubarrWith0Sum(arr) << endl;

    return 0;
}