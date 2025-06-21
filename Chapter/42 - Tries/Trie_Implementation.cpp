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

    bool search(string key){   // O(L)
        Node* temp = root;

        for(char ch : key){
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }else{
                return false;
            }
        }

        return temp->endOfWord;
    }
};

int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "three"};

    Trie trie;

    for(string key : words){
        trie.insert(key);
    }

    cout << trie.search("there") << endl;   // 1
    cout << trie.search("ant") << endl; // 0

    return 0;
}