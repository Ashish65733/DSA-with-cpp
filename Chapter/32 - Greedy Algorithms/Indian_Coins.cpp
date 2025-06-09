#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Indian coins are set of canonical values

int getMinChange(vector<int> coins, int v){ // O(n) , If sorting is needed in coins vector -> O(n log n)
    int n = coins.size();
    int ans = 0;

    cout << "Coins needed : ";
    for(int i=n-1; i>=0 && v > 0; i--){
        if(v >= coins[i]){
            int c = v / coins[i];
            ans += c;
            cout << coins[i] << "*" << c << " ";
            v %= coins[i];
        }
    }
    cout << endl;
    return ans;
}

int main(){
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int v = 590;
    // int v = 1099;

    cout << "Minimum No. of coins for change : " << getMinChange(coins, v) << endl;

    return 0;
}