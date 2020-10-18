// Stacks follow LIFO(Last In First Out) where element is added on top and deleted from top

#include<bits/stdc++.h>
using namespace std;

void showstack(stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    showstack(s);
}

// 30 20 10