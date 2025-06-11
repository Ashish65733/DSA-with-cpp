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



pair<int,int> diameter(Node* root){   // O(n)
    if(root == NULL){
        return make_pair(0,0);
    }
    
    // (Diameter,Height)
    pair<int,int> leftInfo = diameter(root->left);
    pair<int,int> rightInfo = diameter(root->right);

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHt = max(leftInfo.second,rightInfo.second) + 1;
    
    return make_pair(finalDiam,finalHt);
}

int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(tree);  
    
    pair<int,int> ans = diameter(root);
    cout << "Diameter of Tree = " << ans.first << endl;

    return 0;
}