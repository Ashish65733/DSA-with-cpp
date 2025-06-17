#include<iostream>
#include<vector>

using namespace std;

void heapify(int i, vector<int> &arr,int n){    // O(log n)
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && arr[left] > arr[maxI]){ //  >  - for descending order
        maxI = left;
    }
    if(right < n && arr[right] > arr[maxI]){    // > 
        maxI = right;
    }

    if(maxI != i){
        swap(arr[i],arr[maxI]);
        heapify(maxI,arr,n);
    }
}

void heapSort(vector<int> &arr){    // O(n*log n)
    int n = arr.size();

    // Step : 1
    for(int i=n/2-1; i>=0; i--){
        heapify(i, arr, n);
    }

    // Step : 2
    for(int i=n-1; i>=0; i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}

int main(){
    vector<int> arr = {1, 4, 2, 5, 3};

    heapSort(arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}