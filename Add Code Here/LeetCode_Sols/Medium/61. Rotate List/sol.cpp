#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head || !head->next)
            return head;

        int n = 1;
        ListNode *temp = head;
        while (temp->next)
        {
            n++;
            temp = temp->next;
        }

        temp->next = head;

        k = k % n;
        k = n - k;
        while (k-- > 0)
        {
            temp = temp->next;
        }

        head = temp->next;

        temp->next = nullptr;

        return head;
    }
};

int main()
{

    // call the fn here

    return 0;
}