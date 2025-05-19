#include<iostream>
using namespace std;

void func(){
    int *ptr = new int; // This will create a new block in the heap memory , This is the dynamic 
    *ptr = 10;
    cout<<*ptr<<endl;
    delete ptr; // This is very important, otherwise it will lead to memory leak
}

int main(){
    func();

    return 0;
}