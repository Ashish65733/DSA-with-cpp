#include<iostream>
#include<climits>
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

int count(Node* root){  // O(n)
    if(root == NULL){
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

int main(){
    vector<int> tree1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root1 = buildTree(tree1);   

    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);
    root2->left->left = new Node(2);
    root2->left->right = new Node(3);
    // root2->right->left = new Node(7);
    // root2->right->right = new Node(8);


    cout << "Nodes count = " << count(root2) << endl;

    return 0;
}
