#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;
    int** ptr2 = &ptr;
    int *Nptr = NULL;    // Null Pointer

    cout<< *(&a)<<endl;     // Value at address &a
    cout<< *(ptr)<<endl;     // Value at address ptr

    cout<< ptr <<endl;
    cout<< *(ptr2)<<endl;     // Value at address ptr2

    cout<< **(ptr2)<<endl;     // Value at address (value at address ptr2)
    return 0;
}