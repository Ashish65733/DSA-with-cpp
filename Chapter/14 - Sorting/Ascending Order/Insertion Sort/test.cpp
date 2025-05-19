#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n){    // O(n^2)

    for (int i = 1; i < n-1; i++)
    {
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        
        arr[prev+1] = curr; // placing the curr el in its correct position
        
    }
}

void printArr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
}

int main(){
    int n = 5;
    int arr[5] = {2,4,3,1,5};

    cout<<"Brfore sorting : ";
    printArr(arr,n);
    
    InsertionSort(arr,n);

    cout<<endl<<"After sorting : ";
    printArr(arr,n);

    return 0;
}