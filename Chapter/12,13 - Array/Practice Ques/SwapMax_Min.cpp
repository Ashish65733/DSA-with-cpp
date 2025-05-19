#include<iostream>
#include<climits>
using namespace std;

void SwapMaxMin(int arr[],int n){
    int largInx = 0;
    int smallInx = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[largInx]<arr[i])
        {
            largInx = i;
        }
        if (arr[smallInx]>arr[i])
        {
            smallInx = i;
        }
    
    }
    
    swap(arr[largInx],arr[smallInx]);
}
int main(){
    int n;
    cout<<"Enter number of element : ";
    cin>>n;

    int arr[n];

    cout<<"Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Array before swaping : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    SwapMaxMin(arr,n);
    
    cout<<endl<<"Array after swaping : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}