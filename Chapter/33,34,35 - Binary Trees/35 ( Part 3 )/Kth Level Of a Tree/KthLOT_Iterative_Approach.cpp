#include<iostream>
#include<climits>
#include<queue>
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

void kthLevel(Node* root,int k){    // O(n) --> no. of nodes in a tree
    if(root == NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    int level = 1;

    while(!Q.empty()){
        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL){
            level++;        // NULL == Next line == Level+1
            // cout << endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);   // to track next line
        }else{
            if(level == k)              // Added condition hear to print nodes when level = k
                cout << curr->data << " ";

            if(curr->left != NULL){
                Q.push(curr->left);
            }

            if(curr->right != NULL){
                Q.push(curr->right);
            }
        }
    }
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    kthLevel(root,3);

    return 0;
}