#include<iostream>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

int maxAreaInHistogram(vector<int> &Height){    // O(n)
    int n = Height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    // next smaller left
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<Height.size(); i++){
        int curr = Height[i];
        while(!s.empty() && curr <= Height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    // next smaller right
    s.push(n-1);
    nsr[n-1] = n;
    for(int i=n-2; i>=0; i--){
        int curr = Height[i];
        while(!s.empty() && curr <= Height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = INT_MIN;
    for(int i=0; i<n; i++){
        int h = Height[i];
        int w = nsr[i] - nsl[i] - 1;
        int area = h * w;

        maxArea = max(area,maxArea);
    }
    return maxArea;
}

int main(){
    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout << "Max Area in Histogram = " << maxAreaInHistogram(height) << endl;
    return 0;
}