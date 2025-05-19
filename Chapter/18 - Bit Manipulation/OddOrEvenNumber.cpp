#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void oddOrEven(int n){
    (!(n & 1)) ? cout << "Even" << endl : cout << "Odd" << endl ;
}

int main(){
    
    oddOrEven(2);
    oddOrEven(5);

    return 0;
}