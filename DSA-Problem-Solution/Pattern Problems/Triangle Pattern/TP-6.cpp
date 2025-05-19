#include<iostream>
using namespace std;

int main(){
    int n; 

    cout<<"Enter number of line : ";
    cin>>n;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<num;
            num += 1;
        }
        cout<<endl;
    }
    
    return 0;
}