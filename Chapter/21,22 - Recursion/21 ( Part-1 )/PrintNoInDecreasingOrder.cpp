#include<iostream>
#include<climits>

using namespace std;

int print(int n){
    if(n==0) return 0;
    cout << n << " " ;  // 1
    print(n-1);         // 2
    // By swapping line no. 1 and 2 we can print numbers in increasing order
}

int main(){
    print(10);
    return 0;
}