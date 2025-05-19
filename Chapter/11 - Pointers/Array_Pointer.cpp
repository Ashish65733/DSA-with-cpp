#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};

    cout<<arr<<endl;
    cout<<*arr<<endl;   // Pointing at arr[0] (First value of array)

    // We can impliment Pointer Arithmetic on array

    cout<<*arr+1<<endl;
    cout<<*arr+2<<endl;
    cout<<*arr+3<<endl;
    return 0;
}