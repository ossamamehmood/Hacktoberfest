# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next is None:
            return None

        total = 0
        temp = head
        while temp is not None:
            total += 1
            temp = temp.next
        temp = head
        pos = 0
        if total == n:
            return head.next
        while temp.next is not None:
            pos += 1
            if total - pos == n:
                if n == 1:
                    temp.next = None
                else:
                    temp.next = temp.next.next
                break
            temp = temp.next
        return head

