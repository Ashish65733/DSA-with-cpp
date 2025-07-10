#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class SegmentTree{
    vector<int> tree;
    int n;

    void buildTree(vector<int> &nums,int st, int end, int node){
        if(st == end){
            tree[node] = nums[st];
            return;
        }

        int mid = st + (end-st)/2;

        buildTree(nums, st, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);

        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }

    int minQuery(int qi, int qj, int si, int sj, int node){
        if(qi > sj || qj < si){ // no overlap
            return INT_MAX;
        }

        if(si >= qi && sj <= qj){   // complete overlap
            return tree[node];
        }

        // partial
        int mid = si + (sj-si)/2;

        return min(minQuery(qi, qj, si, mid, 2*node+1), minQuery(qi, qj, mid+1, sj, 2*node+2));

    }

    void updateUtil(int idx, int val, int st, int end, int node){
        if(st == end){
            tree[node] = val;
            return;
        }

        int mid = st + (end-st)/2;

        if(idx >= st && idx <= mid){
            updateUtil(idx, val, st, mid, 2*node+1);
        }else{
            updateUtil(idx, val, mid+1, end, 2*node+2);
        }

        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

public:
    SegmentTree(vector<int> nums){
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums,0,n-1,0);
    }

    void printST(){
        for(int el : tree){
            cout << el << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj){
        return minQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int val){
        updateUtil(idx, val, 0, n-1, 0);
    }

};

int main(){
    // Range Min Queries:
    vector<int> nums = {16, 8, 11, 2, 17, 10, 3, 22, 4}; 

    SegmentTree st(nums);

    st.printST(); 
    
    cout << st.rangeQuery(2,5) << endl;
    
    st.updateQuery(3, 5);

    cout << st.rangeQuery(2,5) << endl;

    return 0;
}