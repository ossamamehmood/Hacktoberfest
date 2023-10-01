struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* current = head;
    int count = 0;

    // Count the number of nodes in the current group
    while (current && count < k) {
        current = current->next;
        count++;
    }

    if (count == k) {
        // Reverse the current group
        ListNode* prev = nullptr;
        current = head;
        for (int i = 0; i < k; i++) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        // Recursively reverse the next group
        head->next = reverseKGroup(current, k);

        return prev;
    }

    return head;
}
