#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    //Horizontal --> we're placing one queen in each row so no need to check in horizontal
    // for (int j = 0; j < n; j++){
    //     if(board[row][j] == 'Q'){
    //         return false;
    //     }
    // }
    //Vertical
    for (int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    //Diagonal left
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    //Diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>> board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return 1;
    }
    
    int count = 0;
    for (int j = 0; j < n; j++){
        if (isSafe(board,row,j)){
            board[row][j] = 'Q';
            count += nQueens(board,row+1);
            board[row][j] = '.';
        }
    }
    return count;
}

int main(){
    vector<vector<char>> board;
    int n = 4;

    for (int i = 0; i < n; i++){
        vector<char> newRow;
        for (int j = 0; j < n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count = nQueens(board,0);

    cout << "Count = " << count << endl;
    return 0;
}