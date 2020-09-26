// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* t = head;
    if(head != NULL) {
        while(head->next != NULL) {
            head = head->next;
        }
        SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
        head->next = temp;
        temp->next = NULL;
        return t;
    }
    else {
        SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
        head = temp;
        temp->next = NULL;
        return head;
    }
}