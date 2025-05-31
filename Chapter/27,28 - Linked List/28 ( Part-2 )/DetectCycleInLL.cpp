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
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
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
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printList(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Floyd's Cycle Finding Algorithm :
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;  // +1
        fast = fast->next->next;    // +2
        if(fast == slow){
            cout << "Cycle exists." << endl;
            return true;
        }
    }
    cout << "Cycle doesn't exist." << endl;
    return false;
}

int main(){
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // printList(ll.head);
    // 1 -> 2 -> 3 -> 4 -> NULL
    
    ll.tail->next = ll.head;    // 1 -> 2 -> 3 -> 4 -> 1
    isCycle(ll.head);

    return 0;
}