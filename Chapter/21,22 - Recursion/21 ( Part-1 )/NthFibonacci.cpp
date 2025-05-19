#include<iostream>
#include<climits>

using namespace std;

int fibonacci(int n){
    // if(n == 0) return 0;
    // if(n == 1) return 1;
    if(n == 0 || n == 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    cout << fibonacci(5) << endl;
    return 0;
}