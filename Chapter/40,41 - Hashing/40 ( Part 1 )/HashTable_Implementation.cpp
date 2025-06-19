#include<iostream>
#include<string>

using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key,int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;

        for(int i=0; i<key.size(); i++){
            idx = idx + (key[i] * key[i]) % totSize;
        }
        return idx%totSize;
    }

    void rehash(){  // O(n)
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }

        // Copy old values
        for(int i=0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key,temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size=5){
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key,int val){    // avg case : O(1), worst case : O(n) 
        int idx = hashFunction(key);

        Node* newNode = new Node(key,val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lamdba = currSize/(double)totSize;
        if(lamdba > 1){
            rehash();   // O(n) - worst case of insertion
        }
    }

    bool exist(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){   // FOUND
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){   // FOUND
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void erase(string key){
        int idx = hashFunction(key);

        Node *temp = table[idx];
        Node* prev = temp;

        while(temp != NULL){
            if(temp->key == key){   // erase
                if(prev == temp){   // head
                    table[idx] = temp->next;
                }else{
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp= temp->next;
        }
    }

    void print(){
        for(int i=0; i<totSize; i++){
            cout << "Idx : " << i << " -> ";
            Node* temp = table[i];
            while(temp != NULL){
                cout << "(" << temp->key << "," << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main(){
    HashTable ht;

    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    // if(ht.exist("India")){
    //     cout << "India population : " << ht.search("India") << endl;
    // }

    ht.erase("China");
    ht.print();

    cout << "------------------" << endl;

    ht.erase("UK");
    ht.print();

    return 0;
}