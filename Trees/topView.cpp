// Time Complexity - O(nlogn) as insertion in map has O(log n) and each node is visited once.

void fillMap(Node* root, int hd, int l, map<int, pair<int, int>> &m) {
    if(root == NULL) {
        return;
    }
    if(m.count(hd) == 0) {
        m[hd] = make_pair(root->data, l);
    }
    else if(m[hd].second > l){
        m[hd] = make_pair(root->data, l);
    }

    fillMap(root->left, hd - 1, l + 1, m);
    fillMap(root->right, hd + 1, l + 1, m);
} 

void topView(Node* root) {
    if(root == NULL) {
        return;
    }
    map<int, pair<int, int>> m;
    fillMap(root, 0 , 0, m);
    for(auto it = m.begin(); it != m.end(); it++) {
        cout<<it->second.first<<" ";
    }
}
