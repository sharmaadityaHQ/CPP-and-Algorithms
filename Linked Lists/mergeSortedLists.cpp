// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head, *t;
    if(head1->data <= head2->data) {
        t = head1;
        head = head1;
        head1 = head1->next;
    }
    else {
        t = head2;
        head = head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            head->next = head1;
            head = head->next;
            head1 = head1->next;
        }
        else {
            head->next = head2;
            head = head->next;
            head2 = head2->next;
        }
    }
    while(head1 != NULL) {
        head->next = head1;
        head = head->next;
        head1 = head1->next;
    }
    while(head2 != NULL) {
        head->next = head2;
        head = head->next;
        head2 = head2->next;
    }
    return t;
}