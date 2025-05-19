#include<iostream>
using namespace std;

int main(){
    
    int a = 10;
    int *ptr = &a;

    // Increment / Decrement :
    cout<<"Increment / Decrement : "<<endl;

    cout<<ptr<<endl;
    ptr++;
    cout<<ptr<<endl;
    ptr--;
    cout<<ptr<<endl;

    // Add / Subtract Number :
    cout<<"Add / Subtract Number :"<< endl;

    cout<< ptr+2 <<endl;
    cout<< ptr-1 <<endl;

    // Subtract Ptr :
    cout<<"Subtract Ptr :"<<endl;

    int b = 20;
    int *ptr2 = &b;
    cout<<(ptr-ptr2)<<endl;

    // Compare (<,<=,>,>=,==,!=) :
    cout<<"Compare (<,<=,>,>=,==,!=) :"<<endl;

    cout<<(ptr > ptr2)<<endl;
    cout<<(ptr == ptr2)<<endl;

    return 0;
}