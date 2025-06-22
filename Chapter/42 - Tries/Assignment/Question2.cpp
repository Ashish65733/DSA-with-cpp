#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    string word;    // store word at end for direct access

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
        root->endOfWord = true; // root = "" (valid prefix) base case
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
        temp->word = key;   // store word at end
    }

    void DFS(Node* temp, string &ans){
        if(!temp->endOfWord) return;

        if(temp != root){
            string curr = temp->word;
            if(curr.size() > ans.size() || (curr.size() == ans.size()) && curr < ans){
                ans = curr;
            }
        }

        for(auto pair : temp->children){
            DFS(pair.second,ans);
        }
    }

    string LongestWord(){
        string ans = "";
        DFS(root,ans);
        return ans;
    }
};

int main(){
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    Trie trie;
    
    for(string key : words){
        trie.insert(key);
    }

    cout << "Longest word in dictionary : " << trie.LongestWord() << endl;

    return 0;
}