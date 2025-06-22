#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// Given an array of strings, group the anagrams together. You can return the answer in any order.
// solved using sorting + Hashing



vector<vector<string>> groupAnagrams(vector<string> dict){
    unordered_map<string, vector<string>> m;    // <sorted str, related anagram vector>

    for(string str : dict){
        string sortedStr = str;
        sort(sortedStr.begin(),sortedStr.end());    // step 1
        m[sortedStr].push_back(str);    // step 2
    }

    vector<vector<string>> result;

    for(pair<string, vector<string>> p : m){
        result.push_back(p.second);
    }
    return result;
}

int main(){
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(words);

    for(vector<string> v : result){
        cout << "{ "; 
        for(string s : v){
           cout << s << " ";
        }
        cout << "}\n";
    }

    return 0;
}