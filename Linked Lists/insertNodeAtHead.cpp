// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    temp->next = llist;
    return temp;
}