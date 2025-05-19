#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int GetIthBit(int n,int i){
    int BitMask = 1 << i ;

    if (!(n & BitMask)){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    cout << GetIthBit(6,2) << endl;
    return 0;
}