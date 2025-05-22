#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void merge(vector<int> &arr,int si,int ei,int mid){ // O(n)
    int i = si;
    int j = mid+1;

    vector<int> temp;

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
         temp.push_back(arr[j++]);
    }
    // Copy temp vector -> Original Array
    for (int i = si, x = 0; i <= ei; i++){
        arr[i] = temp[x++];
    }
}

void mergeSort(vector<int> &arr,int si,int ei){ // O(n * log n)
    if(si >= ei){
        return;
    }
    
    int mid = si + (ei-si)/2;

    // Divide :
    mergeSort(arr,si,mid);      //Left Half
    mergeSort(arr,mid+1,ei);    //Right Half
    // Conquer :
    merge(arr,si,ei,mid);
}

void printVector(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> vec = {6,5,4,3,2,1};
    cout << "Before Sorting : ";
    printVector(vec);
    mergeSort(vec,0,vec.size()-1);
    cout << "After Sorting : ";
    printVector(vec);

    return 0;
}