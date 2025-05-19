#include<iostream>
using namespace std;

// Two ways of Pass By Reference : 
void UsingPointer(int *ptr){    // Pass By Reference using Pointer\
    *ptr = 20;
}

void UsingAlias(int &b){    // Pass By Reference using Alias
   b = 50;
}

int main(){
    int a = 10;
    cout <<"Initial : "<< a << endl;

    UsingPointer(&a);
    cout <<"After Change Using Pointer : "<< a << endl;

    UsingAlias(a);
    cout <<"After Change Using Alias : "<< a << endl;
    return 0;
}