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


// Function call happens only once for each node in the tree. For each call of this function
// a maximum of k<=4 operations are performed. Hence, max. of k*n operations lead to O(n). 

void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}