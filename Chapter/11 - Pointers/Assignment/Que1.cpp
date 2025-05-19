#include<iostream>
#include<climits>

using namespace std;
// what will be the output of this program?
int main(){
    int x;
    int *ptr;
    x = 7;
    ptr = &x;
    cout << *ptr << endl;
    return 0;
}