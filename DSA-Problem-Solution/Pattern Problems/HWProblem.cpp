#include<iostream>
using namespace std;

int main(){
    int n; 

    cout<<"Enter number of line : ";
    cin>>n;

    // Upper part
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++) // Star
        {
            cout<<"* ";
        }

        for (int j = 0; j < 2*(n-i) ; j++) // Space
        {
            cout<<"  ";
        }

        for (int j = 1; j <= i; j++) // Star
        {
            cout<<"* ";
        }
        cout<<endl;  
    }
    
    // Lower Part
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i+1; j++) // Star
        {
            cout<<"* ";
        }

        for (int j = 0; j < 2*i-2 ; j++) // Space
        {
            cout<<"  ";
        }

        for (int j = 1; j <= n-i+1; j++) // Star
        {
            cout<<"* ";
        }
        cout<<endl;  
    }
    
    return 0;
}