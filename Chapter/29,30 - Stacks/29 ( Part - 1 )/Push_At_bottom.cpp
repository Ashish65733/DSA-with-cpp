#include<iostream>
#include<climits>
#include<stack>

using namespace std;

void pushAtBottom(stack<int> &s,int val){   // O(n)
    if(s.empty()){
        s.push(val);    // push at top = push at bottom where stack is empty..
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s,val); 
    s.push(temp);
}

int main(){
    stack<int> s;
    
    s.push(3);
    s.push(2);
    s.push(1);
    
    pushAtBottom(s,4);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}