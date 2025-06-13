#include<iostream>
#include<climits>

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

void printInRange(Node* root,int start,int end){
    if(root == NULL){
        return;
    }

    if(start <= root->data && root->data <= end){
        printInRange(root->left,start,end);
        cout << root->data << " ";
        printInRange(root->right,start,end);
    }else if(start > root->data){
        printInRange(root->right,start,end);
    }else{
        printInRange(root->left,start,end);
    }
}

int main(){
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = 9;

    Node* root = buildBST(arr,n);
    inorder(root);
    cout << endl;

    printInRange(root,4,10);
    cout << endl;

    return 0;
}