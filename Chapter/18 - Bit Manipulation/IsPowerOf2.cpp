#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool isPowerOf2(int n){
    if(!(n & (n-1))){
        return true;
    }else{
        return false;
    }
}

int main(){
    cout << isPowerOf2(10) << endl;
    cout << isPowerOf2(32) << endl;
    return 0;
}   