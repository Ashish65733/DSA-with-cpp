#include<iostream>

using namespace std;

// Queue implementation using Linked List :

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(empty()){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = NULL;
        }
    }
    void pop(){
        if(empty()){
            cout << "Queue is Underflow!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    int front(){
        if(empty()){
            cout << "Queue is Underflow!" << endl;
            return -1;
        }
        return head->data;
    }
    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}