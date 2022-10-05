class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None


class SLL:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next

    # insert Element in SLL
    def insertSLL(self, value, location):
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
            self.tail = newNode
        else:
            if location == 0:
                newNode.next = self.head
                self.head = newNode
            elif location == -1:
                newNode.next = None
                self.tail.next = newNode
                self.tail = newNode
            else:
                tempNode = self.head
                index = 0
                while index < location - 1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                tempNode.next = newNode
                newNode.next = nextNode
                if tempNode == self.tail:
                    self.tail = newNode

    # Traverse in SLL
    def traverseSLL(self):
        if self.head is None:
            print("SLL is Empty")
        else:
            node = self.head
            while node is not None:
                print(node.value)
                node = node.next

    # Searching a value in SLL
    def searchSLL(self, nodeValue):
        if self.head is None:
            print("SLL is Empty")
            return 0
        else:
            node = self.head
            while node is not None:
                if node.value == nodeValue:
                    return node.value
                node = node.next
            return "Value does not exist"

    # Delete one link in SLL
    def deleteNode(self, location):
        if self.head is None:
            print("SLL is Empty")
        else:
            if location == 0:
                if self.head == self.tail:
                    self.head = None
                    self.tail = None
                else:
                    self.head = self.head.next
            elif location == -1:
                if self.head == self.tail:
                    self.head = None
                    self.tail = None
                else:
                    node = self.head
                    while node is not None:
                        if node.next == self.tail:
                            break
                        node = node.next
                    node.next = None
                    self.tail = node
            else:
                tempNode = self.head
                index = 0
                while index < location - 1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                tempNode.next = nextNode.next

    # Deleting entire SLL
    def delEntireSLL(self):
        if self.head is None:
            print("SLL is Empty")
        else:
            self.head = None
            self.tail = None
