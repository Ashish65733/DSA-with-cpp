#include<iostream>
#include<climits>

using namespace std;
int pow(int x,int n){ // O(log n)
    if (n == 0){
        return 1;
    }
    // int halfPow = pow(x,n/2);
    // if(n % 2 == 0){
    //     x = halfPow * halfPow;
    // }else{
    //     x *= halfPow * halfPow;
    // }
    int halfPow = pow(x,n/2);
    int halfPowSquare = halfPow * halfPow ;

    if(n % 2 != 0){ // Odd power
        return x * halfPowSquare;
    }else{
        return halfPowSquare;
    }
}
int main(){
    cout << pow(2,10) << endl;
    return 0;
}