// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem

void reversePrint(SinglyLinkedListNode* head) {
    vector<int> temp;
    while(head != NULL) {
        temp.insert(temp.begin(), head->data);
        head = head->next;
    }
    for(int i = 0; i < temp.size(); i++) {
        cout<<temp[i]<<endl;
    }
}