// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem

// Arrow operator
// pointer_name -> variable_name

void printLinkedList(SinglyLinkedListNode* head) {
    while(head != NULL) {
        cout<<head->data<<endl;
        head = head->next;    
    }
}