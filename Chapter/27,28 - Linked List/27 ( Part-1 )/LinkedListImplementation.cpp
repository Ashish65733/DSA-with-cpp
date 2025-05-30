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
    Node* head;
    Node* tail;
public:
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
    void insert(int val,int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout << "Position is INVALID!" << endl;
                return;
            }
            temp = temp->next;
        }
        //temp is now at pos-1 i.e. prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        if(head == NULL){
            cout << "LL is empty!" << endl;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL){ // temp->next != tail
            temp = temp->next;
        }
        temp->next = NULL; // temp = tail's pervious
        delete tail;
        tail = temp;
    }

    int searchItr(int key){
        Node* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp->data == key){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    int helper(Node *temp,int key){
        if(temp == NULL){
            return -1;
        }
        if(temp->data == key){
            return 0;
        }
        int idx = helper(temp->next,key);
        if(idx == -1){
            return -1;
        }
        return idx+1;
    }
    int searchRec(int key){
        return helper(head,key);
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        tail = head;
        while(curr != NULL){
            Node* nxt = curr->next;
            curr->next = prev;

            // Updation for next Iteration:
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }

    int llSize(){
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n){
        int size = llSize();
        Node* prev = head;

        for(int i = 1; i < (size-n); i++){
            prev = prev->next;
        }
        Node* toDel = prev->next;
        cout << "going to delete : " << toDel->data << endl;

        prev->next = prev->next->next;
    }

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    
    // cout << ll.searchRec(4) << endl;
    // ll.reverse();
    ll.removeNth(2);
    ll.printList();

    return 0;
}