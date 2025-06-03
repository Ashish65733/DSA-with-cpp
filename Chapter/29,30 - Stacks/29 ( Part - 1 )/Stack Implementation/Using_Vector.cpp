#include<iostream>
#include<climits>
#include<vector>
#include<string>

using namespace std;

// Create Stack using vector with templet
template<class type>
class Stack{
    vector<type> s;
public:
    bool isEmpty(){
        return s.size() == 0;
    }
    void push(type val){
        s.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return;
        }
        s.pop_back();
    }
    type top(){
        // if(isEmpty()){
        //     cout << "Stack is Empty!" << endl;
        //     return -1;
        // }
        return s[s.size()-1];
    }
    void printStack(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return ;
        }
        for(int i = s.size()-1; i>=0; i--){
            cout << s[i] << endl;
        }
    }
};

int main(){
    // Stack<int> s;
    Stack<string> s;
    s.push("Ashish");
    s.push("am");
    s.push("I");

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    
    s.printStack();
    cout << "Top = " << s.top() << endl;
    
    s.pop();
    s.pop();
    
    s.printStack();
    cout << "Top = " << s.top() << endl;
    
    s.pop();
    // s.pop();

    s.printStack();

    // while(!s.isEmpty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    return 0;
}