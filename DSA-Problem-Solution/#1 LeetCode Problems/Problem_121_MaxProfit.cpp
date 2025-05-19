#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int maxProfit = 0 , bestBay = prices[0];

    for (int  i = 1; i < prices.size(); i++)
    {
       if (prices[i] > bestBay){
            maxProfit = max(maxProfit,prices[i]-bestBay);
       }
       bestBay = min(bestBay,prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};

    int maxprofit = maxProfit(prices);

    cout<<"Maximum Profit = "<<maxprofit<<endl;
    
    return 0;
}
