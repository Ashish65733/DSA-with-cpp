#include<iostream>
#include<climits>
#include<vector>
#include<string.h>
using namespace std;

void toUppercase(char word[],int n){
    for (int i = 0; i < n; i++){
        char ch = word[i];
        if (ch>='A' && ch<='Z'){ // character is already in uppercase
            continue;
        }else{
            word[i] = ch - 'a' + 'A';   // (ch - 'a') get the position of the character in the alphabet and add it into 'A' to get the uppercase character.
        }
    }
}

void toLowercase(char word[],int n){
    for (int i = 0; i < n; i++){
        char ch = word[i];
        if (ch>='a' && ch<='z'){ // character is already in lowercase
            continue;
        }else{
            word[i] = ch - 'A' + 'a'; // (ch - 'A') get the position of the character in the alphabet and add it into 'a' to get the lowercase character.
        }
    }
}

int main(){
    char word[] = "AsHiSh";
    int n = strlen(word);

    toUppercase(word,n);
    cout << word << endl;
    toLowercase(word,n);
    cout << word << endl;
    return 0;
}