#include<iostream>
#include<climits>
#include<vector>
#include<string.h>
using namespace std;
// Problem : 125
bool isPalindrome(char word[],int n){
    int st = 0, end = n-1;
    while (st < end)
    {
        if (word[st] != word[end]){
            return false;
        }
        st++;
        end--;
    }
    return true;
}


int main(){
    char word[] = "racecar";
    int n = strlen(word);
    cout<<isPalindrome(word,n)<< endl;

    return 0;
}