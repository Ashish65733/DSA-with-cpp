#include<iostream>
using namespace std;


void bubble(int arr[],int n){  // 0(n^2)

    for (int i = 0; i < n-1; i++){
        bool isSwap = false;
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }   
        } 
        if (!isSwap)
        {
            return;
        }
              
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
    
    bubble(arr,n);

    cout<<endl<<"After sorting : ";
    printArr(arr,n);

    return 0;
}