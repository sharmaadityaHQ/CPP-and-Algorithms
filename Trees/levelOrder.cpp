// Level order traversal is breadth first traversal.

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int nodeData) {
            data = nodeData;
            left = NULL;
            right = NULL;
        }
};

// Method 1
// Time Complexity - For skewed tree, 1 + 2 + 3 + .. + n where n is no. of nodes. O(n^2) in worst case.
// Space Complexity - O(n) in worst case for skewed tree printGivenLevel() uses O(n) space for call stack.

// Calculate height of the tree
int height(Node* root) {
    if(root == NULL) {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

void levelOrder(Node* root) {
    int h = height(root);
    for(int i = 0; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

void printGivenLevel(Node *root, int level) {
    if(root == NULL) {
        return;
    }
    if(level == 0) {
        cout<<root->data<<" ";
    }
    else if(level > 0) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// Method 2 (queue)
// Time Complexity - O(n) where n is no. of nodes in the binary tree (each node is visited once)
// Space Complexity - O(n)

void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root->data);
    while(q.empty() == false) {
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();

        if(node->left != NULL) {
            q.push(node->left);
        }

        if(node->right != NULL) {
            q.push(node->right);
        }
    }
}