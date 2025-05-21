#include<iostream>
#include<climits>

using namespace std;
const int MOD = 1e9 + 7;
// Leetcode Problem : 1922
// Even num in 0 to 9 : 0,2,4,6,8 = 5
// Prime num in 0 to 9 : 2,3,5,7 = 4

int FE(int x, int n){ // Fast Exponentiation
    int ans = 1;
    while(n > 0){
        int lastBit = n & 1;
        if(lastBit){
            ans = (ans*x) % MOD;
        }
        x = (x*x) % MOD ;
        n = n >> 1;
    }
    return ans;
}
int countOfGoodNum(int n){
    if (n % 2 == 0){
        int EvenIdx = n/2;
        int OddIdx = n/2 ;
        return (FE(5,EvenIdx))*(FE(4,OddIdx))%MOD; // (5^evenIdx)*(4^oddIdx) % (10^9 + 7)
    }else{
        int OddIdx = n/2;
        int EvenIdx = OddIdx + 1;
        return (FE(5,EvenIdx))*(FE(4,OddIdx))%MOD; // (5^evenIdx)*(4^oddIdx) % (10^9 + 7)
    }  
}
int main(){
    cout << countOfGoodNum(4) << endl;
    return 0;
}