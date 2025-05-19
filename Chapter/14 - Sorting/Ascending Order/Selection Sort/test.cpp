#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n){    // O(n^2)

    for (int i = 0; i < n-1; i++)
    {
        int smllestIdx = i; // unsorted part starting
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[smllestIdx])
            {
                smllestIdx = j;
            }
        }
        swap(arr[i],arr[smllestIdx]);
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
    
    SelectionSort(arr,n);

    cout<< endl <<"After sorting : ";
    printArr(arr,n);

    return 0;
}