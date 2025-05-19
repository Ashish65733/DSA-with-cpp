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

void Transpose(int mat[][3],int n,int m){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < m; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}


int main(){
    int matrix[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};
    cout << "Matrix : " << endl;
    printMat(matrix,3,3);
    Transpose(matrix,3,3);
    cout << "Transpose of Matrix : "<< endl ;
    printMat(matrix,3,3);
    return 0;
}