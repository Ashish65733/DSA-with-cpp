#include<iostream>
#include<vector>

using namespace std;
// Leetcode - 714 : Best Time to Buy and Sell Stock with Transaction Fee

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    
    int hold = -prices[0];
    int noHold = 0;

    for(int i=1; i<n; i++){
        hold = max(hold, noHold-prices[i]);
        noHold = max(noHold, hold+prices[i]-fee);
    }
    return noHold;
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    cout << maxProfit(prices,fee) << endl;
    
    return 0;
}