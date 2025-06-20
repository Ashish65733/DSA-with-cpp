#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int countDistinct(vector<int> arr){
    unordered_set<int> s;   // set stores unique elements

    for(int num : arr){
        s.insert(num);
    }

    for(int el : s){
        cout << el << " ";
    }
    cout << endl;

    return s.size();
}

int main(){
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << "Count = " << countDistinct(arr) << endl;

    return 0;
}