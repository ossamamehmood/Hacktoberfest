# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: 
Optional[ListNode]) -> Optional[ListNode]:
        
        merge = current = ListNode()
        
        while list1 and list2:
            if list1.val <= list2.val:
                temp = ListNode(list1.val)
                list1 = list1.next
            else:
                temp = ListNode(list2.val)
                list2 = list2.next
            current.next = temp
            current = current.next
        if list1 != None:
            current.next = list1
        if list2 != None:
            current.next = list2
        return merge.next
