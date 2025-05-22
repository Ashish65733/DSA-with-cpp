#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int si,int ei){
    int pivot = arr[ei];
    int i = si-1;

    for (int j = si; j < ei; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    // Setting pivot to it's correct position 
    i++;
    swap(arr[i],arr[ei]);
    // PivotIdx = i
    return i;
}

void QuickSort(vector<int> &arr,int si,int ei){ // O(n * log n) ,  # in worst case O(n^2) : This Complexity occurs when repeatedly the smallest of the largest element of the array becomes the pivot.
    if(si >= ei){
        return;
    }

    int pivotIdx = partition(arr,si,ei);

    QuickSort(arr,si,pivotIdx-1);
    QuickSort(arr,pivotIdx+1,ei);
}

void printVector(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> arr = {3,7,2,6,5,4}; // In this example and in every average case Complaxity is : O(n * log n)
    vector<int> vec = {6,5,4,3,2,1}; // In this example the array is sorted in descending order so Complexity is : O(n^2) 

    cout << "Before Sorting : ";
    printVector(vec);

    QuickSort(vec,0,vec.size()-1);
    
    cout << "After Sorting : ";
    printVector(vec);

    return 0;
}