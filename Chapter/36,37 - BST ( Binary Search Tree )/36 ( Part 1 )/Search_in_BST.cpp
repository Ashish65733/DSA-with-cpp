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

bool search(Node* root,int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }else if(key < root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

int main(){
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = 9;

    Node* root = buildBST(arr,n);
    inorder(root);
    cout << endl;

    cout << search(root,10) << endl;

    return 0;
}