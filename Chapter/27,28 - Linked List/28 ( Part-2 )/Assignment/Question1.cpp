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
    // ~Node(){
    //     if(next != NULL){
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List{
public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }
    // ~List(){
    //     if(head != NULL){
    //         delete head;
    //         head = NULL;
    //     }
    // }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
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

};
int llSize(Node* head){
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
    }
void intersect(Node* &head1,Node* &head2, int pos){
    Node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersectPoint(Node* head1,Node* head2){
    int len1 = llSize(head1);
    int len2 = llSize(head2);

    int d = 0;
    Node* ptr1 ;
    Node* ptr2 ;
    if(len1 > len2){
        d = len1 - len2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = len2 - len1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;

        if(ptr1 == NULL){
            return -1;
        }

        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main(){
    List ll1;
    List ll2;

    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.push_back(6);
    ll1.push_back(7);

    ll2.push_back(4);
    ll2.push_back(5);

    intersect(ll1.head,ll2.head,4);

    cout << "Intersection at Node : " << intersectPoint(ll1.head,ll2.head) << endl;

    return 0;
}