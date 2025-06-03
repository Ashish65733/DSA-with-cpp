#include<iostream>
#include<climits>
#include<string>
#include<list>

using namespace std;

// Create Stack using vector with templet without STL
template<class type>
class Node{
public:
    type data;
    Node* next;
    Node(type val){
        data = val;
        next = NULL;
    }
};

template<class type>
class Stack{
    Node<type>* head;
public:
    Stack(){
        head = NULL;
    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }else{
            return false;
        }
    }
    void push(type val){
        // Push front
        Node<type>* newNode = new Node<type>(val);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void pop(){
        // POP front
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node<type>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    type top(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
        }else{
            return head->data;
        } 
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