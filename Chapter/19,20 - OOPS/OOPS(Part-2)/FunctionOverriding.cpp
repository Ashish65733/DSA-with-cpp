#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Perent{
public:
    void show(){
        cout << "This is Perent class show.." << endl;
    }
};
class Child : public Perent{
public:
    void show(){
        cout << "This is Child class show.." << endl;
    }
};
int main(){
    Child c1;
    c1.show();
    return 0;
}