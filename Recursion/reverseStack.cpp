// Reverse a stack using recursion

// Identify base condition, make input smaller and design the function (hypothesis)

void insert(stack<int> &s, int value) {
    if(s.size() == 0) {
        s.push(value);
        return;
    }

    int temp = s.top();
    s.pop();
    insert(s, value);
    s.push(temp);
}

void reverse(stack<int> &s) {
    if(s.size() == 1) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
}