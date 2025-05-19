#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Print{
public:
    void show(int n){
        cout << "int : " << n << endl;
    }
    void show(string s){
        cout << "string : " << s << endl;
    }
};

int main(){
    Print p;
    p.show(10);
    p.show("Yo!");
    return 0;
}