// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* t = head2;
    while(head1 != NULL) {
        head2 = t;
        while(head2 != NULL) {
            if(head1 == head2) {
                return head1->data;
            }
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    return 0;
}