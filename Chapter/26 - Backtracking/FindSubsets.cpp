#include<iostream>
#include<climits>
#include<string>
using namespace std;

void printSubString(string str,string subset){
    if(str.size() == 0){
        cout << '"' << subset << '"' << endl;
        return;
    }
    char ch = str[0];

    //Yes choice
    printSubString(str.substr(1,str.size()-1),subset+ch);

    //No choice
    printSubString(str.substr(1,str.size()-1),subset);
    
}
int main(){
    string str = "abc";
    string subset = "";
    printSubString(str,subset);
    return 0;
}