// https://www.hackerrank.com/challenges/tree-postorder-traversal/problem

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

void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}