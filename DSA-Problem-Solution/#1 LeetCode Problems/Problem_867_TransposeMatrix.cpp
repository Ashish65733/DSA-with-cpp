#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void printMat(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> result(m,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    vector<vector<int>> result = transpose(matrix);

    printMat(result);

    return 0;
}