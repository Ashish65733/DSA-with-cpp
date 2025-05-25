#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Stairs Search
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;
    
    int n = matrix.size();
    int m = matrix[0].size();
    int row = n-1 , col = 0;

    while (row >= 0 && col < m){
        int cell = matrix[row][col];
        if (cell == target){
            return true;
        }else if(cell < target){
            col++;
        }else{
            row--;
        }   
    }
    return false;  
}
int main(){
    vector<vector<int>> matrix = {{10,20,30,40},
                                  {15,25,35,45},
                                  {27,29,37,48},
                                  {32,33,39,50}};

    if(searchMatrix(matrix,35)){
        cout << "Target Found!" << endl;
    }else{
        cout << "Target Not Found!" << endl;
    }
    return 0;
}