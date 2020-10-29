// sort an array using recursion

// Similarly sort a stack using recursion
// Identify base condition, make input smaller and design the function (hypothesis)

void insert(vector<int> &v, val) {
    if(v.size() == 0 || val >= v[v.size() - 1]) {
        v.push_back(val);
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    insert(v, val);
    v.push_back(temp);
}

void sort(vector<int> &v) {
    if(v.size() == 1) {
        return;
    }

    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v, temp);
}