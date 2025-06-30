#include<iostream>

using namespace std;

// Variation of fibonacci problem : 

int countWayRec(int n){ // O(2^n)
    if(n == 0 || n == 1){
        return 1;
    }

    return countWayRec(n-1) + countWayRec(n-2);
}

int main(){
    int n = 5;

    cout << countWayRec(n) << endl;
    return 0;
}