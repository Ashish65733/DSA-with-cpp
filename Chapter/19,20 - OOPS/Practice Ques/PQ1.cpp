#include<iostream>
#include<climits>

using namespace std;
// Predict the output :
class Perent{
public: 
    Perent(){
        cout << "Constructor of Perent." << endl;
    }
    ~Perent(){
        cout << "Destructor of Perent." << endl;
    }
};

class Child : public Perent{
public: 
    Child(){
        cout << "Constructor of Child." << endl;
    }
    ~Child(){
        cout << "Destructor of Child." << endl;
    }
};

int main(){
    Child c1;
    return 0;
}