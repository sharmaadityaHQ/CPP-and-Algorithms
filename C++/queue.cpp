// Queues operate in FIFO (first in first out). Elements are inserted at the end
// and are deleted from the front.

// push() adds element at the end and pop() deletes the first element of 
// the queue

#include<bits/stdc++.h>
using namespace std;

void showq(queue<int> gq) {
    queue<int> g = gq;
    while(!g.empty()) {
        cout<<" "<<g.front();
        g.pop();
    }
}

int main() {
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
    showq(gquiz);
}

// 10 20 30