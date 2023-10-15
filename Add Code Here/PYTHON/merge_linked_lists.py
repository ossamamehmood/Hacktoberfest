"""
Time Complexity: O(m+n), where m and n are lengths of linked lists
Space Complexity: O(1)
"""

class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def mergeTwoLists(l1, l2):
    dummy = ListNode()  # Create a dummy node as the head of the merged list
    current = dummy  # Initialize a current pointer

    # Traverse both input lists
    while l1 is not None and l2 is not None:
        if l1.value < l2.value:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next

    # If one of the lists is not fully traversed, append the remaining part
    if l1 is not None:
        current.next = l1
    if l2 is not None:
        current.next = l2

    return dummy.next  # Return the merged list, starting from the actual head

# Helper function to print a linked list
def printLinkedList(head):
    current = head
    while current is not None:
        print(current.value, end=" -> ")
        current = current.next
    print("None")

# Example usage:
# Create two sorted linked lists
list1 = ListNode(1, ListNode(3, ListNode(5)))
list2 = ListNode(2, ListNode(4, ListNode(6)))

# Merge the two lists and print the result
merged_list = mergeTwoLists(list1, list2)
print("Merged Linked List:")
printLinkedList(merged_list)
