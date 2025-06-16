#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, currGas = 0, start = 0;

    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i] - cost[i];
        currGas += gas[i] - cost[i];

        if (currGas < 0) {
            start = i + 1;   
            currGas = 0;     
        }
    }

    return (totalGas >= 0) ? start : -1;
}

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << "Starting point to complete circuit = " << canCompleteCircuit(gas,cost) << endl;

    return 0;
}