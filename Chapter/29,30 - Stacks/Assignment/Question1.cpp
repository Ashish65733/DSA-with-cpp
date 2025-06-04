#include<iostream>
#include<climits>
#include<stack>

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

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
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


    // isPalindrome using Stack
    bool isPalindrome() {
        int size = llSize();
        stack<int> s;

        Node* temp = head;
        for (int i = 0; i < size/2; i++)
        {
            s.push(temp->data);
            temp = temp->next;
        }
        if(size % 2 != 0){
            temp = temp->next;
        }
        while(temp != NULL && !s.empty()){
            if(s.top() != temp->data){
                return false;
            }
            s.pop();
            temp = temp->next;
        }
        return true;
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

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.printList();

    cout << ll.isPalindrome() << endl;


    return 0;
}