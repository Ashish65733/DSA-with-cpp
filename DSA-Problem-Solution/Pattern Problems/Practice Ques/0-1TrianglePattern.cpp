#include <iostream>
using namespace std;

int main(){

    int n = 5;
    int p ;

    for(int i=1; i<=n; i++){
        (i % 2 == 0) ?  p = 0 :  p = 1;
        for(int j=1; j<=i; j++){
            cout << p;
            (p == 1) ? p = 0 : p = 1 ;
        }
        cout << endl;
    }


    //0-1TrianglePattern
    // bool val=true;
    // int n=5;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<val<<"";
    //         val=!val;
    //     }
    //     cout<<"\n";
    // }
    return 0;
}