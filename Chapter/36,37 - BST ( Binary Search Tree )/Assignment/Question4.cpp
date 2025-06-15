#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Leetcode - 230
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

void inorder(Node* root,vector<int>& vec) {
    if (root == NULL) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

bool twoSumBSTs(Node* root1, Node* root2, int target) {
    vector<int> vec1, vec2;
    inorder(root1, vec1);
    inorder(root2, vec2);

    int i = 0, j = vec2.size() - 1;

    while (i < vec1.size() && j >= 0) {
        int sum = vec1[i] + vec2[j];
        if (sum == target) {
            return true;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    cout << twoSumBSTs(root1,root2,16) << endl;

    return 0;
}