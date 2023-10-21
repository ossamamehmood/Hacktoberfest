class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        # new_node = Node(value)
        self.head = None
        self.tail = None
        self.length = 0

    def __str__(self):
        temp_node = self.head
        result = ''

        if temp_node is None:
            return '---Empty Linked List---'

        while temp_node is not None:
            result += str(temp_node.value) + ' -> '
            # if temp_node.next is not None:
            # result += ' -> '
            temp_node = temp_node.next
        return result

    def append(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1

    def prepend(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.length += 1

    def insert(self, value, idx):
        
        if idx < 0 or idx > self.length:
            return False

        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            if idx == 0:
                new_node.next = self.head
                self.head = new_node
                self.length += 1

            elif idx == self.length:
                self.tail.next = new_node
                self.tail = new_node

            else:
                curr_node = self.head

                for _ in range(idx - 1):
                    curr_node = curr_node.next
                new_node.next = curr_node.next
                curr_node.next = new_node

        self.length += 1
        return True
    
    def traverse(self):
        current = self.head
        while current is not None:
            print(current.value)
            current = current.next

    def search(self, target):
        current = self.head
        idx = 0
        while current:
            if current.value == target:
                return idx
            idx += 1
            current = current.next
        return -1
    
    def get(self, idx):
        current = self.head
        if idx < -1 or idx > self.length - 1:
            return None
        
        if idx == -1:
            return self.tail

        for i in range(idx):
            current = current.next
        return current
    
    def set_value(self, idx, new_value):
        current = self.get(idx)
        if current:
            current.value = new_value
            return True
        return False
    
    def pop_first(self):
        if self.length == 0:
            return None

        popped_node = self.head

        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            popped_node.next = None
        self.length -= 1
        return popped_node
    
    def pop_last(self):
        if self.length == 0:
            return None

        popped_node = self.head

        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            while popped_node.next is not None:
                previous = popped_node
                popped_node = popped_node.next
            previous.next = None
            self.tail = previous

        self.length -= 1
        return popped_node

    def remove(self, idx):
        if self.length == 0:
            return None
        
        if idx < 0 or idx >= self.length:
            return "Index out of range!"
        
        if idx == 0:
            return self.pop_first()

        elif idx == self.length - 1:
            return self.pop_last()

        else:
            prev_node = self.get(idx - 1)
            popped_node = prev_node.next
            prev_node.next = popped_node.next
            popped_node.next = None
            self.length -= 1
            return popped_node
        
    def delete_all(self):
        self.head = None
        self.tail = None
        self.length = 0

    def reverse(self):
        prev_node = None
        current_node = self.head

        while current_node is not None:
            next_node = current_node.next
            current_node.next = prev_node
            prev_node = current_node
            current_node = next_node
        self.head, self.tail = self.tail, self.head

    def find_middle(self):
        if self.length == 0:
            return None
        
        if self.length == 1:
            return self.head
        
        mid = int(self.length/2)

        current = self.head
        for _ in range(mid):
            current = current.next
        return current

    def remove_duplicates(self):
        if self.head is None:
            return
        node_values = set()  # set to store unique node values
        current_node = self.head
        node_values.add(current_node.value)
        while current_node.next:
            if current_node.next.value in node_values:  # duplicate found
                current_node.next = current_node.next.next
                self.length -= 1
            else:
                node_values.add(current_node.next.value)
                current_node = current_node.next
        self.tail = current_node

    def mergeTwoLists(self, l1, l2):
        prehead = ListNode(-1)
 
        prev = prehead
        while l1 and l2:
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next


linked_list = LinkedList()
print(linked_list)
linked_list.prepend(10)
linked_list.append(20)
linked_list.append(40)
# linked_list.append(34)
linked_list.prepend(1)
linked_list.insert(23456, 4)
print("length", linked_list.length)
# print(linked_list.head.value)
# print(linked_list.head.next)
# print(linked_list.head.next.next)
# print(linked_list.tail)
# print(linked_list.tail.value)
# print(linked_list.traverse())
# print(linked_list.search(20))
print(linked_list)
print(linked_list.find_middle().value)
print(linked_list)
