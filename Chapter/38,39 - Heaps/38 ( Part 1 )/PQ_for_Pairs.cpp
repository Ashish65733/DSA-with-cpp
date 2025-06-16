#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct ComparePair{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second;
    }
};


int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,ComparePair> pq;    // Default - maxHeap: "first"

    pq.push(make_pair("aman",85));
    pq.push(make_pair("bhumika",95));
    pq.push(make_pair("chetan",65));

    while(!pq.empty()){
        cout << "Top = " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}