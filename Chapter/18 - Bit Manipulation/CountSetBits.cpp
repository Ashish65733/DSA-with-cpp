#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void countSetBits(int num){
    int count = 0;
    while(num > 0){
        int lastBit = num & 1 ;
        count += lastBit ;
        num = num >> 1;
    }
    cout << count << endl;
}
int main(){
    countSetBits(10);
    return 0;
}