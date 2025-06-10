#include<iostream>
#include<climits>
#include<string>

using namespace std;
// Leetcode 1221 - split a String in Balanced String : 

int balancedStringSplit(string s){
    int BalancedString = 0;
    int countR = 0, countL = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'R'){
            countR++;
        }else{
            countL++;
        }

        if(countR == countL){
            countR = countL = 0;
            BalancedString++;
        }
    }

    return BalancedString;
}

int main(){
    string s = "RLRRLLRLRL";
    // string s = "RLRRRLLRLL";

    cout << "Maximum number of balanced string = " << balancedStringSplit(s) << endl;
    return 0;
}