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

Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* dltNode(Node* root,int val){
    if(root == NULL){
        return root;
    }

    if(val < root->data){
        root->left = dltNode(root->left,val);
    }else if(val > root->data){
        root->right = dltNode(root->right,val);
    }else{  // val == root->data
        // case 1: 0 child  -> Leaf Node
        if(root->left == NULL && root->right == NULL){  
            delete root;
            return NULL;
        }

        // case 2: 1 child
        if(root->left == NULL || root->right == NULL){ 
            return root->left == NULL ? root->right : root->left;
        }

        // case 3: 2 child
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right =  dltNode(root->right,IS->data);
        return root;
    }
    return root;
}

int main(){
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = 9;

    Node* root = buildBST(arr,n);
    inorder(root);
    cout << endl;
    
    // dltNode(root,4);
    // dltNode(root,10);
    dltNode(root,5);
    
    inorder(root);
    cout << endl;

    return 0;
}