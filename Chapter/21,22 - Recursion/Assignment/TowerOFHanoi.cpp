#include<iostream>
#include<climits>
#include<string>
using namespace std;

void towerOfHanoi(int n,string src, string helper, string dest){ // O(2^n)
    if (n == 1){
        cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
        return;
    }
    
    towerOfHanoi(n-1,src,dest,helper);
    cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n-1,helper,src,dest);
}

int main(){
    
    towerOfHanoi(3,"A","B","C");
    return 0;
}