#include<iostream>
#include<climits>
#include<string>

using namespace std;
// Leetcode 1903 - Largest Odd Number in String :

string largestOddNumber(string s){
    int lastIdx = -1; // lastIdx of substring

    for(int i=s.length()-1; i>=0; i--){
        int num = s[i] - 0;
        if(num % 2 != 0){
            lastIdx = i;
            return s.substr(0,lastIdx+1);
        }
    }

    return "";    
}
int main(){
    string s = "35427";

    cout << "Largest Odd number substring = " << largestOddNumber(s) << endl;
    return 0;
}