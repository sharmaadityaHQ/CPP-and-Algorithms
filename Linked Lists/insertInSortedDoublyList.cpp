// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode* prev;
        DoublyLinkedListNode* next;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* t = head;
    if(head->data >= data) {
        temp->next = head;
        head->prev = temp;
        t = temp;
        return t;
    }
    while(head != NULL) {
        if(head->data >= data) {
            head->prev->next = temp;
            temp->prev = head->prev;
            head->prev = temp;
            temp->next = head;
            return t;
        }
        if(head->next == NULL) {
            head->next = temp;
            temp->prev = head;
            return t;
        }
        head = head->next;
    }
    return t;
}