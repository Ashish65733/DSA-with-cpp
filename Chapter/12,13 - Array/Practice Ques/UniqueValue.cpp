#include<iostream>
using namespace std;

void UniqueValue(int arr[],int n){
    cout<<"Unique Values : ";
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (j==i)
            {
               continue;
            }
            if (arr[i]==arr[j])
            {
                count++;
            }
        }
        if (count==0)
        {
            cout<<arr[i]<<" ";
        }    
    }
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

    UniqueValue(arr,n);
    return 0;
}