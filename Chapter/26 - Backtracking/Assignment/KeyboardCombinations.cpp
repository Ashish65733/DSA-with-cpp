#include<iostream>
#include<climits>
#include<vector>
#include<string>

using namespace std;
/*
Given a string containing digits from 2-9 inclusive, print all pssible letter combinations that
the keyIdx could represent. You can print the answer in any order.
A mapping of digits to letters (just like on the telephone buttons), Note that 1
does not map to any letters.

Input : digits = "23"
Output : "ad","ae","af","bd","be","bf","cd","ce","cf"

Input : digit = "2"
Output : "a","b","c"

Input : digits = ""
Output : ""
*/

// Leetcode - 17
void solve(string digits, string output, int index, vector<string> &ans, vector<string> &keypad){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    int keyIdx = digits[index] - '0';
    string value = keypad[keyIdx];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,keypad);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.size() == 0){
        return ans;
    }
    string output;
    int index = 0;

    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(digits,output,index,ans,keypad);
    return ans;
}

int main(){
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for(string val : ans){
        cout << val << " " ;
    }
    return 0;
}