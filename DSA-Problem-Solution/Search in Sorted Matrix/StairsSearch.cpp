#include<iostream>
#include<climits>
#include<vector>
using namespace std;
// problem : 240

// This approach is used when the all the rows and columns are sorted.
int SearchInMatrix(int mat[][4],int n,int m,int target){ // O(n + m)
    int row = n-1 , col = 0;

    while (row >= 0 && col < m){
        int cell = mat[row][col];
        if (cell == target){
            cout << "Target found at index (" << row << "," << col << ")" << endl;
            return 1;
        }else if(cell < target){
            col++;
        }else{
            row--;
        }   
    }
    cout << " Target Not found! " << endl;
    return -1;   
}

int main(){
    int matrix[4][4] = {{10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}};

    cout <<SearchInMatrix(matrix,4,4,3) << endl;
    return 0;
}