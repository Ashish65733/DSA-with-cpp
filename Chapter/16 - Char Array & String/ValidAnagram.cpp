#include<iostream>
#include<string>
using namespace std;

// Problem : 242
bool isValidAnagram(string str1,string str2){  // O(n+m)
    if (str1.length() != str2.length()) {
       return false;
    }
    int count[23] = {0};

    for (int i = 0; i < str1.length(); i++){
        int idx = str1[i] - 'a';
        count[idx]++;
    }

    for (int i = 0; i < str2.length(); i++){
        if (count[str2[i] - 'a'] == 0){
            return false;
        }
        count[str2[i] - 'a']--;
    }
    return true;
}

int main(){
    string str1 = "anagram";
    string str2 = "nagaram";

    if (isValidAnagram(str1,str2)){
        cout << "Valid Anagram." << endl;
    }else{
        cout << "Not Valid Anagram." << endl;
    }
    
    return 0;
}