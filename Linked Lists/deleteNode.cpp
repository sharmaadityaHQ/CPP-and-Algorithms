// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if(position != 0) {
        SinglyLinkedListNode* t = head;
        for(int i = 0; i < position - 1; i++) {
            head = head->next;
        }
        head->next = head->next->next;
        return t;
    }
    head = head->next;
    return head;
}