#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices,int n){
    int bestBuy[10000];
    bestBuy[0] = INT_MAX;
    for (int i = 1; i < prices.size(); i++){
        bestBuy[i] = min(bestBuy[i-1] ,prices[i-1]);
    }

    int profit = 0;
    for (int i = 0; i < prices.size(); i++){
        int currProfit = prices[i] - bestBuy[i];

        profit = max(profit,currProfit);
    }

    return profit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int n = sizeof(prices) / sizeof(int);

    cout << "Maximum Profit = "<< maxProfit(prices,n) << endl;
    
    return 0;
}