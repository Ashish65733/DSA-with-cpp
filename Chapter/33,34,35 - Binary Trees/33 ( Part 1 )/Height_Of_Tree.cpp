#include<iostream>
#include<climits>
#include<vector>

using namespace std;

// Height of tree is Max Distance from root to leaf.

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

int main(){
    vector<int> tree1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> tree2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};

    // Node* root = buildTree(tree1);   // Height = 3
    Node* root = buildTree(tree2);  // Height = 5

    cout << "Height of tree = " << height(root) << endl;

    return 0;
}
