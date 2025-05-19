#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortArray(vector<int>& arr){   // 0(n log n)
    sort(arr.begin(),arr.end());
}

int main(){
    vector<int> arr = {2,0,2,1,1,0,1,2,0,0};

    sortArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}