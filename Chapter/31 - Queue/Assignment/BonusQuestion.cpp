#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
// Leetcode 146 : LRU Cache

class LRUCache {
public:

    class Node{
        public:
            int key, val;
            Node* prev;
            Node* next;

            Node(int k, int v){
                key = k; 
                val = v;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode){    //O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode){    //O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {  // O(1)
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {  // O(1)
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if(m.size() == limit){
            // delete LRU data
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }

    void printList(){
        Node* temp = head;
        
        while(temp != NULL){
            cout << temp->key << " , " << temp->val << " <=> ";
            temp = temp->next;
        }
        
    }
};


int main(){
    LRUCache lc(2);

    lc.put(1,1);
    lc.put(2,2);
    lc.get(1);
    lc.put(3,3);
    lc.get(2);
    lc.put(4,4);
    lc.get(1);
    lc.get(3);
    lc.get(4);

    lc.printList();

    return 0;
}