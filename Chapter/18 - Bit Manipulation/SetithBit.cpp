#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int SetIthBit(int n,int i){
    int BitMask = 1 << i ;
    return (n | BitMask) ;
}
int main(){
    cout << SetIthBit(6,0) << endl;
    return 0;
}