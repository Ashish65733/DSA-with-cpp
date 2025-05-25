#include<iostream>
#include<climits>

using namespace std;

const int MOD = 1e9 + 7;
int FE(long long x, long long n){ // Fast Exponentiation
    long long ans = 1;
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
int countGoodNumbers(long long n) {
    if (n % 2 == 0){
        long long EvenIdx = n/2;
        long long OddIdx = n/2 ;
        return (1LL*FE(5,EvenIdx))*(FE(4,OddIdx))%MOD; // (5^evenIdx)*(4^oddIdx) % (10^9 + 7)
    }else{
        long long OddIdx = n/2;
        long long EvenIdx = OddIdx + 1;
        return (1LL*FE(5,EvenIdx))*(FE(4,OddIdx))%MOD; // (5^evenIdx)*(4^oddIdx) % (10^9 + 7)
    }  
}
int main(){
    cout << countGoodNumbers(2) << endl;
    return 0;
}