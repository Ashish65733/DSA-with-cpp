#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void updateBit(int num, int i, int val){
    num = num & ~(1 << i); // clearing the ith bit

    num = num | (val << i); // setting ith bit with val

    cout << num << endl;
}
int main(){
    updateBit(7,2,0);
    return 0;
}