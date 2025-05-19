// Single number : 

#include<iostream>
#include<vector>
using namespace std;

int SingleNum(vector<int> vec){
    int ans = 0;
    for(int i : vec){
        ans ^= i;   // Bitwise XOR 
    }
    return ans;
}

int main(){

    vector<int> vec={1,1,2,3,3};

    int Ans = SingleNum(vec);

    cout<<"Single Number : "<<Ans<<endl;
    return 0;
}