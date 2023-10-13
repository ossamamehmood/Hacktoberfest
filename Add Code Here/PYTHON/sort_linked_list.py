""" 
Time Complexity: O(nlogn)
Space Complexity: O(logn)
"""

class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def mergeSort(head):
    if head is None or head.next is None:
        return head

    # Split the linked list into two halves
    mid = findMiddle(head)
    left_half = head
    right_half = mid.next
    mid.next = None

    # Recursively sort both halves
    left_half = mergeSort(left_half)
    right_half = mergeSort(right_half)

    # Merge the sorted halves
    sorted_list = merge(left_half, right_half)

    return sorted_list

def findMiddle(head):
    slow = head
    fast = head

    while fast.next is not None and fast.next.next is not None:
        slow = slow.next
        fast = fast.next.next

    return slow

def merge(left, right):
    dummy = ListNode()
    current = dummy

    while left is not None and right is not None:
        if left.value < right.value:
            current.next = left
            left = left.next
        else:
            current.next = right
            right = right.next
        current = current.next

    if left is not None:
        current.next = left
    if right is not None:
        current.next = right

    return dummy.next

# Helper function to print a linked list
def printLinkedList(head):
    current = head
    while current is not None:
        print(current.value, end=" -> ")
        current = current.next
    print("None")

# Example usage:
# Create an unsorted linked list
unsorted_list = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))

# Sort the linked list and print the result
sorted_list = mergeSort(unsorted_list)
print("Sorted Linked List:")
printLinkedList(sorted_list)
