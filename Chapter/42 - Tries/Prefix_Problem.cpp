#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }

    void insert(string key){    // O(L) -> L is length of key
        Node* temp = root;

        for(char ch : key){
            if(!temp->children.count(ch)){
                temp->children[ch] = new Node();    // insert
                temp->children[ch]->freq = 1;
            }else{
                temp->children[ch]->freq++;
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    string getPrefix(string key){   // O(L)
        Node* temp = root;
        string prefix = "";

        for(char ch : key){
            prefix += ch;
            if(temp->children[ch]->freq == 1){
                break;
            }
            temp = temp->children[ch];
        }
        return prefix;
    }

};

void prefixProblem(vector<string> dict){    // O(n*L)
    Trie trie;

    for(string key : dict){
        trie.insert(key);
    }

    for(string key : dict){
        cout << trie.getPrefix(key) << endl;
    }
}

int main(){
    vector<string> dict = {"zebra", "dog", "duck", "dove"};

    prefixProblem(dict);
  
    return 0;
}