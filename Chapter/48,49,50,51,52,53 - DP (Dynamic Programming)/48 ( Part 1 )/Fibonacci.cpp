#include<iostream>
#include<vector>

using namespace std;

int fib(int n){    // O(2^n)
    if(n == 0 || n == 1){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

// Using Dynamic Programing :

int fibDP(int n,vector<int> &f){    // O(n) - Using memoization
    if(n == 0 || n == 1){
        return n;
    }

    if(f[n] != -1){
        return f[n];
    }
 
    f[n] = fibDP(n-1,f) + fibDP(n-2,f);

    return f[n];  
}

int fibTab(int n){  // O(n) - Using Tabulation
    vector<int> fib(n+1,-1);    // fib[i] -> ith fib
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main(){
    int n = 6;

    vector<int> f(n+1, -1);

    // cout << fib(n) << endl;
    // cout << fibDP(n,f) << endl;
    cout << fibTab(n) << endl;
    return 0;
}