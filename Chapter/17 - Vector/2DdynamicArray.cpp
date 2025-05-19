#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows:";
    cin >> rows;
    cout << "Enter number of cols:";
    cin >> cols;

    int* *matrix = new int*[rows]; // pointer array of pointers

    // allocating memory 
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // individual array in the pointer array
    }

    // filling the matrix
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = 0;
        }
    }


    int x = 1;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // matrix[i][j] = *(*(matrix + i) + j)
    return 0;
}