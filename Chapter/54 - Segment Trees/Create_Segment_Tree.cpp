#include<iostream>
#include<vector>

using namespace std;

class SegmentTree{
    vector<int> tree; // 4*n
    int n;
public:
    SegmentTree(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
        buildTree(arr, 0, n-1, 0);
    }

    void buildTree(vector<int> &arr, int st, int end, int node){    // O(n)
        if(st == end){
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end-st)/2;


        buildTree(arr, st, mid, 2*node+1);  // left
        buildTree(arr, mid+1, end, 2*node+2);   // right

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void printTree(){
        for(int i=0; i<tree.size(); i++){
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    // Range Sum Queries :
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    
    SegmentTree st(arr);

    st.printTree();
    
    return 0;
}