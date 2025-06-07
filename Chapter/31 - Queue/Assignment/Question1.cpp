#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Leetcode - 2073 : Time Needed to Buy Tickets

int timeRequiredToBuy(vector<int> &tickets, int k){
    queue<int> q;
    for(int i = 0; i<tickets.size(); i++){
        q.push(i);
    }

    int time = 0;

    while(true){
        int first = q.front();
        q.pop();
        tickets[first]--;
        time++;

        if(tickets[first] != 0){
            q.push(first);
        }

        if(first == k && tickets[k] == 0){
            break;
        }
    }
    return time;
}

int main(){
    vector<int> tickets = {2,3,2};
    int k = 2;

    cout << "Time taken : " << timeRequiredToBuy(tickets,k) << endl;
    return 0;
}