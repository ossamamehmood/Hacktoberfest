# DAY 5

### Question 1:

Given a sorted array of distinct integers and a target value, return the 
index if the target is found. If not, return the index where it would be 
if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

### Thought process:

- If last element of array greater than target, return len(array)
- Else use binary search on the given list
- If found target, return index
- Else return the index of the last midterm
