#include<iostream>
#include<unordered_Set>
#include<vector>

using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    for(int num : arr1){
        s.insert(num);
    }
    for(int num : arr2){
        s.insert(num);
    }

    // print elements : 
    cout << "Union : ";
    for(int el : s){
        cout << el << " ";
    }
    cout << endl;
}

void printIntersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    for(int num : arr1){
        s.insert(num);
    }

    cout << "Intersection : ";
    for(int num: arr2){
        if(s.find(num) != s.end()){ // FOUND
            cout << num << " ";
            s.erase(num);
        }
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};

    printUnion(arr1,arr2);
    printIntersection(arr1,arr2);

    return 0;
}