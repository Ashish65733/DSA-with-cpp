#include<iostream>
#include<stack>
#include<queue>

using namespace std;

// Reversing the first k elements of a queue :

void reverseKel(queue<int> &q,int k){
    int n = q.size();
    stack<int> s;
    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<(n-k); i++){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    reverseKel(q,k);

    int n = q.size();

    for(int i=0; i<n; i++){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}