#include<iostream>
#include<climits>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void removeNnodes(int n, int m){
        Node* current = head;
        Node* prev = NULL;
        
        for (int i = 0; i < m && current != NULL; i++) {    // Skip m nodes
            prev = current;
            current = current->next;
        }
       
        for (int i = 0; i < n && current != NULL; i++) {     // Delete n nodes
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        // Connect last retained node to the remaining list
        if (prev != NULL) {
            prev->next = current;
        } else {
            head = current;  // head is deleted
        }
    }
    
};

int main(){
    List ll;

    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    
    ll.removeNnodes(2,2);
    ll.printList();

    return 0;
}