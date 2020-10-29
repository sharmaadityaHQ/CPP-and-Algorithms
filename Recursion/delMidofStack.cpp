// Delete middle element of stack using recursion

// Identify base condition, make input smaller and design the function (hypothesis)

void solve(stack<int> &s, int k) {
    if(k == 1) {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(temp);
}

stack<int> midDel(stack<int> s, int size) {
    if(s.size() == 0) {
        return s;
    }
    int k = size / 2 + 1;
    solve(s, k);
    return s;
}