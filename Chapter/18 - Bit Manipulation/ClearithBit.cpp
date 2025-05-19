#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int ClearIthBit(int n,int i){
    int BitMask = ~(1 << i) ;
    return (n & BitMask) ;
}
int main(){
    cout << ClearIthBit(6,2) << endl;
    return 0;
}