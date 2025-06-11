#include<iostream>
#include<climits>
#include<vector>

using namespace std;

// Diameter of a Tree is No. of nodes in the longest path between 2 leaves0

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

int height(Node* root){ // O(n)
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currHeight = max(leftHeight,rightHeight) + 1;

    return currHeight;
}

int diameter(Node* root){   // O(n^2)
    if(root == NULL){
        return 0;
    }
    
    int currDiam = height(root->left) + height(root->right) + 1;    // O(n)

    int leftDiam = diameter(root->left);
    int rightDiam = diameter(root->right);

    return max(leftDiam,max(rightDiam,currDiam));
}

int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(tree);  
    
    cout << "Diameter of Tree = " << diameter(root) << endl;

    return 0;
}