#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return getStartingNode(head, slow);
            }
        }

        return NULL;
    }

private:
    ListNode *getStartingNode(ListNode *head, ListNode *meetingPoint)
    {
        ListNode *slow = head;
        while (slow != meetingPoint)
        {
            slow = slow->next;
            meetingPoint = meetingPoint->next;
        }
        return slow;
    }
};

int main()
{

    // call the fn here

    return 0;
}