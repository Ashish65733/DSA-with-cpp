#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

void topView(Node* root){
    queue<pair<Node*,int>> Q;   // (root,HD)
    map<int,int> m; // (HD,root->data)

    Q.push(make_pair(root,0));

    while(!Q.empty()){
        pair<Node*,int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(!m.count(currHD)){
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            Q.push(make_pair(currNode->left,currHD-1));
        }
        if(currNode->right != NULL){
            Q.push(make_pair(currNode->right,currHD+1));
        }
    }
    for(auto it : m){
        cout << it.second << " ";
    }
    cout << endl;
}


int main(){
    vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(tree);  
    
    topView(root);

    return 0;
}