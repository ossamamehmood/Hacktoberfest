#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode* node) {
        int count = 0;
        while (node) {
            count++;
            node = node->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (getLength(head) < k) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode;

        int count = 0;
        while (current != nullptr && count < k) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }
        if (nextNode != nullptr) {
            head->next = reverseKGroup(nextNode, k);
        }
        return prev;
    }
};

void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;

    Solution solution;
    ListNode* newHead = solution.reverseKGroup(head, k);

    printLinkedList(newHead);

    return 0;
}
