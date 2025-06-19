#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string,int> m;

    m["India"] = 150;
    m["China"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;
    m["India"] = 175;

    // cout << m["India"] << endl;

    for(pair<string,int> country : m){
        cout << country.first << "," << country.second << endl;
    }

    // count : 1 -> exist, 0 -> doesn't exist

    m.erase("Nepal");
    if(m.count("Nepal")){
        cout << "Nepal exist" << endl;
    }else{
        cout << "Nepal doesn't exist" << endl;
    }

    return 0;
}