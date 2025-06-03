#include<iostream>
#include<climits>
#include<string>
#include<list>

using namespace std;

// Create Stack using vector with templet using STL
template<class type>
class Stack{
    list<type> ll;
public:
    bool isEmpty(){
        return ll.size() == 0;
    }
    void push(type val){
        ll.push_front(val);
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return;
        }
        ll.pop_front();
    }
    type top(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return ll.front();
    }
};

int main(){
    Stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}