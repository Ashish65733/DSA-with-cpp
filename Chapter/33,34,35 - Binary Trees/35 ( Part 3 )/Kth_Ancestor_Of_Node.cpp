#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // left subTree
    currNode->right = buildTree(nodes); // right subTree

    return currNode;
}

int KthAncestor(Node* root,int node,int k){ // O(n)
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftDist = KthAncestor(root->left,node,k);
    int rightDist = KthAncestor(root->right,node,k);

    if(leftDist == -1 && rightDist == -1){
        return -1;
    }

    int validval = leftDist == -1 ? rightDist : leftDist;

    if(validval + 1 == k){
        cout << "Kth Ancestor : " << root->data << endl;
    }
    return validval + 1;
}

int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(tree);  
    
    KthAncestor(root,4,1);
    return 0;
}