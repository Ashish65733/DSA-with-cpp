#include<iostream>
#include<climits>

using namespace std;
int pow(int x,int n){ // O(n)
    if(n == 1){
        return x;
    }
    x *= pow(x,n-1);
    return x;
}
int main(){
    cout << pow(2,2) << endl;
    return 0;
}