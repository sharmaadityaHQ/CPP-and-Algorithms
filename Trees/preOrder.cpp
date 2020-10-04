// https://www.hackerrank.com/challenges/tree-preorder-traversal/problem

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int node_data) {
            data = node_data;
            left = NULL;
            right = NULL;
        }
};

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}