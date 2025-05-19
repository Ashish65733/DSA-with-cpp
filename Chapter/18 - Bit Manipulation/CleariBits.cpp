#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void clearIBits(int num,int i){
    int BitMask = (~0) << i; // let's say i = 2, so BitMask = 11111111111111111111111111111100 << 2 =  11111111111111111111111111111100
    num = num & BitMask; // This makes last i bits as 0 and the rest bits as it is.
    cout << num << endl;
}
int main(){
    clearIBits(15,2);
    return 0;
}