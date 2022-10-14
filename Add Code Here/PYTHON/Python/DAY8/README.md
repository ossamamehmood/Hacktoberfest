# Day 8

### Question 1:

A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, it reads 
the same forward and backward. Alphanumeric characters include letters and 
numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

### Thought process:

- Create a new string with only the letters and digits
- Use slice method to check the string with its reverse
- Return true if they are same else false
