#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){    // O(L) -> L is length of key
        Node* temp = root;

        for(char ch : key){
            if(!temp->children.count(ch)){
                temp->children[ch] = new Node();    // insert
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    bool startsWith(string prefix){ // O(L)
        Node* temp = root;
        for(char ch : prefix){
            if(temp->children[ch]){
                temp = temp->children[ch];
            }else{
                return false;
            }
        }
        return true;
    }
};


int main(){
    vector<string> dict = {"apple", "app", "mango", "man", "woman"};

    Trie trie;
    
    for(string key : dict){
        trie.insert(key);
    }   

    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("many") << endl;
  
    return 0;
}