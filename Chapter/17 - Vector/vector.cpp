#include<iostream>
#include<vector>
using namespace std;

int main(){

    // vector defination:
    vector<int> vec ;
    vector<int> vec1 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec2(3,0);  // vector<DataType> vector_name(size,value at all index);

    // For_each loop :
    cout<<"vec : ";
    for(int i: vec1){
        cout<<i<<" ";
    }
    
    cout<<endl<<"vec2 : ";
    for(int i: vec2){
        cout<<i<<" ";
    }
    cout<<endl;

    // vector function

    // int size = vec.size();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // vec.pop_back();
    // vec.front();
    // vec.back();
    // vec.at(1);

    cout<< vec.size()<<endl;
    cout<< vec.capacity()<<endl;

    return 0;
}