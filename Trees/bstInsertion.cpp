// https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

// Time Complexity - O(n) for skewed tree 

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

Node* insert(Node* root, int data) {
    if(!root) {
        return new Node(data);
    }
    if(data > root->data) {
        root->right = insert(root->right, data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}