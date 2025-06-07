#include<iostream>
#include<deque>

using namespace std;

// There is 2 ways of implementing Stack using Deque :
// push -> deq.push_front(), pop -> deq.pop_front(), top -> deq.front()
// push -> deq.push_back(), pop -> deq.pop_back(), top -> deq.back()

class Stack{
    deque<int> deq;
public:
    void push(int val){
        deq.push_front(val);
    }
    void pop(){
        deq.pop_front();
    }
    int top(){
        return deq.front();
    }
    bool empty(){
        return deq.empty();
    }
};

int main(){
    Stack s;

    for(int i = 1; i<=5; i++){
        s.push(i);
    }

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}