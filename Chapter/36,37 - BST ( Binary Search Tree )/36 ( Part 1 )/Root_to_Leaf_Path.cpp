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

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* insert(Node* root,int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }

    return root;
}

Node* buildBST(int arr[],int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root,arr[i]);
    }

    return root;
}

void printPath(vector<int> path){
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node* root,vector<int> &path){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left,path);
    pathHelper(root->right,path);
    path.pop_back();
}

void rootToLeafPath(Node* root){
    vector<int> path;
    pathHelper(root,path);
}

int main(){
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = 9;

    Node* root = buildBST(arr,n);
    inorder(root);
    cout << endl;

    
    rootToLeafPath(root);

    return 0;
}