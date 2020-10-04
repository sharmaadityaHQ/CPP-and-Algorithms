// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* current = head;
    DoublyLinkedListNode* prev = NULL, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}