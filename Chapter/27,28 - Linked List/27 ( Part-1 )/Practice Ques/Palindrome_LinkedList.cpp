#include<iostream>
#include<climits>
#include<vector>

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

    // bool isPalindrome() {
    //     int size = llSize();
    //     vector<int> half;
    //     Node* temp = head;

    //     // Store the first half
    //     for (int i = 0; i < size / 2; i++) {
    //         half.push_back(temp->data);
    //         temp = temp->next;
    //     }

    //     // Skip the middle node for odd size
    //     if (size % 2 != 0) {
    //         temp = temp->next;
    //     }

    //     // Compare the second half with the reversed first half
    //     for (int i = half.size() - 1; i >= 0; i--) {
    //         if (temp->data != half[i]) return false;
    //         temp = temp->next;
    //     }

    //     return true;
    // }

    // Optimized in space complexity
    bool isPalindrome() {
        if (!head || !head->next) return true;

        // Step 1: Find the middle (slow will point to middle)
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        Node* prev = nullptr;
        while (slow) {
            Node* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Step 3: Compare both halves
        Node* first = head;
        Node* second = prev;  // Head of reversed second half
        while (second) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
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
    ll.push_back(2);
    ll.push_back(1);
    ll.printList();

    cout << ll.isPalindrome() << endl;


    return 0;
}