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

Node* LCA(Node* root,int n1,int n2){  // TC = O(n), SC = O(1)
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA(root->left,n1,n2);
    Node* rightLCA = LCA(root->right,n1,n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dist(Node* root,int n){ //O(n)
    if(root == NULL){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int leftdist = dist(root->left,n);
    if(leftdist != -1){
        return leftdist + 1;
    }

    int rightdist = dist(root->right,n);
    if(rightdist != -1){
        return rightdist + 1;
    }

    return -1;
}

int minDist(Node* root,int n1,int n2){  // O(n)
    Node* lcaNode = LCA(root,n1,n2);

    int dist1 = dist(lcaNode,n1);
    int dist2 = dist(lcaNode,n2);

    return dist1+dist2;
}


int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(tree);  
    
    int n1 = 4, n2 = 6;
    cout << "Minimum distance between Nodes " << n1 << " & " << n2 << " = " << minDist(root,n1,n2) << endl;

    return 0;
}