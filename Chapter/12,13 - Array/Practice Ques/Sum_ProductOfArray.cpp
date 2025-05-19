#include<iostream>
using namespace std;

int sum(int arr[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int product(int arr[],int n){
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
    }
    return product;
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

    int ArrSum = sum(arr,n);
    int ArrProd = product(arr,n);

    cout<<"The Sum of all numbers in Array : "<<ArrSum<<endl;
    cout<<"The Product of all numbers in Array : "<<ArrProd<<endl;


    return 0;
}