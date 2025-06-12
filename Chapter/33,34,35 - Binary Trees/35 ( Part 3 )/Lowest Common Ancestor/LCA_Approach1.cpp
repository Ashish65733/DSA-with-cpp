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

bool rootToNodePath(Node* root,int n,vector<int> &path){
    if(root == NULL){
        return false;
    } 

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    bool isLeft = rootToNodePath(root->left,n,path);
    bool isRight = rootToNodePath(root->right,n,path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root,int n1,int n2){  // TC = O(n), SC = O(n)
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root,n1,path1);
    rootToNodePath(root,n2,path2);

    // for(int i=0; i<path1.size(); i++){
    //     cout << path1[i] << " ";
    // }
    // cout << endl;
    // for(int i=0; i<path2.size(); i++){
    //     cout << path2[i] << " ";
    // }
    // cout << endl;

    for(int i=path1.size()-1,j=path2.size()-1; i>=0,j>=0; i--,j--){
        if(path1[i] == path2[i]){
            return path1[i];
        }
    }
    return -1;
}

int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(tree);  
    
    cout << "Lowest Common Ancestor = " << LCA(root,4,6) << endl;

    return 0;
}