// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    else
    {
        SinglyLinkedListNode* current = head;
        while(current->next != NULL)
        {
            if(current->data != current->next->data)
                current=current->next;
            else
            {
                current->next=current->next->next;
            }
        }
        return head;
    }
}