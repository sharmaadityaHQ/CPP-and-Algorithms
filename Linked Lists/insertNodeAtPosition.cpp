// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;
        
        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* t = head;
    for(int i = 0; i < position - 1; i++) {
        head = head->next;
    }
    temp->next = head->next;
    head->next = temp;
    return t;
}