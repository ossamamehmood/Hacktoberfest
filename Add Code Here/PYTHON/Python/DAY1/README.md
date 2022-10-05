# Day 1

### Question 1:

- Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
- You may assume that each input would have exactly one solution, and you may not use the same element twice.
- You can return the answer in any order.

### Thought process:

- Start from the first element of the list
- If target-element exists as key in a dict, return [index of key from array, index of element from array]
- Else insert element as the key to the dict

### Changes:

- While inserting into the dict, insert index as the value


### Question 2:

- Given a string s consisting of lowercase English letters, return the first letter to appear twice.
- Note: A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
s will contain at least one letter that appears twice.

### Thought process:

- Start from the first character of the string and add it to a dict with its count
- If count gets to 2, return the character
