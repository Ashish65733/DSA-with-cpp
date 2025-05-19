#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main(){
    
    int n;
    cout <<"Enter size of array : ";
    cin >> n;
    int *arr = new int[n];

    cout <<"Enter elements of array : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout <<"Elements of array are : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;

    return 0;
}