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

Node* buildBSTSortedArray(int arr[],int st,int end){
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

int main(){
    int arr[7] = {3,4,5,6,7,8,9};    

    Node* root = buildBSTSortedArray(arr,0,6);

    preorder(root);

    return 0;
}