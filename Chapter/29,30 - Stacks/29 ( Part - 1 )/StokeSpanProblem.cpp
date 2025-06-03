#include<iostream>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

void stockSpanProblem(vector<int> stock, vector<int> span){
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i = 1; i<stock.size(); i++){
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }

        if(s.empty()){
            span[i] = i + 1;
        }else{
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
    }

    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> stock = {100,80,60,70,60,85,100};
    vector<int> span = {0,0,0,0,0,0,0};

    stockSpanProblem(stock,span);
    return 0;
}