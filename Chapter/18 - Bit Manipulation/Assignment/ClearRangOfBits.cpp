#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void clearRangeOfBits(int num, int i, int j){
    // 15,1,3
    int bitMask = (~0) << j+1; // 11110000

    bitMask = bitMask | (~((~0)<<i)); // 11110000 | 00000001 = 11110001
    
    num = num & bitMask ;   // 00001111 & 11110001 = 00000001
    cout << num << endl;
}
int main(){
    clearRangeOfBits(15,1,3);
    return 0;
}