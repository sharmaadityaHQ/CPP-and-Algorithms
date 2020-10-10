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

// Method 1
// Time Complexity - O(w*n) where w is width of binary tree. In worst case value of w can be O(n).
// Hence, O(n*n)

void findMinMax(Node* node, int* min, int* max, int hd) {
    if(node == NULL) {
        return;
    }
    if(hd < *min) {
        *min = hd;
    }
    if(hd > *max) {
        *max = hd;
    }
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

void printVerticalLine(Node* node, int lineNo, int hd) {
    if(node == NULL) {
        return;
    }
    if(lineNo == hd) {
        cout<<node->data<<" ";
    }
    printVerticalLine(node->left, lineNo, hd - 1);
    printVerticalLine(node->right, lineNo, hd + 1);
}

void verticalOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for(int lineNo = min; lineNo <= max; lineNo++) {
        printVerticalLine(root, lineNo, 0);
    }
}

// Method 2
// Map operations take O(log n) therefore complexity of the below solution is O(nlog n)

void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m) {
    if(root == NULL) {
        return;
    }

    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

void verticalOrder(Node* root) {
    map<int, vector<int>> m;
    map<int, vector<int>>::iterator itr;

    for(itr = m.begin(); itr != m.end(); itr++) {
        for(int i = 0; i < itr->second.size(); i++) {
            cout<<itr->second[i]<<" ";
        }
        cout<<endl;
    }
}