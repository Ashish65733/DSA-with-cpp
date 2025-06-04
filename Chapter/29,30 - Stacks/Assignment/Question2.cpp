#include <iostream>
#include <string>
#include <stack>

using namespace std;

string decodeString(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string curr = "";
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');  
        } else if (c == '[') {
            numStack.push(num);
            num = 0;
            strStack.push(curr);
            curr = "";
        } else if (c == ']') {
            int repeat = numStack.top(); 
            numStack.pop();

            string temp = "";

            string prev = strStack.top(); 
            strStack.pop();
            
            for (int i = 0; i < repeat; i++){
                temp += curr;
            }
            curr = prev + temp;
        } else {
            curr += c;
        }
    }

    return curr;
}

int main() {
    string str = "3[a2[c]]";
    cout << "Decoded String: " << decodeString(str) << endl;
    return 0;
}
