#include<iostream>
#include<unordered_map>
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

    int countHelper(Node* root){
        int ans = 0;

        for(pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }

        return ans + 1;
    }

    int countNodes(){
        return countHelper(root);
    }
    
};

int countUniqueSubstr(string str){
    Trie trie;

    for(int i=0; i<str.size(); i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main(){
    // string str = "ababa";
    string str = "abc";

    cout << "Count of Unique Substrings = " << countUniqueSubstr(str) << endl;
  
    return 0;
}