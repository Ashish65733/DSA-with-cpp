#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isDuplicate(string str){// O(n)
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch != ')'){  // non-closing
            s.push(ch);
        }else{  // closing
            if(s.top() == '('){
                return true; // DUPLICATE
            }
            while(s.top() != '('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    string str1 = "((a+b))";    // invalid : true
    string str2 = "((a+b)+(c+d))";   // valid : false

    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2) << endl;

    return 0;
}