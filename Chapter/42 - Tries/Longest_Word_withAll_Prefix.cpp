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

    void longestHelper(Node* root, string &ans, string temp){
        for(pair<char, Node*> child : root->children){
            if(child.second->endOfWord){
                temp += child.first;

                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())){
                    ans = temp;
                } 

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestStrWithEOW(){
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestString(vector<string> dict){
    Trie trie;  

    for(string key : dict){
        trie.insert(key);
    }

    return trie.longestStrWithEOW();
}

int main(){
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << "Longest Word with all Prefix : " << longestString(words) << endl;

    return 0;
}