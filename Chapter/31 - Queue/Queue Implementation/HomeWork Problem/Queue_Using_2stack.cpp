#include<iostream>
#include<stack>

using namespace std;

// Queue using 2 stack : pop -> O(n), push -> front -> O(1)

class Queue{
    stack<int> s1;
    stack<int> s2;
    int frontEl;
public:
    void push(int val){
        if(s1.empty()){
            frontEl = val;
        }
        s1.push(val);
    }
    void pop(){
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        if(!s2.empty()){
            frontEl = s2.top();
        }
        // s2 -> s1
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int front(){
        if (s1.empty()){
            return -1;
        }
        
        return frontEl;
    }
    bool empty(){
        return s1.empty();
    }
};

int main(){
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}