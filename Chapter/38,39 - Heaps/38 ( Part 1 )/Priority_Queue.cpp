#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq;

    pq.push(5);
    pq.push(10);
    pq.push(7);
    pq.push(9);
    pq.push(2);

    while(!pq.empty()){
        cout << "Top = " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}