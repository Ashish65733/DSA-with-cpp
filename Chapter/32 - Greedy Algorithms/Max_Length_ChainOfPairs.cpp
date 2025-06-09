#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;   // ascending
}

int maxChainLength(vector<pair<int,int>> pairs){
    sort(pairs.begin(),pairs.end(),compare);

    int maxLength = 1;
    int currEnd = pairs[0].second;

    for(int i=1; i<pairs.size(); i++){
        if(pairs[i].first >= currEnd){  // non-Overlapping
            maxLength++;
            currEnd = pairs[i].second;
        }
    }

    return maxLength;
}

int main(){
    int n = 5;
    vector<pair<int,int>> pairs(n,make_pair(0,0));

    pairs[0] = make_pair(2,24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    cout << "Maximum Chain Length = " << maxChainLength(pairs) << endl;

    return 0;
}