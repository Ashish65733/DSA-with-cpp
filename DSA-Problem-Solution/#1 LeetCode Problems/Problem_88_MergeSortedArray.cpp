#include <iostream>
#include <vector>
using namespace std;

void MergeSortedArr(vector<int> &A, vector<int>& B, int m, int n) // O(m+n)
{
  int i = m - 1, j = n - 1, idx = m+n-1;
  while (i >= 0 && j >= 0){
    if (A[i] < B[j]){
      A[idx--] = B[j--];
    }else{
      A[idx--] = A[i--];
    }
  }

  while (j >= 0){
    A[idx--] = B[j--];
  }
}

int main()
{
  vector<int> A = {1, 2, 3, 0, 0, 0};
  vector<int> B = {2, 5, 6};

  int m = 3;
  int n = B.size();

  MergeSortedArr(A,B,m,n);

  for (int i = 0; i < A.size(); i++)
  {
    cout<<A[i]<<" ";
  }
  
  return 0;
}