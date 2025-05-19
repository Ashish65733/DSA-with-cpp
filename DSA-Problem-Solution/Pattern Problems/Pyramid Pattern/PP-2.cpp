#include<iostream>
using namespace std;

int main(){
    int n; 

    cout<<"Enter number of line : ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++) // Space
        {
            cout<<" ";
        }

        for (int j = 1; j <= (2*(i+1)-1); j++) // Star
        {
            cout<<"*";
        }

        // For Star
        // for (int j = 1; j <= i+1; j++)
        // {
        //     cout<<"*";
        // }

        // for (int j = i; j >= 1; j--)
        // {
        //     cout<<"*";
        // }
        

        cout<<endl;  
    }
    
    return 0;
}