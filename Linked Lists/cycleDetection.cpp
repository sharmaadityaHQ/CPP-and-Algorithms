// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem

// Floyd's cycle finding algorithm

bool has_cycle(SinglyLinkedListNode* head) {
    if(head == NULL) {
        return 0;
    }
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return 1;
        }
    }
    return 0;
}

// Hashing O(n)

bool detectLoop(SinglyLinkedListNode* h) {
    unordered_set<SinglyLinkedListNode*> s;
    while(h != NULL) {
        if(s.find(h) != s.end()) {
            return 1;
        }
        s.insert(h);
        h = h->next;
    }
    return 0;
}