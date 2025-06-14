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


Node* mergeBSTs(Node* root1,Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> mergeNodes;

    getInorder(root1,nodes1);
    getInorder(root2,nodes2);

    int i=0, j=0;
    while(i < nodes1.size() && j < nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            mergeNodes.push_back(nodes1[i++]);
        }else{
            mergeNodes.push_back(nodes2[j++]);
        }
    }
    while(i < nodes1.size()){
        mergeNodes.push_back(nodes1[i++]);
    }
    while(j < nodes2.size()){
        mergeNodes.push_back(nodes2[j++]);
    }

    return buildBSTSortedArray(mergeNodes,0,mergeNodes.size()-1);
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBSTs(root1,root2);

    preorder(root);
    cout << endl;

    return 0;
}