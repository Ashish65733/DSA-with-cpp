#include<iostream>
#include<climits>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

static int count = 0;
static int result = -1;
void inorder(Node* root,int k){
    if(root == NULL){
        return;
    }

    inorder(root->left,k);
    count++;
    if(count == k){
        result = root->val;
        return;
    }
    inorder(root->right,k);
}
int kthSmallest(Node* root, int k) {
    inorder(root,k);
    return result;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int k = 3;
    cout << "Closest Key = " << kthSmallest(root,k) << endl;

    return 0;
}