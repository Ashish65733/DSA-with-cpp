#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void printMat(int mat[][3],int n,int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Rotate(int mat[][3],int n,int m){
    // For Transpose :
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < m; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    // For Reverse all rows :
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < m/2; j++){
            swap(mat[i][j],mat[i][m-j-1]);
        }
    } 
    // After completing these two processes, we will have the final result(Rotate 90 degree).
}

int main(){
    int matrix[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}}; 
    cout << "Initialy Matrix :" <<endl;
    printMat(matrix,3,3);

    Rotate(matrix,3,3);

    cout << "Matrix after Rotation :" <<endl;
    printMat(matrix,3,3);
    return 0;
}