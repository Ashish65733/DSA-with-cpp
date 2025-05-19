#include<iostream>
#include<climits>

using namespace std;

class Example{
public:
    static int x;
};

int Example::x = 0;

void count(){
    static int a = 0;
    cout << "Count = " << a++ << endl;
}

int main(){
    Example Eg1;
    Example Eg2;
    Example Eg3;

    cout << Eg1.x++ << endl;
    cout << Eg2.x++ << endl;
    cout << Eg3.x++ << endl;

    count();
    count();
    count();

    if (1)
    {
        static Example eg;
    }

    cout << "Code ending.." << endl;    
    return 0;
}