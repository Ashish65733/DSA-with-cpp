#include<iostream>
#include<climits>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};
class DoublyList{
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            head->prev = NULL;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = NULL;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "Doubly Linked List is empty!" << endl;
        }else{
            Node* temp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head == NULL){
            cout << "Doubly Linked List is empty!" << endl;
        }else{
            Node* temp = tail;
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
            temp->prev = NULL;
            delete temp;
        }
    }
};

void printList(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    DoublyList ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(5);

    printList(ll.head);
    ll.pop_front();
    ll.pop_back();
    printList(ll.head);
    return 0;
}