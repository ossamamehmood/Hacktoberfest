# python3 program to Implement a stack
# using singly linked list

class Node:

	# Class to create nodes of linked list
	# constructor initializes node automatically
	def __init__(self, data):
		self.data = data
		self.next = None


class Stack:

	# head is default NULL
	def __init__(self):
		self.head = None

	# Checks if stack is empty
	def isempty(self):
		if self.head == None:
			return True
		else:
			return False

	# Method to add data to the stack
	# adds to the start of the stack
	def push(self, data):

		if self.head == None:
			self.head = Node(data)

		else:
			newnode = Node(data)
			newnode.next = self.head
			self.head = newnode

	# Remove element that is the current head (start of the stack)
	def pop(self):

		if self.isempty():
			return None

		else:
			# Removes the head node and makes
			# the preceding one the new head
			poppednode = self.head
			self.head = self.head.next
			poppednode.next = None
			return poppednode.data

	# Returns the head node data
	def peek(self):

		if self.isempty():
			return None

		else:
			return self.head.data

	# Prints out the stack
	def display(self):

		iternode = self.head
		if self.isempty():
			print("Stack Underflow")

		else:

			while(iternode != None):

				print(iternode.data, end = "")
				iternode = iternode.next
				if(iternode != None):
					print(" -> ", end = "")
			return


# Driver code
if __name__ == "__main__":
MyStack = Stack()

MyStack.push(11)
MyStack.push(22)
MyStack.push(33)
MyStack.push(44)

# Display stack elements
MyStack.display()

# Print top element of stack
print("\nTop element is ", MyStack.peek())

# Delete top elements of stack
MyStack.pop()
MyStack.pop()

# Display stack elements
MyStack.display()

# Print top element of stack
print("\nTop element is ", MyStack.peek())

# This code is contributed by Mathew George
