#include<iostream>
#include<climits>

using namespace std;

class Stack{
    int* arr;
    int size;
    int top;
public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    ~Stack(){
        delete[] arr;
    }

    void push(int val){
        if(top == size-1){
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = val;    
    }
    void pop(){
        if(top == -1){
            cout << "Stack is Underflow!" << endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top == -1){
            cout << "Stack is Underflow!" << endl;
            return -1;
        }
        return arr[top];
    }
    void printStack(){
        for(int i = top; i>=0;i--){
            cout << arr[i] << endl;
        }
    }
};

int main(){
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.printStack();
    cout << "Top = " << s.peek() << endl;
    
    s.push(6);
    
    s.pop();
    s.pop();
    
    s.printStack();

    return 0;
}