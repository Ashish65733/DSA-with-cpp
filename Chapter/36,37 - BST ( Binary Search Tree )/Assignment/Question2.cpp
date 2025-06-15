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

int minDiff(Node* root, int K) {
    int closest = root->val;

    while (root != NULL) {
        if (abs(K - root->val) < abs(K - closest)) {
            closest = root->val;
        }
        if (K < root->val)
            root = root->left;
        else if (K > root->val)
            root = root->right;
        else
            break;  // Exact match
    }

    return closest;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int k = 12;
    cout << "Closest Key = " << minDiff(root,k) << endl;

    return 0;
}