#include<iostream>
#include<climits>
#include<vector>
#include<string.h>
using namespace std;

void reverseCharArray(char word[],int n){
    int start = 0, end = n-1;
    while(start < end){
        swap(word[start++],word[end--]);
    }
}

int main(){
    char word[] = "Ashish";
    int n = strlen(word);

    reverseCharArray(word,n);
    cout<<word<<endl;
    return 0;
}