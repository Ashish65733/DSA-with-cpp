#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};



Node* buildBSTSortedArray(vector<int> arr,int st,int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* currNode = new Node(arr[mid]);
    currNode->left = buildBSTSortedArray(arr,st,mid-1);
    currNode->right = buildBSTSortedArray(arr,mid+1,end);

    return currNode;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void getInorder(Node* root,vector<int> &ans){
    if(root == NULL){
        return ;
    }

    getInorder(root->left,ans);
    ans.push_back(root->data);
    getInorder(root->right,ans);
}

Node* balancedBST(Node* root){
    vector<int> inorder ;
    getInorder(root,inorder);

    return  buildBSTSortedArray(inorder,0,inorder.size()-1);
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(5); 
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    

    preorder(root);
    cout << endl;
    
    Node* root2 = balancedBST(root);
    
    preorder(root2);
    cout << endl;

    return 0;
}