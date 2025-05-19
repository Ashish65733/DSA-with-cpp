#include<iostream>
#include<climits>

using namespace std;

int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int main(){
    int n;
    cout << "Enter number : " ;
    cin >> n;

    cout << n << "! = " << factorial(n) << endl;
    return 0;
}