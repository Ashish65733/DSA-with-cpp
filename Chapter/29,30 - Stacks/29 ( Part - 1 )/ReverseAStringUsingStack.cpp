#include<iostream>
#include<climits>
#include<string>
#include<stack>

using namespace std;

string reverseStr(string str){  // O(n)
    string ans;
    stack<char> s;

    for (int i = 0; i < str.size(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
}

int main(){
    string str = "ABCD";

    cout << "Reverse String = " << reverseStr(str) << endl;

    return 0;
}