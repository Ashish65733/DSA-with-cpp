#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(3);

    s.insert(1);    // Duplicate
    s.insert(1);
    s.insert(1);

    cout << "Size of the set is: " << s.size() << endl;

    // s.erase(3);
    // if(s.find(3) != s.end()){
    //     cout << "3 exist" << endl;
    // }else{
    //     cout << "3 doesn't exist" << endl;
    // }

    for(auto el : s){
        cout << el << " ";
    }
    cout << endl;
    
    return 0;
}