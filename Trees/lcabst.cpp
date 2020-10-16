// lowest common ancestor in binary search tree
// https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree

// To find distance between pairs of nodes in a tree, distance between n1 and n2 can be computed 
// as the distance from the root to n1, plus the distance from root to n2, minus twice the distance
// from the root to their lowest common ancestor

// A node is considered a descendant of itself

// Recursive solution
// Time Complexity - O(h)
// Space Complexity - O(1) if recursive stack space is ignored

Node* lca(Node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > n1 && root->data > n2) {
        return lca(root->left, n1, n2);
    }
    if(root->data < n1 && root->data < n2) {
        return lca(root->right, n1, n2);
    }
    return root;
}

// Iterative solution
// Time Complexity - O(h)
// Space Complexity - O(1)

Node* lca(Node* root, int n1, int n2) {
    if(root == NULL) {
        return;
    }
    while(root != NULL) {
        if(root->data > n1 && root->data > n2) {
            root = root->left;
        }
        else if(root->data < n1 && root->data < n2) {
            root = root->right
        }
        else 
            break;
    }
    return root;
}