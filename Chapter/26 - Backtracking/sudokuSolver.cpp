#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void printSudoku(int sudoku[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoku[][9], int row, int col, int digit){
    // vertical
    for(int i=0;i<8;i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    // Horizontal
    for(int i=0;i<8;i++){
        if(sudoku[row][i] == digit){
            return false;
        }
    }

    // 3x3 Grid
    int startrow = (row/3)*3;
    int startrcol = (col/3)*3;
    for(int i=startrow;i<=startrow+2;i++){
        for(int j=startrcol;j<=startrcol+2;j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[][9],int row,int col){
    if(row == 9){
        // sudoku solved
        printSudoku(sudoku);
        return true;
    }

    int nxtRow = row;
    int nxtCol = col+1;
    if(col+1 == 9){
        nxtRow = row+1;
        nxtCol = 0;
    }

    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku,nxtRow,nxtCol);
    }

    for (int digit = 1; digit <= 9; digit++){
        if(isSafe(sudoku,row,col,digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku,nxtRow,nxtCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int sudoku[9][9] = {{0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},                                            
                        {0,0,3,0,0,4,1,9,0},                                            
                        {1,8,5,0,6,0,0,2,0},                                            
                        {0,0,0,0,2,0,0,6,0},                                            
                        {9,6,0,4,0,5,3,0,0},                                            
                        {0,3,0,0,7,2,0,0,4},                                            
                        {0,4,9,0,3,0,0,5,7},                                            
                        {8,2,7,0,0,9,0,1,3}};

    sudokuSolver(sudoku,0,0);
    return 0;
}