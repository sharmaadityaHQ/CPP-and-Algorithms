// Searching for an element in binary search tree is similar to binary search

// Time Complexity - O(n), skewed binary tree

Node* search(Node* root, int key) {
    if(root == NULL || root->data == key) {
        return root;
    }
    if(root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}