#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<int,string> m;

    m[101] = "ronak";
    m[110] = "neha";
    m[130] = "ronak";

    m[101] = "rajat";

    cout << m[101] << endl;

    cout << m.count(101) << endl;   // 1
    cout << m.count(120) << endl;   // 0

    for(auto it : m){
        cout << "Key = " << it.first << " , Value = " << it.second <<endl;
    }

    return 0;
}