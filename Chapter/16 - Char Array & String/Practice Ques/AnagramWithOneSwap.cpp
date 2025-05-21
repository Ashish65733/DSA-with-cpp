#include<iostream>
#include<string>
using namespace std;
/*
--> you are given two strings s1 and s2 of equal length.A string swap is an
Operation where you choose two indices in a string (not necessarily diffrent) and
swap the characters at these idices.

Return true if it possible to make both string equal by performing at most one
string swap on exactly one of the strings. Othewise,return false.
*/
bool areAlmostEqual(string str1,string str2){
    if (str1.length() != str2.length()) {
        return false;
    }
    int diffIdx[2] , idx = 0;
    for (int i = 0; i < str1.length(); i++){
        if (str1[i] != str2[i]){
            if (idx >= 2) return false;
            diffIdx[idx++] = i ;
        } 
    }
    if(idx == 0) return true;
    if(idx != 2) return false;
    swap(str2[diffIdx[0]],str2[diffIdx[1]]);
    return str1==str2 ;
}
int main(){
    string str1 = "bank";
    string str2 = "kanb";

    if (areAlmostEqual(str1,str2)){
        cout << "True" << endl ;
    }else{
        cout << "False" << endl ;
    }
    return 0;
}