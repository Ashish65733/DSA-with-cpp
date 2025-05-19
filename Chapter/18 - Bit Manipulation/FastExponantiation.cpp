#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void FastExponantiation(int x, int n){
    int ans = 1;
    while(n > 0){
        int lastBit = n & 1;
        if(lastBit){
            ans *= x ;
        }
        x = x*x;
        n = n >> 1;
    }
    cout << ans << endl;
}
int main(){
    FastExponantiation(2,2);
    return 0;
}