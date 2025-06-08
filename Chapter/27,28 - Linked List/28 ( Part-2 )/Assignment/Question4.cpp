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
        Node* first = head;

        while(first != NULL){
            cout << first->data << " -> ";
            first = first->next;
        }
        cout << "NULL" << endl;
    }   

    Node* oddEvenList(){
        // case of LL length = 0, 1, 2
        if (head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }

        Node *evenStart = head->next;
        Node *odd = head;
        Node *even = head->next;

        while (odd->next && even->next){
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenStart;

        return head;
    }
};



int main(){
    List ll;

    ll.push_front(6);
    ll.push_front(1);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(10);
    ll.push_front(12);
    ll.push_front(8);
    ll.printList();
    
    ll.oddEvenList();
    ll.printList();

    return 0;
}


