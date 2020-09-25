// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* t = head;
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    head = t;
    int index = count - positionFromTail;
    count = 0;
    while(head != NULL) {
        count++;
        if(index == count) {
            return head->data;
        }
        head = head->next;
    }
    return 0;
}