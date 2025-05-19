#include<iostream>
#include<climits>
using namespace std;


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

    int largest = arr[0];
    int smallest = arr[0];
    int largInx = 0;
    int smallInx = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[largInx]<arr[i])
        {
            largest = arr[i];
            largInx = i;
        }
        if (arr[smallInx]>arr[i])
        {
            smallest = arr[i];
            smallInx = i;
        }
    
    }

    // int mini = INT_MAX;
    // int maxi = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     mini = min(mini,arr[i]);
    //     maxi = max(maxi,arr[i]);
    // }

    cout<<"The Maximum number is : "<<largest<<" at Index "<<largInx<<endl;
    cout<<"The Minimum number is : "<<smallest<<" at Index "<<smallInx<<endl;


    return 0;
}