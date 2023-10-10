"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def findLinkedListLength(head):
    count = 0  # Initialize a count variable to 0
    current = head  # Start from the head of the linked list

    while current is not None:
        count += 1  # Increment count for each node
        current = current.next  # Move to the next node

    return count

# Example usage:
# Create a linked list
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

# Find the length of the linked list
length = findLinkedListLength(head)
print("Length of the linked list:", length)
