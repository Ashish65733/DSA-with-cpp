#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

bool validAnagram(string s,string t){
    if(s.size() != t.size()){
        return false;
    }
    unordered_map<char, int> freq;

    for(char c : s){
        if(freq.count(c)){
            freq[c]++;
        }else{
            freq[c] = 1;
        }
    }

    // look for t's chars in freq
    for(char c : t){
        if(freq.count(c)){
            freq[c]--;
            if(freq[c] == 0){
                freq.erase(c);
            }
        }else{
            return false;
        }
    }

    return freq.size() == 0;
}

int main(){
    string s = "race";
    string t = "care";
    // string s = "tulip";
    // string t = "lipid";

    cout << validAnagram(s,t) << endl;
    return 0;
}