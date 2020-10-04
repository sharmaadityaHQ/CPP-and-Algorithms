// https://www.hackerrank.com/challenges/tree-inorder-traversal/problem

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

void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}