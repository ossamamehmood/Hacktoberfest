# Day 4

### Question 1:

Given a string s containing just the characters '(', ')', '{', '}', '[' 
and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

### Thought process:

- Create a dict with the closing parantheses as the keys and its opening 
as the values
- Create a stack and push if its an opening para. or if the stack is empty
- If the next para. is the closing of the para. in the stack, pop the 
opening out of the stack else return false
- If all the para. in the given string is over, and if the length of the 
stack is zero, return true else return false

### Question 2:

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by 
splicing together the nodes of the first two lists.

Return the head of the merged linked list.

### Thought process:

- While both the list has elements
	- Compare the first node element in each list
	- Add the smallest to the new list node and take head of that list 
to its next element
- If any list becomes empty before the other
	- Make next node of the new list the non-empty list

