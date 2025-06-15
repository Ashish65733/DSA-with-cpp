#include<iostream>
#include<climits>

using namespace std;
// Leetcode - 938
class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

int rangeSumBST(Node* root, int low, int high){
    if(root == NULL){
        return 0;
    }

    if(low <= root->val && root->val <= high){
        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }else if(root->val < low){
        return rangeSumBST(root->right,low,high);
    }else{
        return rangeSumBST(root->left,low,high);
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    cout << "Sum in range = " << rangeSumBST(root,7,15) << endl;

    return 0;
}