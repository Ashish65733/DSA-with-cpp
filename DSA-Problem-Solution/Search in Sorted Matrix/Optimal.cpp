#include<iostream>
#include<climits>
#include<vector>
using namespace std;
// problem : 74

// This approach is used when either the row or column id sorted.
// When the row is sorted, traversing the columns and performing binary search on the rows one by one.
// When the column is sorted, traversing the rows and performing binary seatch on the columns one by one.

int SearchInMatrix(int mat[][4],int n,int m,int target){ // O(n * log m)
    for (int i = 0; i < n; i++){
        int st = 0,end = m-1;
        while (st<=end){
            int mid = st + (end-st)/2;
            if (mat[i][mid] == target){
                cout << "Target found at index (" << i << "," << mid << ")" << endl;
                return 1;
            }else if(mat[i][mid] > target){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
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

    cout << SearchInMatrix(matrix,4,4,35) << endl;
    return 0;
}