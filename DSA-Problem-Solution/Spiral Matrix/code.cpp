#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int diagonalSum(int mat[][4],int n,int m){
    int sum = 0;
    // for (int i = 0; i < n; i++)  // O(n^2)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if(i==j){  
    //             sum += mat[i][j];
    //         }else if(j == n-i-1){ 
    //             sum += mat[i][j]; 
    //         }
    //     }
        
    // }
    for (int i = 0; i < n; i++) // O(n)
    {
        sum += mat[i][i];
        if(i != n-i-1){
            sum += mat[i][n-i-1];
        }
    }
    
    return sum;
}

int main(){            //0 1 2 3
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    int matrix1[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};

    cout<< "Sum = " << diagonalSum(matrix,4,4) << endl;
    return 0;
}