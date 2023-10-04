class ListNode:
    def __init__(self, val) -> None:
        self.data = val
        self.next = None


class LinkedList:
    def __init__(self, val) -> None:
        self.head = ListNode(val=val)

    def insertAtHead(self, val):
        new_node = ListNode(val=val)

        new_node.next = self.head
        self.head = new_node

    def insertAtTail(self, val):
        temp = self.head
        while temp.next:
            temp = temp.next

        new_node = ListNode(val=val)
        temp.next = new_node

    def lengthLL(self):
        ctr = 0
        temp = self.head

        while temp:
            ctr += 1
            temp = temp.next

        return ctr

    def getMiddle(self):
        slow = self.head
        fast = self.head.next

        while slow and fast:
            slow = slow.next
            fast = fast.next

            if fast:
                fast = fast.next

        return slow

    def printLL(self):
        temp = self.head

        while temp:
            print(temp.data, end="")
            if temp.next:
                print('-->', end="")
            temp = temp.next
        print()
