#include<iostream>
using namespace std;

void Intersection(int arr1[],int arr2[],int n1,int n2){
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i]==arr2[j])
            {
                cout<<arr1[i]<<" ";
            }
            
        }
        
    }
    
}

int main(){
    int n1;
    cout<<"Enter number of element of Array 1: ";
    cin>>n1;

    int arr1[n1];
    cout<<"Enter Elements : ";
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }

    int n2;
    cout<<"Enter number of element of Array 2: ";
    cin>>n2;

    int arr2[n2];
    cout<<"Enter Elements : ";
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }

    cout<<"Intersection Array : ";
    Intersection(arr1,arr2,n1,n2);

    return 0;
}