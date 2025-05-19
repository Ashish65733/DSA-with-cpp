#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Perent{
public:
    virtual void hello(){
        cout << "Perent Hello!" << endl;
    }
};
class Child : public Perent{
public:
    void hello(){
        cout << "Child Hello!" << endl;
    }
};
int main(){
    Child c1;
    Perent *ptr;
    ptr = &c1;  // Run time Binding
    
    ptr->hello(); 
    return 0;
}