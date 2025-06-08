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

    void swapNodes(int x, int y){
        if (x == y) return;

        // Make sure x < y
        if (x > y) swap(x, y);

        Node *prevX = NULL, *currX = head;
        for (int i = 1; currX != NULL && i < x; i++) {
            prevX = currX;
            currX = currX->next;
        }

        Node *prevY = NULL, *currY = head;
        for (int i = 1; currY != NULL && i < y; i++) {
            prevY = currY;
            currY = currY->next;
        }

        if (currX == NULL || currY == NULL) return;

        if (prevX != NULL)
            prevX->next = currY;
        else
            head = currY;

        if (prevY != NULL)
            prevY->next = currX;
        else
            head = currX;

        Node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
    }

};



int main(){
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    
    ll.swapNodes(2,4);
    ll.printList();

    return 0;
}